#include "RubiksCube.h"

/**
 * Returns the first letter of the given COLOR eg- For COLOR::GREEN, it returns 'G'
 *
 * @param color the color of the face
 * @return the first letter of the given COLOR
 */
char RubiksCube::getColorLetter(const COLOR color)
{
    switch (color)
    {
    case COLOR::BLUE: return 'B';
    case COLOR::GREEN: return 'G';
    case COLOR::RED: return 'R';
    case COLOR::YELLOW: return 'Y';
    case COLOR::WHITE: return 'W';
    case COLOR::ORANGE: return 'O';
    default: return '?';
    }
}

/**
 * Returns the move in the string format eg- "L", "LPRIME", "L2", "D"...
 *
 * @param move the move to be converted to string
 * @return the move in the string format
 */
string RubiksCube::getMove(const MOVE move)
{
    switch (move)
    {
    case MOVE::L: return "L";
    case MOVE::LPRIME: return "L'";
    case MOVE::L2: return "L2";
    case MOVE::R: return "R";
    case MOVE::RPRIME: return "R'";
    case MOVE::R2: return "R2";
    case MOVE::U: return "U";
    case MOVE::UPRIME: return "U'";
    case MOVE::U2: return "U2";
    case MOVE::D: return "D";
    case MOVE::DPRIME: return "D'";
    case MOVE::D2: return "D2";
    case MOVE::F: return "F";
    case MOVE::FPRIME: return "F'";
    case MOVE::F2: return "F2";
    case MOVE::B: return "B";
    case MOVE::BPRIME: return "B'";
    case MOVE::B2: return "B2";
    default: return "?";
    }
}

/**
 * Applies a single move to the cube.
 *
 * @param move the move to apply
 * @return a reference to the cube, after the move has been applied
 */
RubiksCube& RubiksCube::move(const MOVE move)
{
    switch (move)
    {
    case MOVE::L: return this->L();
    case MOVE::LPRIME: return this->LPrime();
    case MOVE::L2: return this->L2();
    case MOVE::R: return this->R();
    case MOVE::RPRIME: return this->RPrime();
    case MOVE::R2: return this->R2();
    case MOVE::U: return this->U();
    case MOVE::UPRIME: return this->UPrime();
    case MOVE::U2: return this->U2();
    case MOVE::D: return this->D();
    case MOVE::DPRIME: return this->DPrime();
    case MOVE::D2: return this->D2();
    case MOVE::F: return this->F();
    case MOVE::FPRIME: return this->FPrime();
    case MOVE::F2: return this->F2();
    case MOVE::B: return this->B();
    case MOVE::BPRIME: return this->BPrime();
    case MOVE::B2: return this->B2();
    default: throw std::invalid_argument("Invalid move passed to move() method");
    }
}

/**
 * Returns the inverse of the given RubiksCube move.
 *
 * The inverse of a move is the move that can be performed to undo the
 * effects of the original move. For example, the inverse of the move
 * L is LPRIME, the inverse of U is UPRIME, and so on.
 *
 * @param move the move to be inverted
 * @return the inverse of the given move
 */
RubiksCube& RubiksCube::invert(const MOVE move)
{
    switch (move)
    {
    case MOVE::L: return this->LPrime();
    case MOVE::LPRIME: return this->L();
    case MOVE::L2: return this->L2();
    case MOVE::R: return this->RPrime();
    case MOVE::RPRIME: return this->R();
    case MOVE::R2: return this->R2();
    case MOVE::U: return this->UPrime();
    case MOVE::UPRIME: return this->U();
    case MOVE::U2: return this->U2();
    case MOVE::D: return this->DPrime();
    case MOVE::DPRIME: return this->D();
    case MOVE::D2: return this->D2();
    case MOVE::F: return this->FPrime();
    case MOVE::FPRIME: return this->F();
    case MOVE::F2: return this->F2();
    case MOVE::B: return this->BPrime();
    case MOVE::BPRIME: return this->B();
    case MOVE::B2: return this->B2();
    default: throw std::invalid_argument("Invalid move passed to invert() method");
    }
}

/**
 * Prints the current state of the Rubik's Cube in a planar format.
 *
 * The cube is represented as a 3x3 grid for each face, where each cell displays
 * the first letter of the color of that part of the face. The UP face is printed
 * first, followed by the LEFT, FRONT, RIGHT, and BACK faces printed in a row,
 * and finally the DOWN face is printed. Each face is separated by spaces to
 * visually distinguish them.
 */
