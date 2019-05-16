#ifndef RAVE_KINE
#define RAVE_KINE
#include "Definitions.h"
/**
 * @brief      change raw joint values to dh convension
 *
 * @param[in]  joint    The joint   (length 7)
 * @param      dhvalue  The dhvalue (length 6)
 * @param[in]  arm      The arm
 *
 * @return     success
 */
class kinematics{
public:
		bool joint_to_dhvalue(vector<float> joint, vector<float>& dhvalue, int arm)
	{
		bool success = false;
		if(arm < 0 || arm >= reference::arms || joint.size() != reference::children_size)
		{
			ROS_ERROR("Invalid input to function joint to dhvalue.");
			return success;
		}

		for(int i=0; i<reference::children_size-1; i++)
		{
			if(i != 2)
			{
				if(i == 5)
				{
					if(arm == 0)
						dhvalue[i] =  (joint[i] - joint[i+1]);  // red(left) - black(right)
					else
						dhvalue[i] = -(joint[i] - joint[i+1]);  // black(left) - red(right)
				}
				else
					dhvalue[i] = joint[i];

				while(dhvalue[i] > M_PI)   dhvalue[i] -= 2*M_PI;
				while(dhvalue[i] < -M_PI)  dhvalue[i] += 2*M_PI;
			}
			else
				dhvalue[i] = joint[i];
		}

		success = true;
		return success;
	}




	/**
	 * @brief      change dh convension to raw joint values
	 *
	 * @param[in]  dhvalue  The dhvalue (length 6)
	 * @param      joint    The joint   (length 7)
	 * @param[in]  gangle   The gangle
	 * @param[in]  arm      The arm
	 *
	 * @return     limited  The joint values were saturated
	 */
	bool dhvalue_to_joint(vector<float> dhvalue, vector<float>& joint, float gangle, int arm)
	{
		bool limited;

		// set desired joint positions
		for(int i=0; i<reference::children_size-1; i++)
		{
			if(i != 2)
			{
				if(i == 5)
				{
					if(arm == 0)
					{
						joint[i+1] =  (-dhvalue[i] + gangle) / 2;  // black (right)
						joint[i] =    (dhvalue[i] + gangle) / 2;  // red (left)
					}
					else
					{
						joint[i] =    (-dhvalue[i] + gangle) / 2; // red (right)
						joint[i+1] =  (dhvalue[i] + gangle) / 2;  // black (left)
					}

				}
				else
					joint[i] = dhvalue[i];

				while(joint[i] > M_PI)   joint[i] -= 2*M_PI;
				while(joint[i] < -M_PI)  joint[i] += 2*M_PI;
			}
			else
				joint[i] = dhvalue[i];
		}

		// check joint limits for saturating
		apply_joint_limits(joint, limited);

		return limited;
	}



	/**
	 * @brief      Raven forward kinematics calculation
	 *
	 * @param[in]  arm        The arm
	 * @param[in]  input_jp   The input joitn position
	 * @param      output_cp  The output cartesian end-effector pose
	 *
	 * @return     success
	 */
	bool fwd_kinematics(int arm, vector<float> input_jp, tf::Transform& output_cp)
	{
		bool success = false;

		vector<float> dh_alpha(6);
		vector<float> dh_theta(6);
		vector<float> dh_a(6);
		vector<float> dh_d(6);

		// convert the joint angles to DH theta convention
		vector<float> jp_dh(6);

		if(!joint_to_dhvalue(input_jp, jp_dh, arm))
		{
			ROS_ERROR("Something went wrong in joint to dhvalue conversion.");
			return success;
		}

		for(int i=0; i<reference::children_size-1; i++)
		{
			if(i == 2)
			{
				dh_d[i] = jp_dh[i];
				dh_theta[i] = reference::raven_dh_theta[arm][i];
			}
			else
			{
				dh_d[i] = reference::raven_dh_d[arm][i];
				dh_theta[i] = jp_dh[i];
			}

			dh_alpha[i] = reference::raven_dh_alpha[arm][i];
			dh_a[i] = reference::raven_dh_a[arm][i];
		}

		// computes forward kinematics
		output_cp = fwd_trans(0, 6, dh_alpha, dh_theta, dh_a, dh_d);

		success = true;
		return success;
	}



