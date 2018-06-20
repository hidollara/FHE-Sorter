#include "EncArrayComp.hpp"

std::pair<Ctxt, Ctxt> EncArrayComparator::compare(const Ctxt &a, const Ctxt &b) const {
    /** sample:
     *      a := 00001001
     *      b := 00001010
     */

    /** bitlevel-eq := a ^ b ^ 1 = a + b + 1 (mod 2)
     *
     *  sample:
     *      beq = 11111100
     */
    Ctxt beq = a; beq += b; beq += encrypter.getTrue();

    /** bitlevet-lt := (a ^ 1) & b = (a + 1) * b (mod 2)
     *
     *  sample:
     *      blt = 00000010
     */
    Ctxt blt = a; blt += encrypter.getTrue(); blt.multiplyBy(b);

    /** l-bit less than circuit:
     *
     *  sample:
     *      76543210
     *      ========
     *      00001001
     *      00001010
     *      |same|^
     *  lt(7) | eq(7)lt(6) | eq(7)eq(6)lt(5) | ...
     */

    /** MSB of lt indicates less-than flags.
     *  At first, lt initialize by MSB of blt: lt = 1000... & blt
     *
     *  sample:
     *      lt = 00000000
     */
    Ctxt lt = encrypter.getMSBTrue(); lt.multiplyBy(blt);

    /** MSB of beqs indicates sum of bit-equals.
     *  At first, beqs initilize by 1000...
     *
     *  sample:
     *      beqs = 10000000
     */
    Ctxt beqs = encrypter.getMSBTrue();

    /** for k in 1...BIT_WIDTH:
     *      beqs &= (beq << (k - 1))
     *      lt |= (beqs & (blt << k))
     *
     *  sample:
     *      k = 1, beqs = 10000000, tmp = 00000000, lt = 00000000
     *      k = 2, beqs = 10000000, tmp = 00000000, lt = 00000000
     *      k = 3, beqs = 10000000, tmp = 00000000, lt = 00000000
     *      k = 4, beqs = 10000000, tmp = 00000000, lt = 00000000
     *      k = 5, beqs = 10000000, tmp = 00000000, lt = 00000000
     *      k = 6, beqs = 10000000, tmp = 10000000, lt = 10000000
     *      k = 7, beqs = 00000000, tmp = 00000000, lt = 10000000
     */
    for (int k = 1; k < BIT_WIDTH; k++) {
        beqs.multiplyBy(beq); encrypter.ea.shift(beq, -1);
        encrypter.ea.shift(blt, -1); Ctxt tmp = blt; tmp.multiplyBy(beqs);
        Ctxt tmplt = lt; lt += tmp; tmp.multiplyBy(tmplt); lt += tmp;
    }

    // a < b then lt = Enc(11111111) else then lt = Enc(00000000)
    totalSums(encrypter.ea, lt);

    // ge := lt ^ 1 = lt + 1 (mod 2)
    Ctxt ge = lt; ge += encrypter.getTrue();

    Ctxt lt_then_a = lt; lt_then_a.multiplyBy(a);
    Ctxt lt_then_b = lt; lt_then_b.multiplyBy(b);
    Ctxt ge_then_a = ge; ge_then_a.multiplyBy(a);
    Ctxt ge_then_b = ge; ge_then_b.multiplyBy(b);

    return std::make_pair(lt_then_a += ge_then_b, lt_then_b += ge_then_a);
}
