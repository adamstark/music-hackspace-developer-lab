# =============================================================================
# Unit Testing with CMake + doctest
# =============================================================================
# REQUIREMENTS:
#   - CMake 3.14+
#   - A C++17-capable compiler (GCC, Clang, MSVC)
#   - doctest/doctest.h
#
# QUICKSTART:
#   mkdir build && cd build
#   cmake ..
#   cmake --build . && ctest --output-on-failure
# =============================================================================

cmake_minimum_required(VERSION 3.14)
project(UnitTestingDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================================
# Enable CTest
enable_testing()

# =============================================================================
# STEP 2a — LIST THE CPP FILES YOU WANT TO TEST HERE
#
#   MusicHelpers.h          <- declarations
#   MusicHelpers.cpp        <- implementations   <-- list it here
# =============================================================================

set(SOURCE_FILES
    # --- Add your implementation files below this line ---
    MusicHelpers.cpp
    # SomethingElse.cpp
)

# =============================================================================
# STEP 2b — LIST THE TEST FILES HERE
#
#   test_MusicHelpers.cpp   <- TEST_CASEs for MusicHelpers.hpp  <-- list it here
# =============================================================================
set(TEST_FILES
    main.cpp        # <-- owns DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN; do not touch

    # --- Add your test files below this line ---
    test_MusicHelpers.cpp
    # test_SomethingElse.cpp
)

# =============================================================================
# STEP 3 — Build the test executable and register it with CTest
# =============================================================================
add_executable(run_tests ${SOURCE_FILES} ${TEST_FILES})
add_test(NAME all_tests COMMAND run_tests)
