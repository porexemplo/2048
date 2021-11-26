all: compile link

compile:
	g++ -std=c++11 -c main_game.cpp
	g++ -std=c++11 -c modele.cpp
	g++ -std=c++11 -c color.cpp

link:
	g++ -std=c++11 main_game.o modele.o color.o -o main_game
