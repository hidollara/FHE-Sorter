#include "encrypter.hpp"

Encrypter::Encrypter(
        long p, long r, long L, long c, long w, long d, long k, long s) :
    context(FindM(k, L, c, p, d, s, 0), p, r),
    secretKey(context),
    publicKey(secretKey)
{
    buildModChain(context, L, c);
    secretKey.GenSecKey(w);
}

ZZX Encrypter::getG() {
    return context.alMod.getFactorsOverZZ()[0];
}

Ctxt Encrypter::encrypt(int p) {
    Ctxt ctx(publicKey);
    publicKey.Encrypt(ctx, to_ZZX(p));
    return ctx;
}

NTL::ZZ Encrypter::decrypt(Ctxt ct) {
    ZZX pt;
    secretKey.Decrypt(pt, ct);
    return pt[0];
}

int main() {
    std::cout << "Initialize Encrypter..." << std::endl;
    Encrypter e;
    std::cout << "done" << std::endl;

    while (true) {
        int pt1, pt2;
        std::cout << "input 2 numbers: ";
        std::cin >> pt1 >> pt2;

        Ctxt ct1 = e.encrypt(pt1), ct2 = e.encrypt(pt2);

        Ctxt ctSum = ct1; ctSum += ct2;
        std::cout << pt1 << " + " << pt2 << " = " << e.decrypt(ctSum) << std::endl;

        Ctxt ctProd = ct1; ctProd *= ct2;
        std::cout << pt1 << " * " << pt2 << " = " << e.decrypt(ctProd) << std::endl;
    }

    return 0;
}
