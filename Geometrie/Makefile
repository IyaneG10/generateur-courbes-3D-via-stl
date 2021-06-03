SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
BIBLIOTHEQUE = libGeometrie.a
AR = ar r
CFLAGS += -g -Wall

all: $(BIBLIOTHEQUE)

$(BIBLIOTHEQUE): $(OBJETS)
	$(AR) $@ $^

$(OBJETS): Geometrie.h

clean:
	rm -rf *.o *.a core
