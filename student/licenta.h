//
// Created by Florii on 11/27/2020.
//

#ifndef STUDENT_LICENTA_H
#define STUDENT_LICENTA_H

#include "grupa.h"
#include "student.h"
#include <string>


class licenta {
    std::vector<std::pair<std::string, std::vector<grupa>>> sectii;
public:

    licenta();

    ~licenta();

    void ordonare_nume();

    void ordonare_varsta();

    void ordonare_an();

    friend std::istream &operator>>(std::istream &, licenta &);

    friend std::ostream &operator<<(std::ostream &, licenta &);

    licenta &operator=(const licenta &);

};


#endif //STUDENT_LICENTA_H