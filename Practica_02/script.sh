#!/bin/bash

# Uso: ./script.sh

# Guardamos los directorios necesarios
bin=$(pwd)/bin
data=$(pwd)/data/beethoven

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

_mostrar_menu(){
	clear
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~ Opciones ~~~~~~${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
	echo -e "${menu}1. Compilar${nocolor}"
	echo -e "${menu}2. Compilar y Ejecutar${nocolor}"
	echo -e "${menu}3. Comprimir${nocolor}"
	echo -e "${menu}4. Limpiar${nocolor}"
	echo -e "${menu}5. Salir${nocolor}"
	echo -e "${menu}~~~~~~~~~~~~~~~~~~~~~~~${nocolor}"
}

_leer_opcion(){
	local opcion
	read -p "Elige la Opcion (1-5): " opcion
	case $opcion in
		1) clear; _directorios_creacion; _directorios_limpieza; _compilar; exit 0;;
		2) clear; _directorios_creacion; _directorios_limpieza; _compilar; _ejecucion; exit 0;;
		3) clear; _directorios_creacion; _directorios_limpieza; _empaquetar; exit 0;;
		4) clear; _directorios_creacion; _directorios_limpieza; exit 0;;
		5) clear; exit 0;;
		*) echo -e "\n${error}Error! Introduce una Opcion Valida${nocolor}" && sleep 1
	esac
}

trap '' SIGINT SIGQUIT SIGTSTP

while true
do
	_mostrar_menu
	_leer_opcion
done
