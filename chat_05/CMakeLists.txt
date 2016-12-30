cmake_minimum_required (VERSION 1.0)
project(springsnail)

aux_source_directory(. DIR_SRCS)

add_executable(springsnail ${DIR_SRCS})
