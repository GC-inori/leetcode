暴力求解即可 
class Solution {
public:
    int row[9],col[9],squ[9],flag=0;
    bool dfs(vector<vector<char>>& board,int x,int y)
    {
        if(y==9) x++,y=0; //换行 
        if(x==9) return 1;  //第8行已经填完 说明发现答案 返回 
        if(board[x][y]=='.')  //如果为. 尝试使用1-9每个数字去填 
            for(int k=1;k<10;k++)
            {
                if(row[x]&(1<<k)||col[y]&(1<<k)||squ[x/3*3+y/3]&(1<<k)) continue;
                board[x][y]=k+'0';
                row[x]|=1<<k;
                col[y]|=1<<k;
                squ[x/3*3+y/3]|=1<<k;
                if(dfs(board,x,y+1)) return 1;
                row[x]-=1<<k;  //回复现场 
                col[y]-=1<<k;
                squ[x/3*3+y/3]-=1<<k;
                board[x][y]='.';
            }
        else return dfs(board,x,y+1); //不为. 遍历下一个格子 
        return 0; //目前格子填1-9均不可 返回0 
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<9;i++) row[i]=col[i]=squ[i]=0;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.')
                {
                    int t=board[i][j]-'0';
                    row[i]+=1<<t;     //预处理每行 每列 每个小方格 有那些数字 
                    col[j]+=1<<t;
                    squ[i/3*3+j/3]+=1<<t;
                }
        dfs(board,0,0);  //从0，0 开始逐行遍历每个格子   
    }
};
