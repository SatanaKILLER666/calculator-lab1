OBJS	= output/main.o output/calc.o
SOURCE	= main.c calc.c
HEADER	= calc.h
OUT	= output/calculator
FLAGS	= -g -c 
CC	= gcc
ARGUM = ""

all:	output/calculator

output/calculator: $(OBJS)
	$(CC) -o $@ $^

output/%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c -o $@ $< 

clean:
	rm -f $(OBJS) $(OUT)

run: output/calculator
	make clean
	make
	./output/calculator $(ARGUM)