#pragma once
#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

template <typename T>
class IDDFSSolver
{
    int maxDepth;
    vector<RubiksCube::MOVE> moves;

public:
    T rubiksCube;
    /**
    * Constructor for the IDDFSSolver class.
    *
    * Initializes the IDDFSSolver with a given Rubik's Cube and sets the initial maximum
    * search depth for the iterative deepening depth-first search algorithm.
    *
    * @param _rubiksCube The Rubik's Cube object to solve.
    * @param _maxDepth The initial maximum search depth for the IDDFS algorithm. Default is 7.
    */
    explicit IDDFSSolver(T _rubiksCube, const int _maxDepth = 7)
    {
        rubiksCube = _rubiksCube;
        maxDepth = _maxDepth;
    }

    /**
    * Solves the Rubik's Cube using an iterative deepening depth-first search algorithm.
    *
    * The algorithm starts by performing a depth-first search with a maximum search depth of 1.
    * If the cube is not solved, then the algorithm restarts with a maximum search depth of 2.
    * This process is repeated until the cube is solved or the maximum search depth has been reached.
    *
    * @return a vector of moves performed to solve the cube
    */
    vector<RubiksCube::MOVE> solve()
    {
        for (int i = 1; i <= maxDepth; i++)
        {
            DFSSolver<T> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved())
            {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //IDDFSSOLVER_H
