# the compiler to use.
COMPILER = clang++

# include path
INCLUDE = include/

# program souce files
SOURCES = source/marketzilla/*.cpp

# test source files
TEST_SOURCES = test/marketzilla/*.cpp

# depencences
LIBS = gtest

# executable name
EXECUTABLE = marketzilla

all: test

test: $(SOURCES) $(TEST_SOURCES)
	$(COMPILER) -o $(EXECUTABLE) $(SOURCES) $(TEST_SOURCES) -I$(INCLUDE) -l$(LIBS)
	./$(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)