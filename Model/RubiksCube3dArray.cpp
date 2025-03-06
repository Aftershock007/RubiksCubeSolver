#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube
{
    /**
    * Rotates the face of the cube at the given index in a clockwise direction.
    *
    * This function performs an in-place rotation of a 3x3 face of the cube.
    * It temporarily stores the current state of the face, then updates the face
    * to reflect a 90-degree clockwise rotation.
    *
    * @param face The index of the face to rotate.
    */
    void rotateFace(const int face)
    {
        char temp[3][3] = {};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = cube[face][i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            cube[face][0][i] = temp[2 - i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[face][i][2] = temp[0][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[face][2][2 - i] = temp[i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[face][2 - i][0] = temp[2][2 - i];
        }
    }

public:
    char cube[6][3][3]{};
    /**
    * Constructor for the RubiksCube3dArray class.
    *
    * Initializes the cube faces by coloring each face with its corresponding
    * color.
    */
    RubiksCube3dArray()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[i][j][k] = getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }

    /**
     * Returns the color of the cell at (row, col) in face.
     *
     * @param face the face of the cube
     * @param row the row index of the cell
     * @param col the column index of the cell
     * @return the color of the cell
     */
    [[nodiscard]] COLOR getColor(FACE face, const unsigned int row, const unsigned int col) const override
    {
        switch (cube[static_cast<int>(face)][row][col])
        {
        case 'B': return COLOR::BLUE;
        case 'R': return COLOR::RED;
        case 'G': return COLOR::GREEN;
        case 'O': return COLOR::ORANGE;
        case 'Y': return COLOR::YELLOW;
        default: return COLOR::WHITE;
        }
    }

    /**
     * Checks if the cube is solved.
     *
     * The cube is considered solved when all the cells in each face have the
     * same color. The color of each face is determined by its corresponding
     * enum value in the COLOR enum.
     *
     * @return true if the cube is solved, false otherwise
     */
    [[nodiscard]] bool isSolved() const override
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (cube[i][j][k] != getColorLetter(static_cast<COLOR>(i)))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    /**
     * Rotate the front face of the cube clockwise.
     *
     * This function rotates the front face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, i.e. the cube is modified directly.
     * The top, left, right, and bottom faces are also modified accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& F() override
    {
        rotateFace(2);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][2][i] = cube[1][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[1][2 - i][2] = cube[5][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][0][2 - i] = cube[3][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[3][i][0] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the front face of the cube counter-clockwise.
     *
     * This function rotates the front face of the cube counter-clockwise by 90 degrees.
     * The rotation is done in-place, i.e. the cube is modified directly.
     * The top, left, right, and bottom faces are also modified accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& FPrime() override
    {
        this->F();
        this->F();
        this->F();
        return *this;
    }

    /**
     * Rotate the front face of the cube 180 degrees.
     *
     * This function performs two consecutive 90-degree clockwise rotations
     * of the front face, effectively rotating it by 180 degrees.
     * The operation is done in-place, modifying the cube directly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& F2() override
    {
        this->F();
        this->F();
        return *this;
    }

    /**
     * Rotate the upper face of the cube clockwise.
     *
     * This function rotates the upper face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, affecting the top row of the left, front,
     * right, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& U() override
    {
        rotateFace(0);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[4][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][0][2 - i] = cube[1][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[1][0][2 - i] = cube[2][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][0][2 - i] = cube[3][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[3][0][2 - i] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the upper face of the cube counter-clockwise.
     *
     * This function rotates the upper face of the cube counter-clockwise by 90 degrees.
     * The rotation is done in-place, affecting the top row of the left, front,
     * right, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& UPrime() override
    {
        this->U();
        this->U();
        this->U();
        return *this;
    }

    /**
     * Rotate the upper face of the cube 180 degrees.
     *
     * This function performs two consecutive 90-degree clockwise rotations
     * on the upper face of the cube. The rotation is done in-place,
     * affecting the top row of the left, front, right, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& U2() override
    {
        this->U();
        this->U();
        return *this;
    }

    /**
     * Rotate the left face of the cube clockwise.
     *
     * This function rotates the left face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, affecting the left column of the up, front,
     * down, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& L() override
    {
        rotateFace(1);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][i][0] = cube[4][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][2 - i][2] = cube[5][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][i][0] = cube[2][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][i][0] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the left face of the cube counter-clockwise.
     *
     * This function is the inverse of the L() function. It rotates the left face of
     * the cube counter-clockwise by 90 degrees. The rotation is done in-place,
     * affecting the left column of the up, front, down, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& LPrime() override
    {
        this->L();
        this->L();
        this->L();
        return *this;
    }

    /**
     * Rotate the left face of the cube 180 degrees.
     *
     * This function is the same as calling L() twice. It rotates the left face of
     * the cube 180 degrees. The rotation is done in-place, affecting the left column
     * of the up, front, down, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& L2() override
    {
        this->L();
        this->L();
        return *this;
    }

    /**
     * Rotate the right face of the cube clockwise.
     *
     * This function rotates the right face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, affecting the right column of the up, front,
     * down, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& R() override
    {
        rotateFace(3);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][2 - i][2] = cube[2][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][2 - i][2] = cube[5][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][2 - i][2] = cube[4][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][i][0] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the right face of the cube counter-clockwise.
     *
     * This function is the inverse of the r() function. It rotates the right face of
     * the cube counter-clockwise by 90 degrees. The rotation is done in-place,
     * affecting the right column of the up, front, down, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& RPrime() override
    {
        this->R();
        this->R();
        this->R();
        return *this;
    }

    /**
     * Rotate the right face of the cube clockwise by 180 degrees.
     *
     * This function is equivalent to calling r() twice. It rotates the right face of
     * the cube clockwise by 180 degrees, effectively flipping the colors of the
     * right column of the up, front, down, and back faces.
     *
     * @return a reference to the cube object
     */
    RubiksCube& R2() override
    {
        this->R();
        this->R();
        return *this;
    }

    /**
     * Rotate the back face of the cube clockwise.
     *
     * This function rotates the back face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, affecting the back column of the up, left,
     * down, and right faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& B() override
    {
        rotateFace(4);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][0][2 - i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][0][2 - i] = cube[3][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[3][2 - i][2] = cube[5][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][2][i] = cube[1][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[1][i][0] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the back face of the cube counter-clockwise.
     *
     * This function is the inverse of the B() function. It rotates the back face
     * of the cube counter-clockwise by 90 degrees. The rotation is done in-place,
     * affecting the back column of the up, left, down, and right faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& BPrime() override
    {
        this->B();
        this->B();
        this->B();
        return *this;
    }

    /**
     * Rotate the back face of the cube 180 degrees.
     *
     * This function is equivalent to calling B() twice. It rotates the back face of
     * the cube by 180 degrees, affecting the back column of the up, left, down, and
     * right faces. The rotation is done in-place.
     *
     * @return a reference to the cube object
     */
    RubiksCube& B2() override
    {
        this->B();
        this->B();
        return *this;
    }

    /**
     * Rotate the down face of the cube clockwise.
     *
     * This function rotates the down face of the cube clockwise by 90 degrees.
     * The rotation is done in-place, affecting the down row of the left, front,
     * right, and back faces accordingly.
     *
     * @return a reference to the cube object
     */
    RubiksCube& D() override
    {
        rotateFace(5);
        char temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[2][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][2][i] = cube[1][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[1][2][i] = cube[4][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][2][i] = cube[3][2][i];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[3][2][i] = temp[i];
        }
        return *this;
    }

    /**
     * Rotate the down face of the cube counter-clockwise.
     *
     * This function is equivalent to calling D() three times. It rotates the down
     * face of the cube counter-clockwise by 90 degrees, affecting the down row of
     * the left, front, right, and back faces accordingly.
     *
     * @return a copy of the cube object
     */
    RubiksCube& DPrime() override
    {
        this->D();
        this->D();
        this->D();
        return *this;
    }

    /**
     * Rotate the down face of the cube two times clockwise.
     *
     * This function is equivalent to calling D() two times. It rotates the down
     * face of the cube clockwise by 180 degrees, affecting the down row of the
     * left, front, right, and back faces accordingly.
     *
     * @return a copy of the cube object
     */
    RubiksCube& D2() override
    {
        this->D();
        this->D();
        return *this;
    }

    /**
     * Compares two Rubik's Cube objects for equality.
     *
     * Two cubes are considered equal if and only if the colors of their
     * corresponding cells are equal. This comparison is done in-place.
     *
     * @param rubiksCube the other cube to compare with
     * @return true if the two cubes are equal, false otherwise
     */
    bool operator==(const RubiksCube3dArray& rubiksCube) const
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (rubiksCube.cube[i][j][k] != cube[i][j][k])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    /**
    * Assigns the state of another RubiksCube3dArray to this object.
    *
    * This operator performs a deep copy of the cube's internal 3D array,
    * copying each element from the provided RubiksCube3dArray object into this
    * object's cube array. The assignment is done in-place, overwriting the
    * current state of this cube.
    *
    * @param rubiksCube the RubiksCube3dArray object to copy from
    * @return a reference to this RubiksCube3dArray object after assignment
    */
    RubiksCube3dArray& operator=(const RubiksCube3dArray& rubiksCube)
    {
        if (this == &rubiksCube) {
            return *this;
        }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[i][j][k] = rubiksCube.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d
{
    /**
     * This function is used to hash a RubiksCube3dArray object.
     *
     * The hash is calculated by concatenating the characters of the cube
     * and then using the standard string hash function.
     *
     * @param rubiksCube the RubiksCube3dArray object to be hashed
     * @return the hash value of the object
     */
    size_t operator()(const RubiksCube3dArray& rubiksCube) const
    {
        string cubeString;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cubeString += rubiksCube.cube[i][j][k];
                }
            }
        }
        return hash<string>()(cubeString);
    }
};
