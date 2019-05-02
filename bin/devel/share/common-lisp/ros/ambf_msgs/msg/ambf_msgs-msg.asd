
(cl:in-package :asdf)

(defsystem "ambf_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ObjectCmd" :depends-on ("_package_ObjectCmd"))
    (:file "_package_ObjectCmd" :depends-on ("_package"))
    (:file "ObjectState" :depends-on ("_package_ObjectState"))
    (:file "_package_ObjectState" :depends-on ("_package"))
    (:file "WorldCmd" :depends-on ("_package_WorldCmd"))
    (:file "_package_WorldCmd" :depends-on ("_package"))
    (:file "WorldState" :depends-on ("_package_WorldState"))
    (:file "_package_WorldState" :depends-on ("_package"))
  ))