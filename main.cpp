#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/IDASTARSolver.h"

int main()
{
    RubiksCubeBitboard cube;

    const vector<RubiksCube::MOVE> shuffleMoves = cube.randomShuffleCube(5);
    cube.print();
    for (const auto move : shuffleMoves)
    {
        cout << RubiksCubeBitboard::getMove(move) << " ";
    }
    cout << endl << endl;

    const string fileName = R"(C:\Users\arijitbiswas\CLionProjects\RubiksCubeSolver\Databases\cornerDepth5V1.txt)";
    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    const vector<RubiksCube::MOVE> moves = idaStarSolver.solve();
    idaStarSolver.rubiksCube.print();
    for (const auto move : moves)
    {
        cout << RubiksCubeBitboard::getMove(move) << " ";
    }
    cout << endl;
}