void RubiksCube::print() const
{
    cout << "Rubik's Cube:\n\n";
    // Print the UP face.
    for (int i = 0; i < 3; i++)
    {
        cout << string(7, ' ');
        for (int j = 0; j < 3; j++)
        {
            cout << getColorLetter(getColor(FACE::UP, i, j)) << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Print LEFT, FRONT, RIGHT, BACK faces in a row.
    for (int i = 0; i < 3; i++)
    {
        for (int face = 0; face < 4; face++)
        {
            FACE currentFace;
            switch (face)
            {
            case 0: currentFace = FACE::LEFT;
                break;
            case 1: currentFace = FACE::FRONT;
                break;
            case 2: currentFace = FACE::RIGHT;
                break;
            case 3: currentFace = FACE::BACK;
                break;
            default: currentFace = {};
            }
            for (int j = 0; j < 3; j++)
            {
                cout << getColorLetter(getColor(currentFace, i, j)) << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Print the DOWN face.
    for (int i = 0; i < 3; i++)
    {
        cout << string(7, ' ');
        for (int j = 0; j < 3; j++)
        {
            cout << getColorLetter(getColor(FACE::DOWN, i, j)) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Randomly shuffles the Rubik's Cube a specified number of times.
 *
 * @param times the number of times to shuffle the cube
 * @return a vector of moves performed to shuffle the cube
 */
vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(const unsigned int times)
{
    vector<MOVE> performedMoves;
    srand(time(nullptr));
    for (unsigned i = 0; i < times; i++)
    {
        auto currentMove = static_cast<MOVE>(rand() % 18);
        performedMoves.push_back(currentMove);
        this->move(currentMove);
    }
    return performedMoves;
}

/**
 * Returns the color string of the given corner index.
 *
 * The indices are assigned as follows:
 * 0 - UFR
 * 1 - UFL
 * 2 - UBL
 * 3 - UBR
 * 4 - DFR
 * 5 - DFL
 * 6 - DBR
 * 7 - DBL
 *
 * @param ind the index of the corner
 * @return a string of the colors of the corner in the order U, F, R
 */
string RubiksCube::getCornerColorString(const uint8_t ind) const
{
    string cornerColorString;
    switch (ind)
    {
    // UFR
    case 0:
        cornerColorString += getColorLetter(getColor(FACE::UP, 2, 2));
        cornerColorString += getColorLetter(getColor(FACE::FRONT, 0, 2));
        cornerColorString += getColorLetter(getColor(FACE::RIGHT, 0, 0));
        break;
    // UFL
    case 1:
        cornerColorString += getColorLetter(getColor(FACE::UP, 2, 0));
        cornerColorString += getColorLetter(getColor(FACE::FRONT, 0, 0));
        cornerColorString += getColorLetter(getColor(FACE::LEFT, 0, 2));
        break;
    // UBL
    case 2:
        cornerColorString += getColorLetter(getColor(FACE::UP, 0, 0));
        cornerColorString += getColorLetter(getColor(FACE::BACK, 0, 2));
        cornerColorString += getColorLetter(getColor(FACE::LEFT, 0, 0));
        break;
    // UBR
    case 3:
        cornerColorString += getColorLetter(getColor(FACE::UP, 0, 2));
        cornerColorString += getColorLetter(getColor(FACE::BACK, 0, 0));
        cornerColorString += getColorLetter(getColor(FACE::RIGHT, 0, 2));
        break;
    // DFR
    case 4:
        cornerColorString += getColorLetter(getColor(FACE::DOWN, 0, 2));
        cornerColorString += getColorLetter(getColor(FACE::FRONT, 2, 2));
        cornerColorString += getColorLetter(getColor(FACE::RIGHT, 2, 0));
        break;
    // DFL
    case 5:
        cornerColorString += getColorLetter(getColor(FACE::DOWN, 0, 0));
        cornerColorString += getColorLetter(getColor(FACE::FRONT, 2, 0));
        cornerColorString += getColorLetter(getColor(FACE::LEFT, 2, 2));
        break;
    // DBR
    case 6:
        cornerColorString += getColorLetter(getColor(FACE::DOWN, 2, 2));
        cornerColorString += getColorLetter(getColor(FACE::BACK, 2, 0));
        cornerColorString += getColorLetter(getColor(FACE::RIGHT, 2, 2));
        break;
    // DBL
    case 7:
        cornerColorString += getColorLetter(getColor(FACE::DOWN, 2, 0));
        cornerColorString += getColorLetter(getColor(FACE::BACK, 2, 2));
        cornerColorString += getColorLetter(getColor(FACE::LEFT, 2, 0));
        break;
    default:
        cornerColorString = "";
        break;
    }
    return cornerColorString;
}

/**
 * Returns a binary representation of the corner at index ind.
 *
 * The representation is done as follows:
 * The 3rd bit represents the color Yellow/White
 * The 2nd bit represents the color Orange/Red
 * The 1st bit represents the color Green/Blue
 *
 * @param ind the index of the corner
 * @return a binary representation of the corner
 */
uint8_t RubiksCube::getCornerIndex(const uint8_t ind) const
{
    const string cornerColorString = getCornerColorString(ind);
    uint8_t binaryCorner = 0;
    for (const char c : cornerColorString)
    {
        if (c == 'Y')
        {
            binaryCorner |= (1 << 2);
        }
        else if (c == 'O')
        {
            binaryCorner |= (1 << 1);
        }
        else if (c == 'G')
        {
            binaryCorner |= (1 << 0);
        }
    }
    return binaryCorner;
}

/**
 * Returns the orientation of the corner at index ind.
 *
 * The orientation is represented as the number of clockwise rotations
 * of the corner's yellow sticker relative to the UP face.
 *
 * @param ind the index of the corner
 * @return the orientation of the corner
 */
uint8_t RubiksCube::getCornerOrientation(const uint8_t ind) const
{
    const string cornerColorString = getCornerColorString(ind);
    string upFaceColors;
    // Extract the UP face colors (W or Y).
    for (const char c : cornerColorString)
    {
        if (c == 'W' || c == 'Y')
        {
            upFaceColors.push_back(c);
        }
    }
    if (cornerColorString[1] == upFaceColors[0])
        return 1;
    if (cornerColorString[2] == upFaceColors[0])
        return 2;
    return 0;
}
