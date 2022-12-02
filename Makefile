CXX = g++

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = test.o FileReader.o Subsequence.o

main: Main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) main *.o
