PROGRAM = poslovniOglasi.out
CC      = gcc
CFLAGS  = -g -Wall -I./src/include $(shell mysql_config --cflags)
LDFLAGS = 
LDLIBS  = $(shell mysql_config --libs)
IDIR = src
ODIR = obj
_DEPS = queries.h
DEPS = $(patsubst %,$(IDIR)/include/%,$(_DEPS))
_OBJ = queries.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(PROGRAM): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS) $(LDLIBS) 
	
$(ODIR)/%.o: $(IDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDLIBS)

.PHONY: all create insert beauty clean dist 

all: create insert $(PROGRAM)

create:
	mysql -u root -proot -D mysql <db_creation_poslovni_oglasi.sql

insert:
	mysql -u root -proot -D mysql <datainserts/insert_all_data.sql

beauty:
	-indent -kr -nut main.c
	-rm *~ *BAK

clean:
	-rm $(ODIR)/*.o $(PROGRAM)

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)