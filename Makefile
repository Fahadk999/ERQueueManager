CXX         := g++
CXXFLAGS    := -Wall -Wextra -std=c++11 -O2 -Iinclude
LDFLAGS     :=

# Directories and Source Files
SRC_DIR     := src
BUILD_DIR   := build
TARGET      := app

# Find all C++ source files recursively (including subdirectories like src/Utils)
SRCS        := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS        := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default Rule
all: $(BUILD_DIR)/$(TARGET)

# Link Object Files into the Final Executable
$(BUILD_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile Object Files (handles nested subdirectories automatically)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the Application
run: all
	./$(BUILD_DIR)/$(TARGET)

# Clean Build Files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
