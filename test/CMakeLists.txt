# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(cmake_initTests LANGUAGES CXX)

# ---- Tests ----

add_executable(cmake_init_test source/cmake_init_test.cpp)
target_link_libraries(cmake_init_test PRIVATE cmake_init_lib)
target_compile_features(cmake_init_test PRIVATE cxx_std_17)

add_test(NAME cmake_init_test COMMAND cmake_init_test)

# ---- End-of-file commands ----

add_folders(Test)
