CC=gcc
BIN=webserver
#CFLAGS=-std=c++11
SRCS=$(foreach dir,.,$(wildcard $(dir)/*.c))

OBJS=$(SRCS:%.c=%.o)

$(BIN):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -rf $(OBJS)

.PHONY:clean
