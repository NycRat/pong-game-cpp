CXX := g++
CXXFLAGS := -std=c++17 -Wall

BIN := bin
SRC := src

TARGET := $(BIN)/main
BUILD := build

# SRCS := src/main.cpp src/Game.cpp src/Player.cpp src/Ball.cpp
# OBJS := $(BUILD)/main.o $(BUILD)/Game.o $(BUILD)/Player.o $(BUILD)/Ball.o

SRCS := $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))

LIBS := -l sfml-graphics -l sfml-audio -l sfml-window -l sfml-system 
# -l sfml-main
LDFLAGS := -L/usr/local/lib $(LIBS)
INCFLAGS = -I/usr/local/include -Iinclude

# compile:
# 	$(CXX) $(CXXFLAGS) -c -I/usr/local/include -Iinclude -o $(OBJS) $(SRCS)
# link: 
# 	$(CXX) $(OBJS) -o main-L /usr/local/lib $(LIBS)
	
run: build
	./$(TARGET)

build: clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

# -mwindows

.PHONY: clean
clean:
	rm -rf $(BUILD)
