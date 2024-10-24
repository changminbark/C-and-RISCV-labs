# default
CFLAGS=-Wall -Werror -std=c99
LINK.c = $(CC) $(CLFAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)

# Recipe to execute (built-in):
%: %c
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
