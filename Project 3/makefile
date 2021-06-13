all: compilar
compilar: Character Herz Enemy Boss Item Weapon Potion HealthPotion PowerPotion InstantDmgPotion EscapePotion Potion Main
		g++ Character.o Herz.o Enemy.o Boss.o Item.o Weapon.o Potion.o HealthPotion.o PowerPotion.o InstantDmgPotion.o EscapePotion.o Main.o -o ejecutable
Character: Character.hpp Character.cpp 
		g++ -c Character.cpp
Herz: Herz.hpp Herz.cpp Character.hpp
		g++ -c Herz.cpp
Enemy: Enemy.hpp Enemy.cpp Character.hpp
		g++ -c Enemy.cpp
Boss: Boss.hpp Boss.cpp Character.hpp
		g++ -c Boss.cpp
Item: Item.hpp Item.cpp
		g++ -c Item.cpp
Weapon: Weapon.hpp Weapon.cpp Item.hpp
		g++ -c Weapon.cpp
Potion: Potion.hpp Potion.cpp Item.hpp
		g++ -c Potion.cpp
HealthPotion: HealthPotion.hpp HealthPotion.cpp Potion.hpp
		g++ -c HealthPotion.cpp
PowerPotion: PowerPotion.hpp PowerPotion.hpp Potion.hpp
		g++ -c PowerPotion.cpp
InstantDmgPotion: InstantDmgPotion.hpp InstantDmgPotion.cpp Potion.hpp
		g++ -c InstantDmgPotion.cpp
EscapePotion: EscapePotion.hpp EscapePotion.cpp Potion.hpp
		g++ -c EscapePotion.cpp
Main: Main.cpp Herz.hpp Character.hpp Item.hpp Enemy.hpp Potion.hpp HealthPotion.hpp PowerPotion.hpp InstantDmgPotion.hpp EscapePotion.hpp
		g++ -c Main.cpp

#all: compilar
#compilar: conjuntoLista experto actaTrabajo criteriosCalificacion menu main
#		g++ -o actaTrabajo experto.o criteriosCalificacion.o actaTrabajo.o menu.o main.o conjuntoLista.o
#conjuntoLista: conjuntoLista.cpp conjuntoLista.h
#		g++ -c conjuntoLista.cpp
#criteriosCalificacion: criteriosCalificacion.cpp criteriosCalificacion.h
#		g++ -c criteriosCalificacion.cpp
#experto: experto.cpp experto.h
#		g++ -c experto.cpp
#actaTrabajo: actaTrabajo.cpp actaTrabajo.h
#		g++ -c actaTrabajo.cpp
#menu: menu.cpp menu.h
#		g++ -c menu.cpp
#main: main.cpp menu.h actaTrabajo.h experto.h 
#	  	g++ -c main.cpp
