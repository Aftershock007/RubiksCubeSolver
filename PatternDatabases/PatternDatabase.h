#pragma once
#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"
#include "NibbleArray.h"

#ifndef PATTERNDATABASE_H
#define PATTERNDATABASE_H

class PatternDatabase
{
    NibbleArray database;
    size_t size;
    size_t numItems;

public:
    explicit PatternDatabase(size_t size);
    PatternDatabase(size_t size, uint8_t init_val);

    [[nodiscard]] virtual uint32_t getDatabaseIndex(const RubiksCube& cube) const = 0;

    virtual bool setNumMoves(const RubiksCube& cube, uint8_t numMoves);

    virtual bool setNumMoves(uint32_t ind, uint8_t numMoves);

    [[nodiscard]] virtual uint8_t getNumMoves(const RubiksCube& cube) const;

    [[nodiscard]] virtual uint8_t getNumMoves(uint32_t ind) const;

    [[nodiscard]] virtual size_t getSize() const;

    [[nodiscard]] virtual size_t getNumItems() const;

    [[nodiscard]] virtual bool isFull() const;

    virtual void toFile(const string& filePath) const;

    virtual bool fromFile(const string& filePath);

    [[nodiscard]] virtual vector<uint8_t> inflate() const;

    virtual void reset();
};

#endif //PATTERNDATABASE_H
