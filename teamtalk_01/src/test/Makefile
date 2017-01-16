#基本
CC=g++
CFLAGS=-Wall -Wno-deprecated -g -std=c++11
LDFALGS= -lbase -lpthread -lprotobuf
RM=rm -rf

#二进制目标
BIN=test

#源文件目录
SrcDir=.
#头文件目录
InDir=. ../base ../base/pb/protocol
#链接库目录
LibDir=../base

SRCS=$(foreach dir,$(SrcDir),$(wildcard $(dir)/*.cpp))
INCS=$(foreach dir,$(InDir),$(addprefix -I,$(dir)))
LINKS=$(foreach dir,$(LibDir),$(addprefix -L,$(dir)))

.PHONY:all clean

CFLAGS:=$(CFLAGS) $(INCS)
LDFALGS:=$(LINKS) $(LDFALGS) 
OBJS=$(SRCS:%.cpp=%.o)
all:$(BIN)

$(BIN):$(OBJS)
	@echo $(OBJS)
	$(CC) -o $(BIN) $(OBJS) $(LDFALGS)


%.o:%.cpp
	@echo "\t\tCompileing $@..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\tCleaning files..."
	$(RM) $(OBJS) $(BIN)
