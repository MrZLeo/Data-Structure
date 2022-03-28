build:
	cmake --build build

src:
	./build/src/src

test:
	./build/test/Google_Tests_run --gtest_filter=$(TEST_FLAGS)

.PHONY: build src test
