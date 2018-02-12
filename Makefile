# Nicolle Ayon C.
# nayoncam
# This makefile with macros is for charType.c
# Makefile

FLAGS   = -std=c99 -Wall
SOURCES = charType.c
OBJECTS = charType.o
EXEBIN  = charType

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check :
	valgrind --leak-check=full charType charType.c outfile