//
// Created by Florii on 11/8/2020.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H

#include <queue>
#include <string>
#include <memory>
#include <ostream>
#include <utility>

class student;

class situatie {
    float medie{};
    std::string nume;
public:
    situatie() = default;

    situatie(float medie, std::string nume);

    explicit situatie(std::string nume) : nume(std::move(nume)) {}

    void setMedie(float medie);

    virtual std::unique_ptr<situatie> clone() const = 0;

    virtual ~situatie() = default;

    virtual void actualizeaza_situatie(student &s) = 0;

    friend std::istream &operator>>(std::istream &, situatie &);

    friend std::ostream &operator<<(std::ostream &os, const situatie &situatie);
};

class student {
    std::string nume;
    int varsta{};
    int bani;
    std::unique_ptr<situatie> s;

    friend class grupa;

    friend class licenta;

public:
    void setBani(int bani);

    int getBani() const;


    student();

    ~student();

    friend std::istream &operator>>(std::istream &, student &);

    friend std::ostream &operator<<(std::ostream &, const student &);

    student &operator=(const student &);

    void actualizeaza_situatie(float medie);

    student(const student &student);
};

class bursa : public situatie {
public:
    bursa() : situatie("bursa") {}

    std::unique_ptr<situatie> clone() const override;

    //bursa(float medie, int bani) : situatie(medie), bani(bani) {}
    void actualizeaza_situatie(student &s) override;


};

class taxa : public situatie {
public:
    taxa() : situatie("taxa") {}

    std::unique_ptr<situatie> clone() const override;

    //taxa(float medie, int bani) : situatie(medie), bani(bani) {}
    void actualizeaza_situatie(student &s) override;
};

class buget : public situatie {
public:
    buget() : situatie("buget") {}

    std::unique_ptr<situatie> clone() const override;

    void actualizeaza_situatie(student &s) override;

};
#endif //MAIN_CPP_STUDENT_H