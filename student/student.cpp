//
// Created by Florii on 11/8/2020.
//
#include <iostream>
# include "student.h"
#include "cmake-build-debug/rlutil.h"

/////////////////////////// SITUATIE //////////////////////



void situatie::actualizeaza_situatie(student &) {
    rlutil::saveDefaultColor();
    rlutil::setColor(medie);
    std::cout << medie << " " << '\n';
    rlutil::resetColor();
}

std::istream &operator>>(std::istream &in, situatie &si) {
    in >> si.medie;
    return in;
}

std::ostream &operator<<(std::ostream &os, const situatie &situatie) {
    os << "medie: " << situatie.medie << '\n';
    os << "Studentul/ Studenta este la :" << situatie.nume << '\n';
    return os;
}

void situatie::setMedie(float medie) {
    situatie::medie = medie;
}

situatie::situatie(float medie, std::string nume) : medie(medie), nume(std::move(nume)) {}

///////////////////   STUDENT /////////////////////////

student::student(const student &student) : s(student.s->clone()) {
    nume = student.nume;
    varsta = student.varsta;
    bani = student.bani;
    //std::cout << "cc" << "\n\n\n";
}

void student::setBani(int bani) {
    student::bani = bani;
}


int student::getBani() const {
    return bani;
}


student::~student() {
    //std::cout << "Apel destructor student" << "\n\n\n\n";
    nume = " ";
}

std::istream &operator>>(std::istream &in, student &st) {
    float medie;
    in >> st.nume >> st.varsta >> medie;
    if (medie >= 9)
        st.s = std::make_unique<bursa>();
    else if (medie < 9 && medie >= 6)
        st.s = std::make_unique<buget>();
    else if (medie < 6 && medie >= 5)
        st.s = std::make_unique<taxa>();
    else
        throw std::invalid_argument("studentul este exmatriculat");
    st.actualizeaza_situatie(medie);
    return in;
}

std::ostream &operator<<(std::ostream &os, const student &st) {
    os << "nume =" << st.nume << '\n';
    os << *st.s << '\n';
    return os;
}

student::student() {
    this->bani = 10;
}

student &student::operator=(const student &st) {
    if (this != &st) {
        this->nume = st.nume;
        this->varsta = st.varsta;
        this->s = st.s->clone();
    }
    return *this;
}

void student::actualizeaza_situatie(float medie) {
    s->setMedie(medie);
    s->actualizeaza_situatie(*this);
}



////////////////////////////// BURSA////////////////////////


void bursa::actualizeaza_situatie(student &s) {
    situatie::actualizeaza_situatie(s);
    s.setBani(s.getBani() + 1);

}

std::unique_ptr<situatie> bursa::clone() const {
    return std::make_unique<bursa>(*this);
}


/////////////////////////////////   TAXA  /////////////////


void taxa::actualizeaza_situatie(student &s) {
    situatie::actualizeaza_situatie(s);
    s.setBani(s.getBani() - 1);
}

std::unique_ptr<situatie> taxa::clone() const {
    return std::make_unique<taxa>(*this);
}


//////////////////////// BUGET /////////////////////

void buget::actualizeaza_situatie(student &s) {
    situatie::actualizeaza_situatie(s);
}

std::unique_ptr<situatie> buget::clone() const {
    return std::make_unique<buget>(*this);
}


