OBJS = client.o suffArr.o search.o timer.o
CC = g++
CFLAGS = -Wall -c -std=c++11
LFLAGS = -Wall
EXEC = SuffixArray

all: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o $(EXEC)
		
timer.o : timer.h timer.cpp
		$(CC) $(CFLAGS) timer.cpp

suffArr.o : suffArr.h suffArr.cpp
	    $(CC) $(CFLAGS) suffArr.cpp

search.o : search.h search.cpp
	    $(CC) $(CFLAGS) search.cpp

client.o: search.h suffArr.h timer.h client.h client.cpp
		$(CC) $(CFLAGS) client.cpp

clean:
	rm -f $(OBJS)
	rm -f $(EXEC)
run:
	./$(EXEC)




