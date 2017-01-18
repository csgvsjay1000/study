CC=g++
LDFLAGS= -lpthread -lprotobuf
SrcDir=.
CFLAGS=-g
InDir=$(wildcard ./*.cc)
SRCS=$(foreach dir,$(SrcDir),$(wildcard $(dir)/*.cpp))
OBJS=$(SRCS:%.cpp=%.o) 
BIN=server
$(BIN):$(OBJS) $(InDir)
	$(CC) -o $(BIN) $^ $(LDFLAGS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS) $(BIN)
