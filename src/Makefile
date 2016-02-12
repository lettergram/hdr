CPP = g++
C_FLAGS = -I/usr/local/include
L_FLAGS = -lfann
SRC_DIR = src
BUILD_DIR = build

all: train test convert bulk-test own-test

train: $(SRC_DIR)/train.cpp
	$(CPP) $(SRC_DIR)/train.cpp $(C_FLAGS) $(L_FLAGS) -o $(BUILD_DIR)/train

test: $(SRC_DIR)/test.cpp
	$(CPP) $(SRC_DIR)/test.cpp $(C_FLAGS) $(L_FLAGS) -o $(BUILD_DIR)/test

bulk-test: $(SRC_DIR)/bulk-test.cpp
	$(CPP) $(SRC_DIR)/bulk-test.cpp $(C_FLAGS) $(L_FLAGS) -o $(BUILD_DIR)/bulk-test

own-test: $(SRC_DIR)/own-test.cpp
	$(CPP) $(SRC_DIR)/own-test.cpp $(C_FLAGS) $(L_FLAGS) -lIL -lILU -o $(BUILD_DIR)/own-test

convert: $(SRC_DIR)/convert.cpp
	$(CPP) $(SRC_DIR)/convert.cpp $(C_FLAGS) -o $(BUILD_DIR)/convert

clean:
	rm -rf $(BUILD_DIR)/*
