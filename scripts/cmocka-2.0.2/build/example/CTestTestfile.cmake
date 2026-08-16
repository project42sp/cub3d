# CMake generated Testfile for 
# Source directory: /home/solractys/Downloads/cmocka-2.0.2/example
# Build directory: /home/solractys/Downloads/cmocka-2.0.2/build/example
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(calculator_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/calculator_test")
set_tests_properties(calculator_test PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;14;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(simple_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/simple_test")
set_tests_properties(simple_test PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;23;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(assert_macro_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/assert_macro_test")
set_tests_properties(assert_macro_test PROPERTIES  WILL_FAIL "1" _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;31;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(assert_module_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/assert_module_test")
set_tests_properties(assert_module_test PROPERTIES  WILL_FAIL "1" _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;43;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(set_parameters_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/set_parameters_test")
set_tests_properties(set_parameters_test PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;55;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(set_errno_tests "/home/solractys/Downloads/cmocka-2.0.2/build/example/set_errno_tests")
set_tests_properties(set_errno_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;63;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(output_override_test "/home/solractys/Downloads/cmocka-2.0.2/build/example/output_override_test")
set_tests_properties(output_override_test PROPERTIES  PASS_REGULAR_EXPRESSION "---- UNIT TEST OUTPUT ----[==========] tests: Running 4 test(s).[ RUN      ] true_test_succeeds.*[==========] tests: 4 test(s) run.[  PASSED  ] 3 test(s).[  FAILED  ] tests: 1 test(s), listed below:[  FAILED  ] false_test_fails 1 FAILED TEST(S)---- UNIT TEST OUTPUT ----" WILL_FAIL "1" _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;71;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(expect_check_data_example "/home/solractys/Downloads/cmocka-2.0.2/build/example/expect_check_data_example")
set_tests_properties(expect_check_data_example PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;101;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
add_test(expect_check_data_advanced "/home/solractys/Downloads/cmocka-2.0.2/build/example/expect_check_data_advanced")
set_tests_properties(expect_check_data_advanced PROPERTIES  _BACKTRACE_TRIPLES "/home/solractys/Downloads/cmocka-2.0.2/cmake/Modules/AddCMockaTest.cmake;118;add_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;109;add_cmocka_test;/home/solractys/Downloads/cmocka-2.0.2/example/CMakeLists.txt;0;")
subdirs("mock")
