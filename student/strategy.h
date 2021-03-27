//
// Created by Florii on 1/9/2021.
//

#ifndef STUDENT_STRATEGY_H
#define STUDENT_STRATEGY_H

#include <iostream>
#include "grupa.h"
#include "student.h"


class strategy {
public:
    // afiseaza cate grupe au cele 3 sectii
    static grupa mate();

    static grupa info();

    static grupa cti();
//   static situatie picat();
//   static situatie trecut();

    virtual ~strategy();

    virtual int aplicare();
};

class bursa_s : public strategy {
public:
    int aplicare() override {
        std::cout << "Felicitari! Ai trecut la bursa";
        return 1;
    }
};

class buget_s : public strategy {
public:
    int aplicare() override {
        std::cout << "Felicitari! Ai intrat la buget";
        return 2;
    }
};

class taxa_s : public strategy {
public:
    int aplicare() override {
        std::cout << "Ne pare rau, ai intrat la taxa!";
        return 3;
    }
};

#endif //STUDENT_STRATEGY_H
