# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib
INC_DIR = include

# Files
LIBRARY = $(LIB_DIR)/darray.a
TEST_BIN = $(BIN_DIR)/darray_test
SRC_FILES = $(SRC_DIR)/darray.c
OBJ_FILES = $(OBJ_DIR)/darray.o
TEST_SRC = test/darray_test.c
TEST_OBJ = $(OBJ_DIR)/darray_test.o

# Default target (builds everything and runs the tests)
all: $(LIBRARY) $(TEST_BIN)
	@echo "Running tests..."
	./$(TEST_BIN)

# Build the static library
$(LIBRARY): $(OBJ_FILES) | $(LIB_DIR)
	@echo "Building library..."
	ar rcs $@ $^

# Create the lib directory if it doesn't exist
$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

# Compile the object file for darray.c
$(OBJ_DIR)/darray.o: $(SRC_DIR)/darray.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile the object file for the test
$(OBJ_DIR)/darray_test.o: $(TEST_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Build the test binary
$(TEST_BIN): $(OBJ_FILES) $(TEST_OBJ) $(LIBRARY)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up the build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
