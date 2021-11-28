all: compile link

compile:
	g++ -I src/include -c graphx.cpp
	g++ -I src/include -c main.cpp
	g++ -I src/include -c modele.cpp
link:
	g++ main.o graphx.o modele.o -o main -L src/lib -l sfml-graphics -l sfml-system -l sfml-window