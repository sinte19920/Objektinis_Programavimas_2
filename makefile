CXX = g++
CXXFLAGS = -std=c++17 -O1

SRCS = main.cpp funkcijos.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: main

main: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJS) main

.DEFAULT_GOAL := all
