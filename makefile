CXX = g++
CXXFLAGS = -O2 -std=c++11
FHECXXFLAGS = $(CXXFLAGS) -pthread -DFHE_THREADS -DFHE_BOOT_THREADS
FHESRCS = Helib/src/fhe.a Encrypter.cpp
FHESORTSRCS = $(FHESRCS) FHESort.cpp FHEComp.cpp
FHETESTSRCS = $(FHESRCS) FHETest.cpp
INTSORTSRCS = IntSort.cpp IntComp.cpp

FHESort: $(FHESORTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $(FHESORTSRCS) -lntl -lgmp -lm

FHETest: $(FHETESTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $(FHETESTSRCS) -lntl -lgmp -lm

IntSort: $(INTSORTERSRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(INTSORTSRCS)

HElib/src/fhe.a:
	cd HElib/src; make;

clean:
	rm fhesort fhetest intsort
