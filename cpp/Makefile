build:
	cmake --build build

src: build
	./build/src/src

test: build
	./build/test/Google_Tests_run --gtest_filter=$(TEST_FLAGS)

.PHONY: build src test
