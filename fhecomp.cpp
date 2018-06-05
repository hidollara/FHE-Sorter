#include "fhecomp.hpp"

std::pair<Ctxt, Ctxt> FHEComparator::compare(Ctxt a, Ctxt b) {
    // eq := a ^ b ^ 1 = a + b + 1 (mod 2)
    // Ctxt eq = a; eq += b; eq.addConstant(to_ZZ(1));

    // lt := (a ^ 1) & b = (a + 1) * b (mod 2)
    Ctxt lt = a; lt.addConstant(to_ZZ(1)); lt.multiplyBy(b);
    // ge := lt ^ 1 = lt + 1 (mod 2)
    Ctxt ge = lt; ge.addConstant(to_ZZ(1));

    Ctxt lta = lt; lta.multiplyBy(a);
    Ctxt ltb = lt; ltb.multiplyBy(b);
    Ctxt gea = ge; gea.multiplyBy(a);
    Ctxt geb = ge; geb.multiplyBy(b);

    return make_pair(lta += geb, gea += ltb);
}