	/**
	 * @brief      computes the accumulative multiplication of homogeneous matrices
	 *             under the dh convension from frame a to frame b.
	 *
	 * @param[in]  a         start frame
	 * @param[in]  b         goal frame
	 * @param      dh_alpha  The dh parameter alpha
	 * @param      dh_theta  The dh parameter theta
	 * @param      dh_a      The dh parameter a
	 * @param      dh_d      The dh parameter d
	 *
	 * @return     The resultant transformation matrix
	 */
	tf::Transform fwd_trans(int a, int b, vector<float> dh_alpha, vector<float> dh_theta, vector<float> dh_a, vector<float> dh_d)
	{
		if ((b <= a) || b == 0)
			ROS_ERROR("Invalid start/end indices.");

		double xx = cos(dh_theta[a]),
		       xy = -sin(dh_theta[a]),
		       xz = 0;

		double yx = sin(dh_theta[a]) * cos(dh_alpha[a]),
		       yy = cos(dh_theta[a]) * cos(dh_alpha[a]),
		       yz = -sin(dh_alpha[a]);

		double zx = sin(dh_theta[a]) * sin(dh_alpha[a]),
		       zy = cos(dh_theta[a]) * sin(dh_alpha[a]),
		       zz = cos(dh_alpha[a]);

		double px = dh_a[a];
		double py = -sin(dh_alpha[a]) * dh_d[a];
		double pz = cos(dh_alpha[a]) * dh_d[a];

		tf::Transform xf;
		xf.setBasis(tf::Matrix3x3(xx, xy, xz, yx, yy, yz, zx, zy, zz));
		xf.setOrigin(tf::Vector3(px, py, pz));

		// recursively find transforms for following links
		if (b > a + 1)
			xf *= fwd_trans(a + 1, b, dh_alpha, dh_theta, dh_a, dh_d);

		return xf;
	}


