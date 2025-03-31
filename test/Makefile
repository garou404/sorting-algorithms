CC=gcc
FLAGS=-Wall -Werror
#  -I../tree_sort/tree_sort.h -I../merge_sort/merge_sort.h -I../heap_sort/heap_sort.h
TARGET=testSort
P=../sort/
SRCS=test.c $(P)tree_sort/tree_sort.c $(P)merge_sort/merge_sort.c $(P)heap_sort/heap_sort.c
OBJS=$(SRCS:.c=.o)


# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -L./lib -lcmocka
# $@ Makefile automatic variable that represents the target file (usually the object file in this case).
# $< Makefile automatic variable that refers to the first prerequisite (dependency), which is typically the source file (.c).
# $^ Makefile automatic variable that refers to all prerequisites (dependencies)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -L./lib -lcmocka

clean:
	rm -f $(OBJS) $(TARGET)

# -L. -lm -lcmocka
# -L. tell gcc to add the current directory to the lib search path
# -lm This specifies the math library (libm), link the lib to the program
# -lcmocka links teh cmocka lib
# -g generate debugging information for use by a symbolic debugger,
# and makes prgram state available to the debugging session