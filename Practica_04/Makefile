# Directorios
BIN		= bin
SRC		= src
INCLUDE	= include

# Ejecutable Practica
TARGETS  = main
TEXTURES = textures

# Compilador
CXX	= g++ -Ofast -Wno-write-strings
CC	= gcc -Ofast

# Flags
CFLAGS   = -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE) - Wno-deprecated
CXXFLAGS = -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE) -Wno-deprecated
LDFLAGS	 = -lGL -lGLU -lglut -lm
LIBS     = -L/usr/X11R6/lib/ -lGL -lGLU -lglut -lm -lX11 -lpthread

# Ordenes Compilacion
all: clean $(TARGETS) $(TEXTURES)

$(TARGETS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cc $(CXXFLAGS) $(SRC)/puntos3D.cpp $(SRC)/triangulos3D.cpp $(SRC)/model_basic.cpp $(SRC)/model_revolution.cpp $(SRC)/model_ply.cpp $(SRC)/model_pieces.cpp $(SRC)/model_hierarchical.cpp $(SRC)/model_light.cpp $(SRC)/model_material.cpp $(SRC)/file_ply_stl.cc $(LDFLAGS)

$(TEXTURES):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cc $(CXXFLAGS) $(LIBS)

# Limpiador

clean:
	rm -f $(BIN)/main
	rm -f *.tgz

tgz:
	rm -f $(BIN)/main
	rm -f *.tgz
	tar -zcvf $(TARGETS).tgz *
