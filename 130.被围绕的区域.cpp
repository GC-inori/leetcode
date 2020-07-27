逆向考虑问题，先统计出哪些区域不会被攻占，然后将其它区域都变成'X'即可。
具体做法如下：
开一个二维布尔数组，记录哪些区域被遍历过。
枚举所有边界上的'O'，从该位置做Flood Fill，即做深度优先遍历，只遍历是'O'的位置，并将所有遍历到的位置都标记成true。（只有和边界上的'O'相连的点才没有被包围） 
将所有未遍历到的位置变成'X'。
class Solution {
public:
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<bool>> &f)
    {
        if(board[x][y]=='X'||f[x][y]) return;
        int m=board.size(),n=board[0].size();
        f[x][y]=1;
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<m&&yy<n&&!f[xx][yy])
                dfs(xx,yy,board,f);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        if(board.empty()||board[0].empty()) return;
        const int m=board.size(),n=board[0].size();
        vector<vector<bool>> f(m,vector<bool>(n,0));
        for(int i=0;i<n;i++) dfs(0,i,board,f);//遍历四个边界上的点 
        for(int i=0;i<n;i++) dfs(m-1,i,board,f);
        for(int i=1;i<m-1;i++) dfs(i,0,board,f);
        for(int i=1;i<m-1;i++) dfs(i,n-1,board,f);
        for(int i=1;i<m-1;i++)
            for(int j=1;j<n-1;j++)
                if(board[i][j]=='O'&&!f[i][j]) board[i][j]='X';
    }
};
