PROGRAM = poslovniOglasi.out
CC      = gcc
CFLAGS  = -g -Wall -I./src/include $(shell mysql_config --cflags)
LDFLAGS = 
LDLIBS  = $(shell mysql_config --libs)
IDIR = src
ODIR = obj
_DEPS = 
DEPS = $(patsubst %,$(IDIR)/include/%,$(_DEPS))
_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(PROGRAM): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS) $(LDLIBS) 
	
$(ODIR)/%.o: $(IDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDLIBS)

.PHONY: beauty clean dist

beauty:
	-indent -kr -nut main.c
	-rm *~ *BAK

clean:
	-rm $(ODIR)/*.o $(PROGRAM)

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)