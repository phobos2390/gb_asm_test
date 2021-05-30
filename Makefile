NAME := test_engine
TEST_NAME := test_$(NAME)
MBC_TYPE := 0x1B
RAM_SIZE := 0x2
TEST_ENGINE_DIR := ./src
TEST_DIRECTORY := ./src/test

build_test:
	@mkdir -p build
	rgbasm -i $(TEST_ENGINE_DIR)/utils -i $(TEST_ENGINE_DIR) -i $(TEST_DIRECTORY) $(TEST_ENGINE_DIR)/app/*.asm -o build/$(TEST_NAME).o 
	rgblink -o build/$(TEST_NAME).gb build/$(TEST_NAME).o -m build/$(TEST_NAME).map -n build/$(TEST_NAME).sym
	rgbfix -v -p 0 build/$(TEST_NAME).gb

clean:
	rm -rf build/

test: build_test
	sameboy_debugger build/$(TEST_NAME).gb

run_test: build_test
	sameboy build/$(NAME).gb

debug_test: build_test
	sameboy_debugger build/$(NAME).gb

all: build_test

