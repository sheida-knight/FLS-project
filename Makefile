CC=gcc
CFLAGS=-g -ggdb -Wall -pedantic -Wextra -fno-stack-protector 
DEPS = parameters.h 
OBJ = main.o start.o read_spins.o get_neighbors.o generate_FLS_table.o FLS_type.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 
clean :
	rm -rf *o 