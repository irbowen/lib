## Isaac Bowen, eecs485win16p6

CXXFLAGS = -std=c++1z -pedantic -Wall -pthread -O3

INDEX_LIB := indexer.o indexer_main.o

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
splitter: split.cc helper.h $(TIMING_HEADERS)
	$(CXX) $(CXXFLAGS) split.cc -o splitter

########################################
clean:
	touch indexer splitter server
	rm indexer splitter server
	rm *.o

