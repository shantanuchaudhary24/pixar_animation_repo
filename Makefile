CXX=g++
EXE=bin/run
FILES= src/ctexture.cpp src/plane.cpp src/ball.cpp src/lamp.cpp src/matrix.cpp src/scene.cpp src/main.cpp
COMPILE=-c
LINK=-o
OBJECTS= obj/ctexture.o obj/plane.o obj/ball.o obj/lamp.o obj/matrix.o obj/scene.o obj/main.o
OBJDIR= obj/
LIBS= -lGL -lGLU -lglut -lm
DISABLE_WARNING=-w
DEBUG= -g
DIR=~/repositories/pixar_animation
CONFIG_DIR=config/
CONFIG_FILE=config.cfg
all: build

build:
	clear
	$(CXX) $(COMPILE) $(FILES)  $(LIBS)
	mv *.o $(OBJDIR)
	$(CXX) $(LINK) $(EXE) $(OBJECTS) $(LIBS)

run:
	./$(EXE)

gdb:
	$(CXX) $(DEBUG) $(COMPILE) $(FILES)  $(LIBS)
	mv *.o $(OBJDIR)
	$(CXX) $(LINK) $(EXE) $(OBJECTS) $(LIBS)

cscope:
	cscope -R -b

clean:
	rm -rf $(EXE)
	rm -rf $(OBJECTS)
	rm -rf *.h~ *.cpp~ *Makefile~
