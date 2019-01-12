
# include path:
#  -I
#  or use environment variables:
#  	* c language: C_INLUCDE_PATH
#  	* c++ language: CPLUS_INCLUDE_PATH
#
# compile time library path:
#  -L
#  or use the environment variable
#   * LIBRARY_PATH
#
# runtime library path
# * linux:   LD_LIBRARY_PATH
# * macOS: DYLD_LIBRARY_PATH

hello: hello.c
	gcc -Wall hello.c -o hello

bad: bad-format-printf.c
	gcc -Wall $< -o $@

# automatic variables: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# $^ : all the prerequisites separated by spaces with duplicates removed
# $@ : the target
print_hello: hello_func_main.c hello_func.c
# gcc -Wall hello_func_main.c hello_func.c -o print_hello
	gcc -Wall -I./inc $^ -o $@


hello_srcs = hello_func_main.c hello_func.c
hello_objs = $(hello_srcs:.c=.o)
%.o: %.c
	$(CC) -Wall -I./inc -c $< -o $@
print_hello2: $(hello_objs)
	$(CC) $^ -o $@

# to demonstrate linking `-lm`
calc: calc.c
	$(CC) -Wall $< -o $@ -lm
# $(CC) -Wall -lm $< -o $@	# error! -lm should be placed at last!

# use static linking: `-static`
calc_static: calc.c
	$(CC) -Wall -static $< -o $@ -lm

.PHONY: clean
clean:
# $(RM) expands to `rm -f`
	$(RM) hello bad print_hello calc calc_static print_hello2
	$(RM) *.o *.i *.s

