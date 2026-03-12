.PHONY: build run clean all

build:
	cmake -G Ninja -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

run:
	./build/bin/Snake

clean:
	rm -rf build

all: build run
