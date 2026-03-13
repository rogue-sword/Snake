.PHONY: build run clean all format

build:
	cmake -G Ninja -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

run:
	./build/bin/Snake

clean:
	rm -rf build

all: build run

format:
	find src/ -name '*.cpp' -o -name '*.h' | xargs clang-format -i

