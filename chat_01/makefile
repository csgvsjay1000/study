
all:server
CC=g++
server:Student.pb.cc  server.cc
	$(CC) -o $@ $^ -lprotobuf  -lpthread 

clean:
	rm -rf server *.o
