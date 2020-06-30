动态规划
f[i][j] 由f[i-1][j] f[i][j-1] 中较小值转移来 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        const int m=grid.size(),n=grid[0].size();
        for(int i=0,t;i<m;i++)
            for(int j=0;j<n;j++)
            {
                t=INT_MAX;
                if(i) t=grid[i-1][j];
                if(j) t=min(grid[i][j-1],t);
                if(i||j) grid[i][j]+=t;
            }
        return grid[m-1][n-1];
    }
};
