SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
BIBLIOTHEQUE = libCourbe.a
AR = ar r
CFLAGS += -g -Wall


all: $(BIBLIOTHEQUE)

$(BIBLIOTHEQUE): $(OBJETS)
	$(AR) $@ $^

$(OBJETS): courbe.h

clean:
	rm -rf *.o *.a core
