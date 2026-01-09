CXX = g++
CXXFLAGS = -Wall -std=c++23 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

SRC = src/*
OUT = build/app

all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -rf build
