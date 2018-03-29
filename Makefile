%: %.c
	gcc -o $@ -g $<

all: algo


clean:
	rm -f ./algo ./test
	