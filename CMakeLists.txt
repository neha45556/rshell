CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

include_directories(
	${PROJECT_SOURCE_DIR}/unit_tests
	${PROJECT_SOURCE_DIR}/src
)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/Input.cpp
	${PROJECT_SOURCE_DIR}/src/command.cpp
	${PROJECT_SOURCE_DIR}/src/execute.cpp
	${PROJECT_SOURCE_DIR}/src/connector.cpp
	${PROJECT_SOURCE_DIR}/src/semicolon.cpp
	${PROJECT_SOURCE_DIR}/src/and.cpp
	${PROJECT_SOURCE_DIR}/src/or.cpp
)

ADD_EXECUTABLE(test
        ${PROJECT_SOURCE_DIR}/unit_tests/unit_tests.cpp
        ${PROJECT_SOURCE_DIR}/src/Input.cpp
        ${PROJECT_SOURCE_DIR}/src/command.cpp
        ${PROJECT_SOURCE_DIR}/src/execute.cpp
        ${PROJECT_SOURCE_DIR}/src/connector.cpp
        ${PROJECT_SOURCE_DIR}/src/semicolon.cpp
        ${PROJECT_SOURCE_DIR}/src/and.cpp
        ${PROJECT_SOURCE_DIR}/src/or.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
