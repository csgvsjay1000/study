CC=g++
CFLAGS=-Wall -g
LDFLAGS=
BIN=test_client
SrcDir=../base/
SRCS=$(foreach dir,.,$(wildcard $(dir)/*.cpp))
INCS=$(foreach dir,$(SrcDir),$(addprefix -I,$(dir)))
CFLAGS:=$(CFLAGS) $(INCS)
OBJS=$(SRCS:%.cpp=%.o)
all:$(OBJS)
	$(CC) -o $(BIN) $^ $(LDFLAGS)

%.o:%.cpp
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(BIN)

