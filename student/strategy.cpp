//
// Created by Florii on 1/9/2021.
//
#include "strategy.h"


grupa strategy::mate() {
    return grupa(3);
}

grupa strategy::info() {
    return grupa(4);
}

grupa strategy::cti() {
    return grupa(5);
}

int strategy::aplicare() {
    return 0;
}

strategy::~strategy() = default;
//
//situatie strategy::picat() {
//    return situatie(4.5,"Popes");
//}
//
//situatie strategy::trecut() {
//    return situatie(3,"A");}
