## Isaac Bowen, eecs485win16p6

CXXFLAGS = -std=c++1z -pedantic -Wall -pthread -O3

INDEX_LIB := indexer.o indexer_main.o

STRING_LIB := strs/*.h
TIMING_HEADERS := timing/*.h

########################################
default: all 
all: splitter

DEPS := $(wildcard *.h)

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

indexer: $(INDEX_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

########################################
splitter: strs/split.cc $(STRING_LIB) $(TIMING_HEADERS)
	$(CXX) $(CXXFLAGS) strs/split.cc -o bin/splitter

########################################
clean:
	rm bin/*
	rm *.o


