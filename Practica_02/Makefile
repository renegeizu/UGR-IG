# Directorios
BIN		= bin
SRC		= src
INCLUDE	= include

# Ejecutable Practica
TARGETS = main

# Compilador
CXX	= g++ -Ofast -Wno-write-strings
CC		= gcc -Ofast

# Flags
CFLAGS	= -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE) - Wno-deprecated
CXXFLAGS	= -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE) -Wno-deprecated
LDFLAGS	= -lGL -lGLU -lglut -lm

# Ordenes Compilacion
all: clean $(TARGETS)

$(TARGETS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cc $(CXXFLAGS) $(SRC)/puntos3D.cpp $(SRC)/triangulos3D.cpp $(SRC)/model_basic.cpp $(SRC)/model_revolution.cpp $(SRC)/model_ply.cpp $(SRC)/file_ply_stl.cc $(LDFLAGS)

# Limpiador

clean:
	rm -f $(BIN)/main
	rm -f *.tgz

tgz:
	rm -f $(BIN)/main
	rm -f *.tgz
	tar -zcvf $(TARGETS).tgz *
