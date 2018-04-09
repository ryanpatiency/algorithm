all: algo


.d/algo.d: algo.c
	gcc -MMD -MF .d/algo.d algo.c

optalgo: 
	gcc -g -O3 -o $@ algo.c

algo.o:  algo.c .d/algo.d
	gcc -c -g -o $@ $<

-include .d/algo.d

.PHONY: clean
clean:
	rm -f algo
	rm -f algo.o
	rm -f .d/algo.d