DEP_INC = -I./dependencies/include
DEP_LIB_DIR = -L./dependencies/lib
DEP_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	mingw32-g++.exe -std=c++14 -Wall main.cpp tictactoe.cpp -o ./bin/tictactoe.exe $(DEP_INC) $(DEP_LIB_DIR) $(DEP_LIBS) 