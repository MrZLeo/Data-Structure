all:
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/opt/homebrew/bin/ninja -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -G Ninja -S /Users/mrzleo/CLionProjects/Data-Structure-Algorithm/cpp -B build

build:
	cmake --build build

src: build
	./build/src/src

test: build
	./build/test/Google_Tests_run --gtest_filter=$(TEST_FLAGS)

gdb: build
	lldb ./build/src/src

fmt:
	cd src/ && (ls *.cpp *.h *.hpp | xargs clang-format -i -style=WebKit)
	cd test/ && (ls *.cpp *.hpp | xargs clang-format -i -style=WebKit)

clean:
	rm -rf build/

.PHONY: build src test fmt all clean
