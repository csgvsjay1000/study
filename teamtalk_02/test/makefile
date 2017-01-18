CC=g++
LDFLAGS= -lpthread -lprotobuf
CFLAGS=-g
SrcDir=.
InDir=$(wildcard ./*.cc)
SRCS=$(foreach dir,$(SrcDir),$(wildcard $(dir)/*.cpp))
#INCS=$(foreach dir,$(InDir),$(addprefix -I,$(dir)))
CFLAGS:=$(CFLAGS) 
OBJS=$(SRCS:%.cpp=%.o) 
BIN=client
$(BIN):$(OBJS) $(InDir)
	$(CC) -o $(BIN) $^ $(LDFLAGS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BIN)
