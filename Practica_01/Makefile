# Practica
TARGETS = practica1_B

# Flags
CFLAGS = -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS = -g -DXWINDOWS -DSHM -I/usr/include -I.
LDFLAGS = -lGL -lGLU -lglut -lm

# Compilador
CC = g++

# Ordenes Compilacion
default : $(TARGETS)

$(TARGETS) : objetos_B.o practica1_B.o
	$(CC) -o $@ $(CXXFLAGS) objetos_B.o practica1_B.o $(LDFLAGS)

# Limpiador

clean:
	rm -f *.o
	rm -f $(TARGETS)

redo:
	touch *.cc
	make

superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *