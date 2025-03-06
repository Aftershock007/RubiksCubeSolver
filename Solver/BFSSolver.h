#pragma once
#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

template <typename T, typename H>
class BFSSolver
{
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, RubiksCube::MOVE, H> movesDone;
    /**
     * Performs a breadth-first search on the cube to find the shortest path to the solution.
     *
     * @return a solved Rubik's Cube
     */
    T bfs()
    {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            if (node.isSolved())
            {
                return node;
            }
            for (int i = 0; i < 18; i++)
            {
                auto currMove = static_cast<RubiksCube::MOVE>(i);
                node.move(currMove);
                if (!visited[node])
                {
                    visited[node] = true;
                    movesDone[node] = currMove;
                    q.push(node);
                }
                node.invert(currMove);
            }
        }
        return rubiksCube;
    }

public:
    T rubiksCube;
    /**
     * Constructor for the BFSSolver class.
     *
     * @param _rubiksCube: The Rubik's Cube object for which we want to find a solution.
     */
    explicit BFSSolver(T _rubiksCube)
    {
        rubiksCube = _rubiksCube;
    }

    /**
     * Performs a breadth-first search on the cube to find the shortest path to the solution.
     *
     * @return a vector of moves to solve the Rubik's Cube
     */
    vector<RubiksCube::MOVE> solve()
    {
        T solvedCube = bfs();
        assert(solvedCube.isSolved());
        T currCube = solvedCube;
        while (!(currCube == rubiksCube))
        {
            RubiksCube::MOVE currMove = movesDone[currCube];
            moves.push_back(currMove);
            currCube.invert(currMove);
        }
        rubiksCube = solvedCube;
        ranges::reverse(moves);
        return moves;
    }
};

#endif //BFSSOLVER_H
