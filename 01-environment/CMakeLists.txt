add_executable(01_environment 01_environment.cpp)
target_link_libraries(01_environment PRIVATE common_lib)
target_include_directories(01_environment PRIVATE "${CMAKE_BINARY_DIR}")
target_compile_options(01_environment PRIVATE -Wall -Wextra -pedantic -Werror)

add_executable(test_01_environment test_01_environment.cpp)
target_link_libraries(test_01_environment common_lib)
target_link_libraries(test_01_environment gtest_main)
target_compile_options(test_01_environment PRIVATE -Wall -Wextra -pedantic -Werror)

set_target_properties(01_environment test_01_environment PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)

include(GoogleTest)

install(TARGETS 01_environment RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_DESCRIPTION "Otus c++ learning")
set(CPACK_PACKAGE_CONTACT maratsr@ya.ru)
include(CPack)

