# Makefile for the cplus project

.PHONY: all clean

# The 'all' target is the default.
# It will:
# 1. Clean the previous build directory.
# 2. Create a new build directory.
# 3. Run CMake to configure and then make to compile the project.
all:
	@echo "--- Cleaning and rebuilding project ---"
	@rm -rf build
	@mkdir -p build
	@cd build && cmake .. && make all

clean:
	@echo "--- Cleaning build directory ---"
	@rm -rf build
