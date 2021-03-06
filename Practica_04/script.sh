#!/bin/bash

# Uso: ./script.sh

# Guardamos los directorios necesarios
bin=$(pwd)/bin
data=$(pwd)/data/PLY/beethoven

# Colores para los mensajes por terminal
nocolor='\033[0m'
color='\033[0;34m'
error='\033[0;31m'
menu='\033[1;35m'

# Procedimiento para crear los directorios necesarios
_directorios_creacion(){
	# Se crean los directorios "vacios" si no existen
	echo -e "${color}Comprobando el Directorio 'bin'...\n${nocolor}"
	if [ -d $bin ];
	then
		echo -e "${color}Directorio 'bin' Listo\n${nocolor}"
	else
		echo -e "${color}No Existe el Directorio 'bin'. Creando...\n${nocolor}"
		mkdir $bin
		echo -e "${color}Directorio 'bin' Creado\n${nocolor}"
	fi
}

# Procedimiento de limpieza de archivos
_directorios_limpieza(){
	# Usa make clean para limpiar
	echo -e "\n${color}Limpiando los Directorios...\n${nocolor}"
	make clean
	echo -e "${color}\nLimpieza Finalizada\n${nocolor}"
}

# Procedimiento de compilacion del proyecto
_compilar(){
	# Compila el codigo
	echo -e "\n${color}Compilando en Codigo...\n${nocolor}"
	make
	echo -e "${color}\nProyecto Compilado${nocolor}"
}

# Procedimiento para comprimir el proyecto
_empaquetar(){
	echo -e "${color}Comprimiendo el Proyecto...\n${nocolor}"
	make tgz
	echo -e "${color}\nProyecto Comprimido${nocolor}"
}

# Procedimiento para ejecutar el proyecto
_ejecucion(){
	#Ejecucion del programa
	echo -e "\n${color}Ejecutando...\n${nocolor}"
	$bin/main $data
	echo -e "\n${color}Ejecucion Finalizada${nocolor}"
}

# Procedimiento para ejecutar el proyecto de texturas
_ejecucion_texturas(){
	#Ejecucion del programa
	echo -e "\n${color}Ejecutando...\n${nocolor}"
	$bin/textures $data/caja.jpg $data/blackfriday.png
	echo -e "\n${color}Ejecucion Finalizada${nocolor}"
}

# Menu de la Aplicacion
_mostrar_menu(){
	clear
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~ Opciones ~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}1. Compilar${nocolor}"
	echo -e "${menu}2. Compilar y Ejecutar (PLY Predefinido)${nocolor}"
	echo -e "${menu}3. Compilar y Ejecutar (Elegir PLY)${nocolor}"
	echo -e "${menu}4. Compilar y Ejecutar Texturas${nocolor}"
	echo -e "${menu}5. Comprimir${nocolor}"
	echo -e "${menu}6. Limpiar${nocolor}"
	echo -e "${menu}7. Salir${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
}

# Menu de los Modelos PLY
_menu_ply(){
	clear
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~ Menu PLY ~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}1. Airplane${nocolor}"
	echo -e "${menu}2. Beethoven${nocolor}"
	echo -e "${menu}3. Big Porsche${nocolor}"
	echo -e "${menu}4. Big Spider${nocolor}"
	echo -e "${menu}5. F16${nocolor}"
	echo -e "${menu}6. Galleon${nocolor}"
	echo -e "${menu}7. Hydrant${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
}

# Escoger PLY
_opcion_ply(){
	local opcion
	read -p "Elige la Opcion (1-7): " opcion
	case $opcion in
		1) clear; data=$(pwd)/data/PLY/airplane; exit 0;;
		2) clear; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		3) clear; data=$(pwd)/data/PLY/big_porsche; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		4) clear; data=$(pwd)/data/PLY/big_spider; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		5) clear; data=$(pwd)/data/PLY/f16; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		6) clear; data=$(pwd)/data/PLY/galleon; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		7) clear; data=$(pwd)/data/PLY/hydrant; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		*) clear; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
	esac
}

# Escoger Aplicacion
_leer_opcion(){
	local opcion
	read -p "Elige la Opcion (1-6): " opcion
	case $opcion in
		1) clear; _directorios_creacion; _directorios_limpieza; _compilar; exit 0;;
		2) clear; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		3) clear; _menu_ply; _opcion_ply; exit 0;;
		4) clear; _directorios_creacion; _directorios_limpieza; _compilar; data=$(pwd)/data/Textures/; _ejecucion_texturas; exit 0;;
		5) clear; _directorios_creacion; _directorios_limpieza; _empaquetar; exit 0;;
		6) clear; _directorios_creacion; _directorios_limpieza; exit 0;;
		7) clear; exit 0;;
		*) echo -e "\n${error}Error! Introduce una Opcion Valida${nocolor}" && sleep 1
	esac
}

trap '' SIGINT SIGQUIT SIGTSTP

while true
do
	_mostrar_menu
	_leer_opcion
done
