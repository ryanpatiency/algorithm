OBJ := algo.o
DEP := $(OBJ:%.o=.%.o.d)
EXEC := $(OBJ:%.o=%)

algo: algo.o
	gcc -o $@ $^
	
%.o: %.c
	gcc -o $@ -c -MMD -MF .$@.d $<
#
#.PHONY: clean
#
clean:
	rm $(OBJ)	
#
#include $(DEP)




