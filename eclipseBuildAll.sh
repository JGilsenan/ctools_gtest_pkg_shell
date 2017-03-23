cd ~
cd catkin_ws
catkin build tdd_cpp_examples --catkin-make-args run_tests
cd devel/lib/tdd_cpp_examples
./examples_node_tests
