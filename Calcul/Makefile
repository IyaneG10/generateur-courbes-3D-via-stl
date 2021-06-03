SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
BIBLIOTHEQUES =  -L ../Liste -lListe -L ../Courbe -lCourbe -L ../Geometrie -lGeometrie -L ../STL -lSTL -lm
EXECUTABLE = Calcul
CFLAGS += -g -Wall -I ../Liste -I ../Courbe -I ../Geometrie -I ../STL

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJETS)
	$(CC) -o $@ $^ $(BIBLIOTHEQUES)

clean:
	rm -rf $(EXECUTABLE) *.o
