CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Wno-array-bounds
TARGET = sort_demo

SRCS = main.cpp \
       counting_sort.cpp \
       radix_sort.cpp \
       bucket_sort.cpp \
       pigeonhole_sort.cpp \
       utils.cpp \
       experiment_design.cpp \
       comparison_sort.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run