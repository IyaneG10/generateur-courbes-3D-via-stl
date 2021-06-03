REPERTOIRES = Calcul Liste Courbe STL Geometrie
COMPILE = $(REPERTOIRES:%=all-%)
DEVERMINE = $(REPERTOIRES:%=debug-%)
NETTOYAGE = $(REPERTOIRES:%=clean-%)
export CFLAGS += -g -Wall 

all: $(COMPILE)
$(COMPILE):
	$(MAKE) -C $(@:all-%=%)
debug: $(DEVERMINE)
$(DEVERMINE): CFLAGS += -g -DDEVERMINE
$(DEVERMINE):
	$(MAKE) -C $(@:debug-%=%)

clean: $(NETTOYAGE)
$(NETTOYAGE):
	$(MAKE) -C $(@:clean-%=%) clean

all-Calcul:  all-Liste all-Courbe all-STL all-Geometrie
debug-Calcul:  debug-Liste debug-Courbe debug-STL debug-Geometrie

.PHONY: $(COMPILE) $(DEVERMINE) $(NETTOYAGE)
.PHONY: all debug clean
