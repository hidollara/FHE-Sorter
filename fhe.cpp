#include "HElib/src/FHE.h"

int main() {
    long m = 0, p = 7, r = 1;
    long L = 16;
    long c = 3;
    long w = 64;
    long d = 0;
    long k = 128;
    long s = 0;

    m = FindM(k, L, c, p, d, s, 0);
    FHEcontext context(m, p, r);
    buildModChain(context, L, c);

    ZZX G = context.alMod.getFactorsOverZZ()[0];

    FHESecKey secretKey(context);
    const FHEPubKey& publicKey = secretKey;
    secretKey.GenSecKey(w);

    Ctxt ctx1(publicKey);
    Ctxt ctx2(publicKey);

    publicKey.Encrypt(ctx1, to_ZZX(2));
    publicKey.Encrypt(ctx2, to_ZZX(3));

    Ctxt ctSum = ctx1;
    ctSum += ctx2;

    ZZX ptSum;
    secretKey.Decrypt(ptSum, ctSum);

    std::cout << ptSum[0] << std::endl;

    return 0;
}
