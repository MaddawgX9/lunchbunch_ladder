all: lbl.cpp Entity.cpp Ladder.cpp tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp
	g++ -std=c++11 -g lbl.cpp Entity.cpp Ladder.cpp tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp -o lbl
