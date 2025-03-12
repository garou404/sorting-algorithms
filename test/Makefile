CC=gcc
DEPS=sth.h
FLAGS=-Wall -Werror


%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# $@ Makefile automatic variable that represents the target file (usually the object file in this case).
# $< Makefile automatic variable that refers to the first prerequisite (dependency), which is typically the source file (.c).

test: test.o 
	$(CC) -o test test.o -g 

# -L. -lm -lcmocka
# -L. tell gcc to add the current directory to the lib search path
# -lm This specifies the math library (libm), link the lib to the program
# -lcmocka links teh cmocka lib
# -g generate debugging information for use by a symbolic debugger,
# and makes prgram state available to the debugging session


# make_lib:
# 	make -C ./lib