	/**
	 * @brief      Raven inverse kinematics calculation
	 *
	 * @return     success
	 */
	bool inv_kinematics(vector<float>& I, int arm, tf::Transform& input_cp, float input_gangle, vector<float>& output_jp)
	{
		bool success = false;

		tf::Transform xf = input_cp;

		vector<vector<float>> iksol(reference::raven_iksols, vector<float>(reference::children_size-1));
		vector<bool>ikcheck(reference::raven_iksols);

		vector<float> dh_alpha(6);
		vector<float> dh_theta(6);
		vector<float> dh_a(6);
		vector<float> dh_d(6);
		for(int i=0; i<reference::children_size-1;i++)
		{
			dh_alpha[i] = reference::raven_dh_alpha[arm][i];
			dh_theta[i] = reference::raven_dh_theta[arm][i];
			dh_a[i] = reference::raven_dh_a[arm][i];
			dh_d[i] = reference::raven_dh_d[arm][i];
		}
		for (int i = 0; i < reference::raven_iksols; i++)
		{
			iksol[i] = reference::zero_joints;
			ikcheck[i] = true;
		}
		//  Step 1, Compute P5
		tf::Transform T60 = xf.inverse();
		tf::Vector3 p6rcm = T60.getOrigin();
		tf::Vector3 p05[8];

		p6rcm[2] = 0;  // take projection onto x-y plane
		for (int i = 0; i < 2; i++)
		{
			tf::Vector3 p65 = (-1 + 2 * i) * reference::raven_ikin_param [5] * p6rcm.normalize();
			p05[4 * i] = p05[4 * i + 1] = p05[4 * i + 2] = p05[4 * i + 3] = xf * p65;
		}

		//  Step 2, compute displacement of prismatic joint d3
		for (int i = 0; i < reference::raven_iksols/4; i++)
		{
			float insertion = 0;
			insertion += p05[4 * i].length();

			if (insertion <= reference::raven_ikin_param[5])
			{
			  ROS_ERROR("WARNING: Raven mechanism at RCM singularity (Lw: %f, ins: %f). IK failing.",
			            reference::raven_ikin_param[5], insertion);

			  ikcheck[4 * i + 0] = ikcheck[4 * i + 1] = false;
			  ikcheck[4 * i + 2] = ikcheck[4 * i + 3] = false;
			  success = false;
			  break;
			}
			iksol[4 * i + 0][2] = iksol[4 * i + 1][2] = -reference::raven_ikin_param[4] - insertion;
			iksol[4 * i + 2][2]= iksol[4 * i + 3][2] = -reference::raven_ikin_param[4] + insertion;
		}
		//  Step 3, calculate theta 2
		for (int i = 0; i < reference::raven_iksols; i += 2)  // p05 solutions
		{
			float z0p5 = p05[i][2];

			float cth2 = 0;
			float d = iksol[i][2] + reference::raven_ikin_param[4];
			float cth2_nom = (( z0p5 / d) + reference::raven_ikin_param[1] * reference::raven_ikin_param[3]);
			float cth2_den = (reference::raven_ikin_param[0] * reference::raven_ikin_param[2]);

			cth2 = -cth2_nom / cth2_den;

			// Smooth roundoff errors at +/- 1.
			if (cth2 > 1 && cth2 < 1 + Eps)
			  cth2 = 1;
			else if (cth2 < -1 && cth2 > -1 - Eps)
			  cth2 = -1;

			if (cth2 > 1 || cth2 < -1)
			{
			  ikcheck[i] = ikcheck[i + 1] = false;
			}
			else
			{
			  iksol[i][1] = acos(cth2);
			  iksol[i + 1][1] = -acos(cth2);
			}
		}

		//  Step 4: Compute theta 1
		for (int i = 0; i < reference::raven_iksols; i++)
		{
			if (ikcheck[i] == false) continue;

			float cth2 = cos(iksol[i][1]);
			float sth2 = sin(iksol[i][1]);
			float d = iksol[i][2] + reference::raven_ikin_param[4];
			float BB1 = sth2 * reference::raven_ikin_param[2];
			float BB2 = 0;
			tf::Matrix3x3 Bmx;  // using 3 vector and matrix bullet types for convenience.
			tf::Vector3 xyp05(p05[i]);
			xyp05[2] = 0;

			BB2 = cth2 * reference::raven_ikin_param[1]*reference::raven_ikin_param[2]
			      - reference::raven_ikin_param[0]*reference::raven_ikin_param[3];

			if (arm == 0)
			  Bmx.setValue(BB1, BB2, 0, -BB2, BB1, 0, 0, 0, 1);
			else
			  Bmx.setValue(BB1, BB2, 0,  BB2, -BB1, 0, 0, 0, 1);

			tf::Vector3 scth1 = Bmx.inverse() * xyp05 * (1 / d);
			iksol[i][0] = atan2(scth1[1], scth1[0]);
		}

		//  Step 5: get theta 4, 5, 6
		for (int i = 0; i < reference::raven_iksols; i++)
		{
			if (ikcheck[i] == false) continue;

			// compute T03:
			dh_theta[0] = iksol[i][0];
			dh_theta[1] = iksol[i][1];
			dh_d[2] = iksol[i][2];

			tf::Transform T03 = fwd_trans(0,3, dh_alpha, dh_theta, dh_a, dh_d);
			tf::Transform T36 = T03.inverse() * xf;

			float c5 = -T36.getBasis()[2][2];
			float s5 = (T36.getOrigin()[2] - reference::raven_ikin_param[4]) / reference::raven_ikin_param[5];

			// Compute theta 4:
			float c4, s4;
			if (fabs(c5) > Eps)
			{
				c4 = T36.getOrigin()[0] / (reference::raven_ikin_param[5] * c5);
				s4 = T36.getOrigin()[1] / (reference::raven_ikin_param[5] * c5);
			}
			else
			{
				c4 = T36.getBasis()[0][2] / s5;
				s4 = T36.getBasis()[1][2] / s5;
			}
			iksol[i][3] = atan2(s4, c4);

			// Compute theta 5:
			iksol[i][4] = atan2(s5, c5);

			// Compute theta 6:
			float s6, c6;
			if (fabs(s5) > Eps)
			{
				c6 = T36.getBasis()[2][0] / s5;
				s6 = -T36.getBasis()[2][1] / s5;
			}
			else
			{
				dh_theta[3] = iksol[i][3];
				dh_theta[4] = iksol[i][4];
				tf::Transform T05 = T03 * fwd_trans(3,5, dh_alpha, dh_theta, dh_a, dh_d);
				tf::Transform T56 = T05.inverse() * xf;
				c6 = T56.getBasis()[0][0];
				s6 = T56.getBasis()[2][0];
			}
			iksol[i][5] = atan2(s6, c6);
		}

		vector<float> jp_dh(6); // current joint angles

		if(!joint_to_dhvalue(I, jp_dh, arm))
		{
			ROS_ERROR("Something went wrong in joint to dhvalue conversion.");
			return success;
		}

		int sol_idx;
		float sol_err;

		if(find_best_solution(jp_dh, iksol, ikcheck, sol_idx, sol_err))
		{
			bool limited = dhvalue_to_joint(iksol[sol_idx], output_jp, input_gangle, arm);

			// adjust desired cartesian positions if necessary
			if(limited)
			{
			  fwd_kinematics(arm, output_jp, xf);
			  input_cp = xf;
			}

			success = true;
		}
		else
			ROS_ERROR("Raven IK calculation failed.");

		return success;
	}



