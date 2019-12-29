#include "header.hpp"
class Solution
{
public:
    bool wordSearch(vector<vector<char>> &board, int r, int c, int cur, string &word)
    {
        if (cur == word.size())
            return true;

        if (r - 1 >= 0 && board[r - 1][c] == word[cur])
        {
            board[r - 1][c] = 0;
            if (wordSearch(board, r - 1, c, cur + 1, word))
                return true;
            board[r - 1][c] = word[cur];
        }
        if (r + 1 < board.size() && board[r + 1][c] == word[cur])
        {
            board[r + 1][c] = 0;
            if (wordSearch(board, r + 1, c, cur + 1, word))
                return true;
            board[r + 1][c] = word[cur];
        }
        if (c - 1 >= 0 && board[r][c - 1] == word[cur])
        {
            board[r][c - 1] = 0;
            if (wordSearch(board, r, c - 1, cur + 1, word))
                return true;
            board[r][c - 1] = word[cur];
        }
        if (c + 1 < board[0].size() && board[r][c + 1] == word[cur])
        {
            board[r][c + 1] = 0;
            if (wordSearch(board, r, c + 1, cur + 1, word))
                return true;
            board[r][c + 1] = word[cur];
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        const int ROW = board.size();
        const int COL = board[0].size();
        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                if (board[i][j] == word[0])
                {
                    board[i][j] = 0;
                    if (wordSearch(board, i, j, 1, word))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};