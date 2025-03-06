#include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(const string& _fileName)
{
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(const string& _fileName, const uint8_t init_val)
{
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore()
{
    const RubiksCubeBitboard cube;
    queue<RubiksCubeBitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty())
    {
        const unsigned n = q.size();
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++)
        {
            RubiksCubeBitboard node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++)
            {
                const auto curr_move = static_cast<RubiksCube::MOVE>(i);
                node.move(curr_move);
                if (static_cast<int>(cornerDB.getNumMoves(node)) > curr_depth)
                {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }
    cornerDB.toFile(fileName);
    return true;
}
