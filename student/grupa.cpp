//
// Created by Florii on 11/8/2020.
//
#include <iostream>
#include <algorithm>
#include "grupa.h"

grupa::grupa(int nr_grupa1) {
    nr_grupa = nr_grupa1;
}

grupa::grupa(const grupa &g) {
    nr_grupa = g.nr_grupa;
    std::copy(g.studenti.begin(), g.studenti.end(), std::back_inserter(studenti));
}

grupa::grupa() = default;

//    vect_grupe.push_back(std::make_unique<grupa>(*this)); // aici iti copiaza sau apeleaza o referinta
/*void grupa ::citire() {
    std:: ifstream in("citire.txt");
    int n;
    in >> n; /// n = nr stud, m = nr grupe
    in >> nr_grupa;
    student st;
    for (int i = 0; i < n; ++i) {
        in >> st.nume >> st.varsta;
        studenti.push_back(st);
    }
}
*/ // am facut in istream

void grupa::ordonare() {
    std::sort(studenti.begin(), studenti.end(), [](const student &a, const student &b) { return a.varsta < b.varsta; });
    std::cout << "Afisare varstei" << '\n';
    for (auto &student : studenti) {
        std::cout << student.varsta << " " << '\n';
    }
}


void grupa::ordonare_an(std::vector<grupa> &vect_grupe) {
    std::sort(vect_grupe.begin(), vect_grupe.end(), [](auto &a, auto &b) { return a.nr_grupa < b.nr_grupa; });
    std::cout << "Afisare dupa an" << '\n';
    for (auto &nr_gr : vect_grupe) {
        std::cout << nr_gr.nr_grupa << " " << '\n';
    }
}


std::istream &operator>>(std::istream &in, grupa &gr) {
    int n;
    in >> n >> gr.nr_grupa;
    gr.studenti.clear();
    student st;
    for (int i = 0; i < n; ++i) {
        try {
            in >> st;
            gr.studenti.emplace_back(st);
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << '\n';
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &os, const grupa &grupa) {
    os << "nr_grupa: " << grupa.nr_grupa << '\n';
    os << "nr_studenti: " << grupa.studenti.size() << '\n';
    for (auto &student:grupa.studenti)
        os << student;
    return os;
}

grupa &grupa::operator=(const grupa &g) {
    if (this != &g)
        this->nr_grupa = g.nr_grupa;
    return *this;
}

void grupa::ordonare_nume() {
    std::sort(studenti.begin(), studenti.end(), [](const student &a, const student &b) { return a.nume < b.nume; });
    for (auto &student : studenti) {
        std::cout << student.nume << " " << '\n';
    }
    std::cout << '\n';
}
