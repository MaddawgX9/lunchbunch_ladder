all: lbl.cpp Entity.cpp Ladder.cpp tinyxml/tinyxml.o tinyxml/tinyxmlparser.o tinyxml/tinyxmlerror.o tinyxml/tinystr.o
	g++ -std=c++11 -g lbl.cpp Entity.cpp Ladder.cpp tinyxml/tinyxml.o tinyxml/tinyxmlparser.o tinyxml/tinyxmlerror.o tinyxml/tinystr.o -o lbl

Entity.o: Entity.cpp Entity.h
	g++ -g -c Entity.cpp

Ladder.o: Ladder.cpp Ladder.h
	g++ -g -c Ladder.cpp

#ifeq ($(mode),release)
#	CFLAGS = -Wall
#else
#	mode = debug
#	CFLAGS = -g -Wall
#endif
#
#CC = g++
#PROG = lbl.exe
#
#SRCS := lbl.cpp Ladder.cpp Entity.cpp tinystr.cpp tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp
#
#OBJS := $(patsubst %.cpp, %.o, $(filter %.cpp,%(SRCS)))
#
#$(info "HELLO SARAH!!!!! I LOVE YOU!!! "$())
#
#.PHONY: all
#
#all: $(PROG)
#
#$(PROG): $(OBJS)
#	echo "$(CC) -o $(PROG) $(OBJS)"
#	$(CC) -o $(PROG) $(OBJS)
#
#%.o: %.cpp %.h
#	echo "$(CC) $(CFLAGS) -c $< -o $@"
#	$(CC) $(CFLAGS) -c $< -o $@
#
#clean:
#	rm -f $(OBJS) $(PROG)
