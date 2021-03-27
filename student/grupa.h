//
// Created by Florii on 11/8/2020.
//

#ifndef MAIN_CPP_GRUPA_H
#define MAIN_CPP_GRUPA_H

#include <queue>
#include <string>
#include <memory>
#include <ostream>
#include "student.h"


class grupa {
    int nr_grupa{};
protected:
    std::vector<student> studenti;
//    static std::vector<std::unique_ptr< grupa>>vect_grupe;
public:

    explicit grupa(int nr_grupa1);

    grupa(const grupa &g);

    grupa();

    ~grupa() = default;

    void ordonare_nume();

    void ordonare();

    static void ordonare_an(std::vector<grupa> &vect_grupe);

    /*
    grupa(const grupa&) = delete; //dezactiveaza copierile
    grupa(grupa&&) = default;//activeaza mutarile*/ // merg impreuna cu cele din student

    friend std::istream &operator>>(std::istream &, grupa &);

    friend std::ostream &operator<<(std::ostream &os, const grupa &grupa);

    grupa& operator = (const grupa&);

};

#endif //MAIN_CPP_GRUPA_H