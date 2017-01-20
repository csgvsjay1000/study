CC=g++
CFLAGS=-Wall -g
LDFLAGS=-lbase
BIN=test_client
SrcDir=../base/
LibDir=../base/
SRCS=$(foreach dir,.,$(wildcard $(dir)/*.cpp))
INCS=$(foreach dir,$(SrcDir),$(addprefix -I,$(dir)))
LIBS=$(foreach dir,$(LibDir),$(addprefix -L,$(dir)))
CFLAGS:=$(CFLAGS) $(INCS)
LDFLAGS:=$(LDFLAGS) $(LIBS)
OBJS=$(SRCS:%.cpp=%.o)
all:$(OBJS)
	$(CC) -o $(BIN) $^ $(LDFLAGS)

%.o:%.cpp
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(BIN)

