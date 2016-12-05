CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11

OBJDIR=obj
SRCDIR=src
BINDIR=bin
APP_NAME=bin/lunchbunch_ladder
SRCS=$(wildcard src/*.cpp)
OTMP=$(SRCS:.cpp=.o)
OBJS=$(OTMP:src/%=obj/%)

all: $(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^

-include $(OBJS:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@
	$(CXX) -MM $(CPPFLAGS) $^ > $(OBJDIR)/$*.d

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(APP_NAME).exe $(OBJDIR)/*.d
