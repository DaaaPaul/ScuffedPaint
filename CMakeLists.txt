cmake_minimum_required(VERSION 3.30)

project(ScuffedPaint)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

add_executable(ScuffedPaint)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ScuffedPaint)
target_sources(ScuffedPaint PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_include_directories(ScuffedPaint PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/vendor/minifb/include
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/minifb)
target_link_libraries(ScuffedPaint minifb)