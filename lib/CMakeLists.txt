cmake_minimum_required(VERSION 2.8)

#set(CMAKE_BUILD_TYPE "Debug")

project(sg3_utils)

FILE(GLOB_RECURSE MY_HEADERS "./*.h")
source_group("Headers" FILES ${MY_HEADERS})

include_directories(../include)

set(common_src sg_cmds_basic.c sg_cmds_basic2.c sg_cmds_extra.c sg_cmds_mmc.c sg_lib_data.c sg_lib.c sg_pt_common.c)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(special_src sg_pt_win32.c)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

set(special_src sg_io_linux.c sg_pt_linux_nvme.c sg_pt_linux.c)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")


ADD_LIBRARY(sg3_utils ${common_src} ${special_src})