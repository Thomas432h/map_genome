comment : # Compiler settings
CXX = g++
CXXFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
DATA_DIR = data

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/sequence_reader

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/*.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)