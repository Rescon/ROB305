//
// Created by wangyu980312 on 30/03/2022.
//

#include "Looper.h"

Looper::Looper() : doStop(false), iLoop(0) {}

Looper::~Looper() = default;

double Looper::runLoop(double nLoops) {
    while (!doStop && iLoop < nLoops)
    {
        ++iLoop;
    }
    return iLoop;
}

double Looper::getSample() const {
    return iLoop;
}

double Looper::stopLoop() {
    doStop = true;
    return iLoop;
}
