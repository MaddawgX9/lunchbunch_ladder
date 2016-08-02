CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g

APP_NAME=lunchbunch_ladder
SRCS=
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CXX) -o $(APP_NAME) $(OBJS)

%.o: %.cpp
	g++ $(CPPFLAGS) -c $@ $<

clean:
	rm -f *.o lbl.exe
