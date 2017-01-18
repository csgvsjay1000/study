CC=g++
CFLAGS=-Wall -g
LDFLAGS=-lbase
BIN=login_server
SrcDir=../base/
LibDir=../base

SRCS=$(foreach dir,.,$(wildcard $(dir)/*.cpp))
INCS=$(foreach dir,$(SrcDir),$(addprefix -I,$(dir)))
LINKS=$(foreach dir,$(LibDir),$(addprefix -L,$(dir)))

CFLAGS:=$(CFLAGS) $(INCS)
LDFLAGS:=$(LINKS)  $(LDFLAGS) 

OBJS=$(SRCS:%.cpp=%.o)
all:$(OBJS)
	$(CC) -o $(BIN) $^ $(LDFLAGS)

%.o:%.cpp
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(BIN)

