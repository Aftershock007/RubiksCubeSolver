#pragma once
#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

template <typename T>
class DFSSolver
{
    vector<RubiksCube::MOVE> moves;
    int maxDepth;
    /**
    * Performs a depth-first search to attempt to solve the Rubik's Cube.
    *
    * The function recursively explores possible moves up to a maximum search
    * depth, trying to find a sequence of moves that solves the cube.
    *
    * @param depth The current depth of the search.
    * @return true if a solution is found, false otherwise.
    */
    bool dfs(const int depth)
    {
        if (rubiksCube.isSolved())
        {
            return true;
        }
        if (depth > maxDepth)
        {
            return false;
        }
        for (int i = 0; i < 18; i++)
        {
            rubiksCube.move(static_cast<RubiksCube::MOVE>(i));
            moves.push_back(static_cast<RubiksCube::MOVE>(i));
            if (dfs(depth + 1))
            {
                return true;
            }
            rubiksCube.invert(static_cast<RubiksCube::MOVE>(i));
            moves.pop_back();
        }
        return false;
    }

public:
    T rubiksCube;
    /**
     * Constructor for the DFSSolver class.
     *
     * Initializes the DFSSolver with a given Rubik's Cube and sets the maximum search depth
     * for the depth-first search algorithm.
     *
     * @param _rubiksCube The Rubik's Cube object to solve.
     * @param _maxDepth The maximum depth to search in the DFS algorithm. Default is 8.
     */
    explicit DFSSolver(T _rubiksCube, const int _maxDepth = 8)
    {
        rubiksCube = _rubiksCube;
        maxDepth = _maxDepth;
    }

    /**
     * Attempts to solve the Rubik's Cube using a depth-first search algorithm.
     *
     * The function calls the dfs function to search for a solution up to the maximum search
     * depth specified when the DFSSolver object was created. If a solution is found, the
     * function returns a vector of moves that, when applied to the cube, will solve it.
     *
     * @return A vector of moves to solve the cube, or an empty vector if no solution is found.
     */
    vector<RubiksCube::MOVE> solve()
    {
        dfs(1);
        return moves;
    }
};

#endif //DFSSOLVER_H
