#pragma once
#include<bits/stdc++.h>
using namespace std;

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

class RubiksCube
{
public:
    enum class FACE
    {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR
    {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE
    {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // const: This qualifier indicates that the function does not modify any member variables of the class (it promises not to change the object's state).
    // = 0: This syntax makes the function a pure virtual function. It means that the function does not have an implementation in this class and must be overridden in any concrete subclass.
    /*
    * Returns the color of the cell at (row, col) in face.
    */
    [[nodiscard]] virtual COLOR getColor(FACE face, unsigned int row, unsigned int col) const = 0;
    // static: Indicates that the method belongs to the class itself rather than an instance of the class.
    /*
    * Returns the first letter of the given COLOR eg- For COLOR::GREEN, it returns 'G'
    */
    static char getColorLetter(COLOR color);
    /*
    * Returns true if the Rubik's Cube is solved, otherwise returns false.
    */
    [[nodiscard]] virtual bool isSolved() const = 0;
    /*
    * Returns the move in the string format eg- "L", "LPRIME", "L2", "D"...
    */
    static string getMove(MOVE move);
    /*
     * Print the Rubik's Cube in Planar format. The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * ri -> row numbering
     * ci -> column numbering
     * bi -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     */
    void print() const;
    /*
    * Randomly shuffle the cube with 'times' moves and returns the moves performed.
    */
    vector<MOVE> randomShuffleCube(unsigned int times);
    /*
    * Perform moves on the Rubik's Cube
    */
    RubiksCube& move(MOVE move);
    /*
    * Invert a move
    */
    RubiksCube& invert(MOVE move);
    /*
    * Rotational Moves on the Rubik's Cubes
    *
    * F, F’, F2,
    * U, U’, U2,
    * L, L’, L2,
    * D, D’, D2,
    * R, R’, R2,
    * B, B’, B2
    */
    virtual RubiksCube& F() = 0;
    virtual RubiksCube& FPrime() = 0;
    virtual RubiksCube& F2() = 0;
    virtual RubiksCube& U() = 0;
    virtual RubiksCube& UPrime() = 0;
    virtual RubiksCube& U2() = 0;
    virtual RubiksCube& L() = 0;
    virtual RubiksCube& LPrime() = 0;
    virtual RubiksCube& L2() = 0;
    virtual RubiksCube& R() = 0;
    virtual RubiksCube& RPrime() = 0;
    virtual RubiksCube& R2() = 0;
    virtual RubiksCube& D() = 0;
    virtual RubiksCube& DPrime() = 0;
    virtual RubiksCube& D2() = 0;
    virtual RubiksCube& B() = 0;
    virtual RubiksCube& BPrime() = 0;
    virtual RubiksCube& B2() = 0;

    [[nodiscard]] string getCornerColorString(uint8_t ind) const;
    [[nodiscard]] uint8_t getCornerIndex(uint8_t ind) const;
    [[nodiscard]] uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif //RUBIKSCUBE_H
