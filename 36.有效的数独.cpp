模拟即可 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int row[9]={0},col[9]={0},squ[9]={0};  //row[i]记录第i行出现的数字 col[i]第i列出现的数字 squ[i]第i个小方格出现的数字 
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int t=1<<(board[i][j]-'0');
                    if(row[i]&t||col[j]&t||squ[i/3*3+j/3]&t) return 0;
                    row[i]|=t;
                    col[j]|=t;
                    squ[i/3*3+j/3]|=t;
                }
            }
        return 1;    
    }
};
