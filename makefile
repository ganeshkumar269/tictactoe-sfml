all:
	mingw32-g++.exe -std=c++14 -Wall main.cpp tictactoe.cpp -o tictactoe.exe -I C:\SFML-2.5.1\include -L C:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system