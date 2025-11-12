WINLIBS = -lopengl32 -lgdi32 -lwinmm # Define Windows-specific libraries
LINUXLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 # Define Linux-specific libraries

# Detect operating system and set appropriate variables
ifeq ($(OS), Windows_NT)
	LIBS = $(WINLIBS)
	OUT_EXT = .exe
else
	LIBS = $(LINUXLIBS)
	OUT_EXT = 
endif

# Default target
all: ./bin/app

# Main build rule
./bin/app: $(shell find src -name '*.cpp') 
	mkdir -p ./bin/
	g++ $^ -o ./bin/app$(OUT_EXT) -g -O1 -Wall -std=c++20 -Wno-missing-braces $(LIBS)

# Remove built executable
clean:
	rm -f ./bin/app$(OUT_EXT)

# Builds and then runs the application
run: ./bin/app
	./bin/app

# Phony targets (don't represent actual files)
.PHONY: all clean run
