CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = sort_demo

SRCS = src/main.cpp \
       src/counting_sort.cpp \
       src/radix_sort.cpp \
       src/bucket_sort.cpp \
       src/pigeonhole_sort.cpp \
       src/utils.cpp \
       src/experiment_design.cpp \    
       src/comparison_sort.cpp        

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) src/*.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run