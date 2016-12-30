all:server
CC=g++
server:msg.pb.cc server.cc	
	$(CC) -o $@ $^ -lprotobuf -lpthread
clean:
	rm -rf server *.o
