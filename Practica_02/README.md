Practica 02 - Modelos PLY y Poligonales
==========================================

Ejecutar el Proyecto
-----------------------
    ./script.sh

Menu del Proyecto
--------------------
    1. Compilar
    2. Compilar y Ejecutar (PLY Predefinido)
    3. Compilar y Ejecutar (Elegir PLY)
    4. Comprimir
    5. Limpiar
    6. Salir

Opciones
-----------
    Tecla p: Visualizar en modo puntos
    Tecla l: Visualizar en modo líneas/aristas
    Tecla f: Visualizar en modo relleno
    Tecla c: Visualizar en modo ajedrez
    Tecla 1: Activar tetraedro
    Tecla 2: Activar cubo
    Tecla 3: Activar cono
    Tecla 4: Activar cilindro
    Tecla 5: Activar esfera
    Tecla 6: Activar objeto PLY cargado
    Tecla 7: Activar tetraedro
    Tecla 8: Activar diamante
    Tecla 9: Activar peon
    Tecla 0: Activar tubo

Funcionalidad Extra
----------------
    + Script Bash y Menu
    + Objetos PLY
    + Objeto Peon
    + Objeto Esfera
    + Objeto Cilindro
    + Objeto Cono
    + Objeto Peon
    + Objeto Tubo
    + Objeto Revolucion Parcial (Construir Solo Una Seccion Del Objeto) (Se modifica en include/model_revolution.h cambiando los valores de lAng y gAng)

Explicaciones Extra
----------------------
	+ Revolucion Parcial: Construir solo una seccion del objeto. Ejemplo: medio cilindro (lAng = 0, gAng = 180). Se modifica en include/model_revolution.h, parametros lAng y gAng.
	+ Inversion: El codigo esta preparado para dibujar el perfil de arriba hacia a abajo o a la inversa.
	+ Los objetos por revolucion son: Cono (3), Cilindro (4), Esfera (5), Peon (9) y Tubo (0).
