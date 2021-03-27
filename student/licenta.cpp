//
// Created by Florii on 11/27/2020.
//

#include <iostream>
#include "licenta.h"
#include "cmake-build-debug/rlutil.h"


licenta::licenta() = default;

licenta::~licenta() {
    std::cout << "apel destructor clasa licenta" << '\n';
}


/// aceasta functie imi afiseaza studentii in ordine in fiecare sectie
void licenta::ordonare_nume() {
    for (auto &sectie : sectii) {
        std::cout << sectie.first << '\n';
        for (auto &gr : sectie.second)
            gr.ordonare_nume();
    }
}

std::istream &operator>>(std::istream &in, licenta &l) {
    int n, m;
    in >> n;
    for (int i = 0; i < n; ++i) {
        std::string sectie;
        std::vector<grupa> gr;
        in >> sectie;
        in >> m;
        for (int j = 0; j < m; ++j) {
            grupa g;
            in >> g;
            gr.push_back(g);
        }
        l.sectii.emplace_back(sectie, gr); // push_back
    }
    return in;
}

licenta &licenta::operator=(const licenta &l) {
    if (this != &l) {
        //this->sectii = l.sectii;
        std::copy(l.sectii.begin(), l.sectii.end(), std::back_inserter(this->sectii));
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, licenta &l) {
    os << "nr sectii = " << l.sectii.size() << '\n';
    for (auto &sectie : l.sectii) {
        os << sectie.first << "\n";
        for (auto &gr : sectie.second)
            os << gr << '\n';
    }
    return os;
}

void licenta::ordonare_varsta() {
    for (auto &sectie: sectii) {
        std::cout << sectie.first << '\n';
        for (auto gr: sectie.second)
            gr.ordonare();
    }
}

void licenta::ordonare_an() {
    for (auto &sectie: sectii) {
        std::cout << sectie.first << '\n';
        grupa::ordonare_an(sectie.second);
        std::cout << &rlutil::trows << "  nr liniii" << '\n';
        std::cout << &rlutil::tcols << "  nr coloane" << '\n';

    }
}