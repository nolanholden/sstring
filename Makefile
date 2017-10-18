CC      = gcc
CFLAGS  = -g
RM      = rm -f

default: all
all: sstring
sstring: main.c sstring.h sstring_util.h sstring_constants.h sstring_assert.h sstring_bool.h sstring_ternary.h
	$(CC) $(CFLAGS) -o sstring main.c sstring.c sstring_util.c sstring_constants.c sstring_assert.c sstring_bool.c sstring_ternary.c

clean:
	$(RM) sstring


-include speck/speck.mk

test: $(SPECK) $(SUITES)
	@$(SPECK) -v
	@$(SPECK) -f
	@$(SPECK)