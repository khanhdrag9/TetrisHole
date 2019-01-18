//
//  Support.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/18/19.
//

#include "Support.h"

namespace support
{
    int getRandom(int start, int end)   // [star, end]
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dist(start, end);
        
        return dist(mt);
    }
};
