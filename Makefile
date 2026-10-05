CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = -static-libgcc -static-libstdc++ -g
LDLIBS = -lX11

OUT_DIR = out
TARGET = $(OUT_DIR)/game

SRCS = sfw.cpp game_scene.cpp main.cpp

OBJS = $(patsubst %.cpp, $(OUT_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OUT_DIR)/%.o: %.cpp
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean