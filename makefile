CXX = g++
CXXFLAGS = -O2 -std=c++11
FHECXXFLAGS = $(CXXFLAGS) -pthread -DFHE_THREADS -DFHE_BOOT_THREADS
FHESRCS = Helib/src/fhe.a Encrypter.cpp
ARRAYSRCS = $(FHESRCS) EncArrayEncrypter.cpp
ARRAYTESTSRCS = $(ARRAYSRCS) EncArrayTest.cpp
FHESORTSRCS = $(FHESRCS) FHESort.cpp FHEComp.cpp
FHETESTSRCS = $(FHESRCS) FHETest.cpp
INTSORTSRCS = IntSort.cpp IntComp.cpp

EncArrayTest: $(ARRAYTESTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $^ -lntl -lgmp -lm

FHESort: $(FHESORTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $^ -lntl -lgmp -lm

FHETest: $(FHETESTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $^ -lntl -lgmp -lm

IntSort: $(INTSORTSRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

HElib/src/fhe.a:
	cd HElib/src; make;

clean:
	rm EncArrayTest FHESort FHETest IntSort
