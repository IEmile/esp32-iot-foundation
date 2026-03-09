CC = gcc
CFLAGS = -Wall

all: program

program: mmain.o math.o
	echo "Bulding the application"
	$(CC) mmain.o math.o -o program

main.o: mmain.c math.h
	@echo "compailing the main with the c flag"
	$(CC) $(CFLAGS) -c main.c

math.o: math.c math.h
	$(CC) $(CFLAGS) -c math.c

.PHONY: claen
clean:
	rm -f *.o program

