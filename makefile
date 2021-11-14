all: compile link

compile:
	g++ -I src/include -c main.cpp Game.cpp Player.cpp Ball.cpp
link: 
	g++ main.o Game.o Player.o Ball.o -o main -L src/lib -l sfml-graphics -l sfml-audio -l sfml-window -l sfml-system 
# g++ main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
# -mwindows