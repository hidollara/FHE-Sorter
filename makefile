CXX = g++
CXXFLAGS = -O2 -std=c++11
FHECXXFLAGS = $(CXXFLAGS) -pthread -DFHE_THREADS -DFHE_BOOT_THREADS
FHESRCS = encrypter.cpp Helib/src/fhe.a
FHESORTSRCS = fhesort.cpp fhecomp.cpp $(FHESRCS)
FHETESTSRCS = fhetest.cpp $(FHESRCS)
INTSORTSRCS = intsort.cpp intcomp.cpp

fhesort: $(FHESORTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $(FHESORTSRCS) -lntl -lgmp -lm

fhetest: $(FHETESTSRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $(FHETESTSRCS) -lntl -lgmp -lm

intsort: $(INTSORTERSRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(INTSORTSRCS)

HElib/src/fhe.a:
	cd HElib/src; make;

clean:
	rm fhesort fhetest intsort
