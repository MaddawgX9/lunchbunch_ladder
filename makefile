CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11

APP_NAME=lunchbunch_ladder
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(APP_NAME) $(OBJS)

-include $(OBJS:.o=.d)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@
	$(CXX) -MM $(CPPFLAGS) $*.cpp > $*.d

clean:
	rm -f *.o $(APP_NAME).exe *.d
