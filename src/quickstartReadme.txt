i keep forgetting how to do this:

after sourcing the install/setup.bash (which should be automatic)

run the intel realsense camera node first:

to run my service:

ros2 run my_package my_node: (you can inspect each package's setup.py to see what the executable is called)
ros2 run robopoint_llm query

then call the service with `ros2 service call`


whatever you edit in src/ pythonfile will STILL need to be rebuilt
cd ~/interbotix_ws
then run
colcon build --packages-select PACKAGE NAME
