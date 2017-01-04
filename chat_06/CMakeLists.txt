cmake_minimum_required (VERSION 1.0)
project(websrv)

aux_source_directory(. DIR_SRCS)

add_executable(websrv ${DIR_SRCS})
