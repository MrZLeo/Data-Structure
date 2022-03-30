build:
	cmake --build build

src: build
	./build/src/src

test: build
	./build/test/Google_Tests_run --gtest_filter=$(TEST_FLAGS)

fmt:
	cd src/ && (ls *.cpp *.h *.hpp | xargs clang-format -i -style=WebKit)
	cd test/ && (ls *.cpp *.hpp | xargs clang-format -i -style=WebKit)

.PHONY: build src test fmt
