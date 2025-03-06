#pragma once
#include "../Model/RubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H

class CornerPatternDatabase : public PatternDatabase
{
    typedef RubiksCube::FACE F;
    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    // Use explicit when you want to keep your type conversions under tight control and avoid
    // any "magic" conversions that might happen without your clear intent.
    explicit CornerPatternDatabase(uint8_t init_val);
    // If you try to ignore the return value, many modern compilers will generate a warning.
    [[nodiscard]] uint32_t getDatabaseIndex(const RubiksCube& cube) const override;
};

#endif //CORNERPATTERNDATABASE_H
