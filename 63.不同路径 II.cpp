动态规划
如果obstacleGrid[i][j]中没有障碍物那么 f[i][j] 由 f[i-1][j] f[i][j-1] 转移来
否则 f[i][j]=0 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        const int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int f[m][n];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]) f[i][j]=0;
                else
                {
                    if(i) f[i][j]+=f[i-1][j];
                    if(j) f[i][j]+=f[i][j-1];
                }
            }
        return f[m-1][n-1];
    }
};
