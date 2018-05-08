CXX = g++
CXXFLAGS = -std=c++11
SRCS = *.cpp
TARGET = sorter

all: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
