#include "fhecomp.hpp"

std::pair<Ctxt, Ctxt> FHEComparator::compare(const Ctxt &a, const Ctxt &b) const {
    // eq := a ^ b ^ 1 = a + b + 1 (mod 2)
    // Ctxt eq = a; eq += b; eq.addConstant(to_ZZ(1));

    // lt := (a ^ 1) & b = (a + 1) * b (mod 2)
    Ctxt lt_then_a = a;
    lt_then_a.addConstant(to_ZZ(1));
    lt_then_a.multiplyBy(b);
    Ctxt lt_then_b = lt_then_a;
    // ge := lt ^ 1 = lt + 1 (mod 2)
    Ctxt ge_then_a = lt_then_a;
    ge_then_a.addConstant(to_ZZ(1));
    Ctxt ge_then_b = ge_then_a;

    lt_then_a.multiplyBy(a);
    lt_then_b.multiplyBy(b);
    ge_then_a.multiplyBy(a);
    ge_then_b.multiplyBy(b);

    return std::make_pair(lt_then_a += ge_then_b, lt_then_b += ge_then_a);
}
