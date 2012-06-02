MRUBY_ROOT = /usr/local/src/mruby
LUA_ROOT = /usr/local/lua5.1

INCLUDES = -I$(MRUBY_ROOT)/include -I$(MRUBY_ROOT)/src -I$(LUA_ROOT)/include
LIB = -lm $(MRUBY_ROOT)/mrblib/mrblib.o -lm $(MRUBY_ROOT)/lib/libmruby.a
CFLAGS = $(INCLUDES) -O3 -g -Wall -Werror-implicit-function-declaration -shared -O

CC = gcc

all :
	$(CC) $(CFLAGS) -o mruby.so mruby.c $(LIB)

clean :
	rm -f *.so
