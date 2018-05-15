CXX = g++
CXXFLAGS = -O2 -std=c++11
FHECXXFLAGS = $(CXXFLAGS) -pthread -DFHE_THREADS -DFHE_BOOT_THREADS
SORTERSRCS = main.cpp intcomp.cpp
FHESRCS = fhe.cpp Helib/src/fhe.a

sorter: $(SORTERSRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SORTERSRCS)

fhe: $(FHESRCS)
	$(CXX) $(FHECXXFLAGS) -o $@ $(FHESRCS) -lntl -lgmp -lm

HElib/src/fhe.a:
	cd HElib/src; make;

