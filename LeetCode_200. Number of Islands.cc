class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& board)
    {
        int islands = 0;
        for (int i = 0; i < board.size(); i++) 
        {
            for (int j = 0; j < board[i].size(); j++) 
            {
                if (board[i][j] == '1') 
                {
                    islands++;
                    infect(board, i, j);
                }
            }
        }
        return islands;
    }

private:
    // 从(i,j)这个位置出发，把所有连成一片的'1'字符，变成'2'
    void infect(std::vector<std::vector<char>>& board, int i, int j)
    {
        if (i < 0 || i == board.size() || j < 0 || j == board[i].size() || board[i][j] != '1')
        {
            return;
        }

        board[i][j] = '2';//作为区分标记
        //感染上下左右4个区域
        infect(board, i - 1, j);
        infect(board, i + 1, j);
        infect(board, i, j - 1);
        infect(board, i, j + 1);
    }
};