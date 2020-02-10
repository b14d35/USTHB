#!/bin/bash/
DOSSIER=$1
LICENS=""
TYPE=""
GIT=""
if [ $# == 0 ]; then 
	echo "Expected arguments, please check the help : initdev -help"
	exit 1
elif [ $# == 1 ]; then
		if [ $1 == "-help" ]; then
			echo "- Name : Application d'initialisation de projet."
			echo "- Syntax : ./main.sh nom_projet [-GPL | -MIT] [-C | -CPP | -C++ | -Py | -Latex | -BEAMER] [-git]."
			echo 
			echo "- args :"
			echo "	-GPL : GENERAL PUBLIC LICENSE."
			echo "	-MIT : Licence MIT."
			echo "	-C : Projet en langage C."
			echo "	-CPP | -C++ : Projet en langage C++."
			echo "	-Py : Projet en langage python."
			echo "	-Latex : Projet de rédaction en Latex."
			echo "	-BEAMER : Projet de présentation en BEAMER."
			
			echo "	-git : Initialisation d'un depot git."
			echo 
			echo "- author : ABDELAIDOUM Walid		Walidsd308@gmail.com"
			exit 0
		fi
elif [ $# == 2 ]; then
	key2=$2
	case $key2 in
		-GPL)
		LICENS="GPL"
		shift
		;;
		-MIT)
		LICENS="MIT"
		shift
		;;
		-C)
		TYPE="main.c"
		shift
		;;
		-CPP|-C++)
		TYPE="main.cpp"
		shift
		;;
		-Py)
		TYPE="main.py"
		shift
		;;
		-Latex)
		TYPE="latexMin.tex"
		shift
		;;
		-BEAMER)
		TYPE="beamer.tex"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
elif [ $# == 3 ]; then
	key2=$2
	key3=$3
	case $key2 in
		-C)
		TYPE="main.c"
		shift
		;;
		-CPP|-C++)
		TYPE="main.cpp"
		shift
		;;
		-Py)
		TYPE="main.py"
		shift
		;;
		-Latex)
		TYPE="latexMin.tex"
		shift
		;;
		-BEAMER)
		TYPE="beamer.tex"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
	case $key3 in
		-git)
		GIT="1"
		shift
		;;
		-GPL)
		LICENS="GPL"
		shift
		;;
		-MIT)
		LICENS="MIT"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
elif [ $# == 4 ]; then
	key2=$2
	key3=$3
	key4=$4
	case $key2 in
		-GPL)
		LICENS="GPL"
		shift
		;;
		-MIT)
		LICENS="MIT"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
	case $key3 in
		-C)
		TYPE="main.c"
		shift
		;;
		-CPP|-C++)
		TYPE="main.cpp"
		shift
		;;
		-Py)
		TYPE="main.py"
		shift
		;;
		-Latex)
		TYPE="latexMin.tex"
		shift
		;;
		-BEAMER)
		TYPE="beamer.tex"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
	case $key4 in
		-git)
		GIT="1"
		shift
		;;
		*)
		echo "Uknown arguments, please check the help : initdev –help"
		exit 1
		shift
		;;
	esac
else
	echo "Too many arguments, please check the help : initdev –help"
	exit 1
fi
if [ $GIT == "1" ]; then
	if [ $TYPE != "" ]; then
		case $TYPE in
			main.c)
			GIT="c"
			shift
			;;
			main.cpp)
			GIT="cpp"
			shift
			;;
			main.py)
			GIT="python"
			shift
			;;
			latexMin.tex | beamer.tex)
			GIT="tex"
			shift
			;;
		esac
	else
		echo "You must set project type, please check the help : initdev –help"
		exit 1
	fi
fi
if [ -d $DOSSIER ]; then
	echo "Projet existant sous le meme nom."
	exit 1
fi
mkdir $DOSSIER
touch ${DOSSIER}/LICENSE
touch ${DOSSIER}/Makefile
if [ $LICENS != "" ]; then
	cat /licenses/${LICENS} > ${DOSSIER}/LICENSE
fi
if [ $TYPE != "" ]; then
	cp /sources/${TYPE} .
else
	touch ${DOSSIER}/main
fi
if [ $GIT != "" ]; then
	touch ${DOSSIER}/.gitignore
	cat /gitignores/${GIT} > ${DOSSIER}/.gitignore
	cd ${DOSSIER}
	git init
	cd ..
fi
exit 0
