cmake_minimum_required(VERSION 2.6)

PROJECT(Base)

AUX_SOURCE_DIRECTORY(./ SRC_LIST1)
AUX_SOURCE_DIRECTORY(./pb/protocol SRC_LIST2)
SET(LIBRARY_OUTPUT_PATH ./)
ADD_DEFINITIONS( -g -W -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL -DAC_HAS_DEBUG -DLINUX_DAEMON)
#编译时添加警告
#ADD_DEFINITIONS( -g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL -DAC_HAS_DEBUG -DLINUX_DAEMON)
INCLUDE_DIRECTORIES(./ ./pb/protocol)
ADD_LIBRARY(base STATIC ${SRC_LIST1} ${SRC_LIST2})
TARGET_LINK_LIBRARIES(base pthread) 
