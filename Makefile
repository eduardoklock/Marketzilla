# the compiler to use.
COMPILER=clang++

# include path
INCLUDE=-Iinclude

# program souce files
SOURCES=source/marketzilla/*.cpp

# test source files
TEST_SOURCES=$(SOURCES) test/marketzilla/*.cpp

# depencences
LIBS=-lgtest

# flags for compiling
FLAGS=-std=c++11

# executable name
EXECUTABLE=marketzilla

all: $(TEST_SOURCES)
	$(COMPILER) -o $(EXECUTABLE) $(TEST_SOURCES) $(INCLUDE) $(LIBS) $(FLAGS)
	./$(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)