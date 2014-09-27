CXX=g++
EXE=bin/run
FILES= src/main.cpp
COMPILE=-c
LINK=-o
OBJECTS= obj/main.o
OBJDIR= obj/
LIBS= -lGL -lGLU -lglut -lm
DISABLE_WARNING=-w
DEBUG= -g
DIR=~/repositories/pixar_animation
CONFIG_DIR=config/

all: build

build:
	$(CXX) $(COMPILE) $(FILES)  $(LIBS)
	mv *.o $(OBJDIR)
	$(CXX) $(LINK) $(EXE) $(OBJECTS) $(LIBS)

run:
	./$(EXE)

gdb:
	$(CXX) $(DEBUG) $(COMPILE) $(FILES)  $(LIBS)
	mv *.o $(OBJDIR)
	$(CXX) $(LINK) $(EXE) $(OBJECTS) $(LIBS)

debug:	gdb
	gdb $(DIR)$(EXE)

cscope:
	cscope -R -b

clean:
	rm -rf $(EXE)
	rm -rf $(OBJECTS)
	rm -rf *.h~ *.cpp~ *Makefile~
