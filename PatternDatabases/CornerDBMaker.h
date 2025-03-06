#pragma once
#include "CornerPatternDatabase.h"
#include "../Model/RubiksCubeBitboard.cpp"

#ifndef CORNERDBMAKER_H
#define CORNERDBMAKER_H

class CornerDBMaker
{
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    explicit CornerDBMaker(const string& _fileName);
    CornerDBMaker(const string& _fileName, uint8_t init_val);
    bool bfsAndStore();
};

#endif //CORNERDBMAKER_H
