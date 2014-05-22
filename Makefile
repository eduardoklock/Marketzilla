# the compiler to use.
COMPILER = clang++

# include path
INCLUDE = -Iinclude/

# program souce files
SOURCES = source/marketzilla/*.cpp

# test source files
TEST_SOURCES = test/marketzilla/*.cpp

# depencences
LIBS = -lgtest

# flags for compiling
FLAGS = -std=c++11

# executable name
EXECUTABLE = marketzilla

all: test

test: $(SOURCES) $(TEST_SOURCES)
    $(COMPILER) -o $(EXECUTABLE) $(SOURCES) $(TEST_SOURCES) $(INCLUDE) $(LIBS) $(FLAGS)
    ./$(EXECUTABLE)

clean:
    rm -rf *.o $(EXECUTABLE)