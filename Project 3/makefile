all: compilar
compilar: Character Herz Enemy Boss Item Weapon Bow Scimitar Greatsword Potion HealthPotion PowerPotion InstantDmgPotion EscapePotion AttackType Weak Strong Ultimate Main
		g++ Character.o Herz.o Enemy.o Boss.o Item.o Weapon.o Bow.o Scimitar.o Greatsword.o Potion.o HealthPotion.o PowerPotion.o InstantDmgPotion.o EscapePotion.o AttackType.o Weak.o Strong.o Ultimate.o Main.o -o ejecutable
Character: Character.hpp Character.cpp AttackType.hpp
		g++ -c Character.cpp
Herz: Herz.hpp Herz.cpp Character.hpp Weapon.hpp Item.hpp Potion.hpp
		g++ -c Herz.cpp
Enemy: Enemy.hpp Enemy.cpp Character.hpp
		g++ -c Enemy.cpp
Boss: Boss.hpp Boss.cpp Character.hpp
		g++ -c Boss.cpp
Item: Item.hpp Item.cpp
		g++ -c Item.cpp
Weapon: Weapon.hpp Weapon.cpp Item.hpp
		g++ -c Weapon.cpp
Bow: Bow.hpp Bow.cpp Weapon.hpp
		g++ -c Bow.cpp
Scimitar: Scimitar.hpp Scimitar.cpp Weapon.hpp
		g++ -c Scimitar.cpp
Greatsword: Greatsword.hpp Greatsword.cpp Weapon.hpp
		g++ -c Greatsword.cpp
Potion: Potion.hpp Potion.cpp Item.hpp Character.hpp Herz.hpp
		g++ -c Potion.cpp
HealthPotion: HealthPotion.hpp HealthPotion.cpp Potion.hpp
		g++ -c HealthPotion.cpp
PowerPotion: PowerPotion.hpp PowerPotion.hpp Potion.hpp
		g++ -c PowerPotion.cpp
InstantDmgPotion: InstantDmgPotion.hpp InstantDmgPotion.cpp Potion.hpp
		g++ -c InstantDmgPotion.cpp
EscapePotion: EscapePotion.hpp EscapePotion.cpp Potion.hpp
		g++ -c EscapePotion.cpp
AttackType: AttackType.hpp AttackType.cpp Character.hpp
		g++ -c AttackType.cpp
Weak: Weak.hpp Weak.cpp AttackType.hpp
		g++ -c Weak.cpp
Strong: Strong.hpp Strong.cpp AttackType.hpp
		g++ -c Strong.cpp
Ultimate: Ultimate.hpp Ultimate.cpp AttackType.hpp
		g++ -c Ultimate.cpp
Main: Main.cpp Herz.hpp Character.hpp Item.hpp Enemy.hpp Potion.hpp HealthPotion.hpp PowerPotion.hpp InstantDmgPotion.hpp EscapePotion.hpp
		g++ -c Main.cpp
