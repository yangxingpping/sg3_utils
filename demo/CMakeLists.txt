cmake_minimum_required(VERSION 2.8)

#set(CMAKE_BUILD_TYPE "Debug")

FILE(GLOB_RECURSE MY_HEADERS "./*.h")
source_group("Headers" FILES ${MY_HEADERS})

include_directories(../include)



IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(special_src list_device_win32.c)
link_libraries(SetupAPI)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

AUX_SOURCE_DIRECTORY(../get_opt_log get_opt_src)

PROJECT(demo)

ADD_EXECUTABLE(demo  main.c ${get_opt_src} ${special_src})

target_link_libraries(demo sg3_utils)
