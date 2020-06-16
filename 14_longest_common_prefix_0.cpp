
bool solve(char[][] board)
{
    for (int i = 0; i < board.length; i++)
    {
        for (int j = 0; j < board[0].length; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                { //trial. Try 1 through 9
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c; //Put c for this cell

                        if (solve(board))
                            return true; //If it's the solution return true
                        else
                            board[i][j] = '.'; //Otherwise go back
                    }
                }

                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                for (char c = '1'; c <= '9'; ++c)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (helper(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}