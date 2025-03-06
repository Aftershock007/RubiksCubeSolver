#pragma once
#include <bits/stdc++.h>
using namespace std;

#ifndef NIBBLEARRAY_H
#define NIBBLEARRAY_H

class NibbleArray
{
    size_t size;
    std::vector<uint8_t> arr;

public:
    explicit NibbleArray(size_t size, uint8_t val = 0xFF);

    [[nodiscard]] uint8_t get(size_t pos) const;

    void set(size_t pos, uint8_t val);

    unsigned char* data();

    [[nodiscard]] const unsigned char* data() const;

    [[nodiscard]] size_t storageSize() const;

    void inflate(vector<uint8_t>& dest) const;

    void reset(uint8_t val = 0xFF);
};

#endif //NIBBLEARRAY_H