	/**
	 * @brief      Apply Raven joint limit constraints.
	 *
	 * @param      joint  The input joint value vector
	 *
	 * @return     success
	 */
	bool apply_joint_limits(vector<float>& joint, bool& changed)
	{
		bool success = false;
		changed = false;

		if(joint.size() != reference::children_size)
		{
			ROS_ERROR("Wrong input vector length to apply joint limit check.");
			return success;
		}

		for(int i=0; i<reference::children_size; i++)
		{
			if(i != 2)
			{
				while(joint[i] >  M_PI)  joint[i] -= 2*M_PI;
				while(joint[i] < -M_PI)  joint[i] += 2*M_PI;
			}

			if(joint[i] < reference::raven_joint_limit[0][i])
			{
				joint[i] = reference::raven_joint_limit[0][i];
				changed = true;
			}
			else if(joint[i] > reference::raven_joint_limit[1][i])
			{
				joint[i] = reference::raven_joint_limit[1][i];
				changed = true;
			}
		}

		success = true;
		return success;
	}





	/**
	 * @brief      Find the IK solution that matches the current pose.
	 *
	 * @param[in]  curr_jp  The curr jp
	 * @param[in]  iksol    The iksol
	 * @param[in]  ikcheck  The ikcheck
	 * @param      sol_idx  The sol index
	 * @param      sol_err  The sol error
	 *
	 * @return     success
	 */
	bool find_best_solution(vector<float> curr_jp, vector<vector<float>> iksol, vector<bool> ikcheck, int& sol_idx, float& sol_err)
	{
		bool success = false;
		float best_err = 1e+10;
		float best_idx = -1;

		for(int i=0;i<reference::raven_iksols;i++)
		{
			float error = 0;
			if(ikcheck[i] == true)
			{
				for(int j=0;j<reference::children_size-1;j++)
				{
					if(j == 2)
						error += 100*pow(iksol[i][j] - curr_jp[j],2);
					else
					{
						float diff = iksol[i][j] - curr_jp[j];
						while(diff >  M_PI) diff -= 2*M_PI;
						while(diff < -M_PI) diff += 2*M_PI;

						error += pow(diff,2);
					}
				}
				if(error < best_err)
				{
					best_err = error;
					best_idx = i;
					success = true;
				}
			}
		}

		sol_err = best_err;
		sol_idx = best_idx;

		return success;
	}
};
#endif
