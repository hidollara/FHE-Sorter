#include "EncArrayEncrypter.hpp"

int main() {
    std::cout << "Initialize Encrypter..." << std::endl;
    EncArrayEncrypter e;
    std::cout << "done" << std::endl;

    while (true) {
        int pt1, pt2;
        std::cout << "input number: ";
        std::cin >> pt1;

        Ctxt ct1 = e.encrypt(pt1); e.ea.shift(ct1, 1);

        std::cout << pt1 << " shift 1 = " << e.decrypt(ct1) << std::endl;
    }

    return 0;
}
