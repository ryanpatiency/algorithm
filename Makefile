%: %.c
	gcc -o $@ -g $<

all: clean test


clean:
	rm -f ./algo ./test
	