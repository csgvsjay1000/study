CC=g++
BIN=server
CFLAGS=-std=c++11
SRCS=$(foreach dir,.,$(wildcard $(dir)/*.cpp))

OBJS=$(SRCS:%.cpp=%.o)

$(BIN):$(OBJS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -rf $(OBJS)

.PHONY:clean
