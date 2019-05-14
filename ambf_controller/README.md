
## Description:
The AMBF Controller is a C++ client that controls the simulated objects in the
AMBF Simulator. It is an alternative to the python client described [here](../README.md).
The Raven2 control is imeplemented and well tested in the AMBF Controller. Robot 
kinematics is implemented in the module so both cartesian and joint space commands 
for Raven2 is supported.

## Usage:
### Building:
The AMBF Controller module supports Linux OS only. If a Linux machine is used, 
it is automatically built when compiling the AMBF framework. See instructions 
[here](../README.md).

### Setting up for Raven2 Demo:
Currently, a Raven2 test module is developed in the AMBF Controller. To launch 
it correctly, change the settings in [launch.yaml](../ambf_models/descriptions/launch.yaml) by:
1. Uncomment (line 3):          world config: ./world/raven_world.yaml
2. Comment out (line 2):        world config: ./world/world.yaml

### Running the AMBF Controller:
Having succesfully completed the steps to build, one can run the AMBF Simulator 
using the following command:

```
cd ~/ambf/bin/<os>
./ambf_simulator -l 3
```
Then on a second terminal, run the AMBF Controller using the following command:

```
cd ~/ambf/bin/<os>
./ambf_controller
```

Or there is an automatic compile and run script using the following command on 
a terminal:

```
./CompileAndRunScript.sh
```