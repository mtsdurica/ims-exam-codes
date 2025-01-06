CXX := g++
RM 	:= rm -rf
CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic
TARGET	:= mc
BUILD := ./build
OBJ_DIR	:= $(BUILD)/objects
SRC_FILES := $(wildcard *.cpp)	
OBJECTS := $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean build 

all: build ./$(TARGET)

$(OBJ_DIR)/%.o: %.cpp 
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $< -o $@ 

./$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

build:
	@mkdir -p $(OBJ_DIR)

clean: 
	$(RM) $(TARGET)
	$(RM) $(BUILD)
