SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
	BIBLIOTHEQUE = libSTL.a
	AR = ar r
	CFLAGS += -g -Wall
	CFLAGS += -I ../Liste
	CFLAGS += -I ../Geometrie

all: $(BIBLIOTHEQUE)

$(BIBLIOTHEQUE): $(OBJETS)
	$(AR) $@ $^

$(OBJETS): STL.h

clean:
	rm -rf *.o *.a core
