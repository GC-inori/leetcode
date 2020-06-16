ģ�⼴�� 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int row[9]={0},col[9]={0},squ[9]={0};  //row[i]��¼��i�г��ֵ����� col[i]��i�г��ֵ����� squ[i]��i��С������ֵ����� 
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
