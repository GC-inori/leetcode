class Solution {
public:
    int m,n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void dfs(vector<vector<char>>& grid,int x,int y)//找到连通块并将其置0 
    {
        grid[x][y]='0';
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i],yy=dy[i]+y;
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&grid[xx][yy]=='1')
                dfs(grid,xx,yy);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        m=grid.size(),n=m?grid[0].size():0;
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1')
                    dfs(grid,i,j),res++;
        return res;
    }
};
