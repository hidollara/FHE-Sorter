#include "encrypter.hpp"

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
