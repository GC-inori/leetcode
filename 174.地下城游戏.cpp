此题不能直接从正向动态规划的原因是不确定起始点的值，但可以发现，到终点之后健康值为 1 一定是最优的。
可以考虑从终点到起点进行动态规划。
设状态 f(i,j) 表示从 (i, j) 成功到达终点，(i, j) 处需要具备的最少健康值。
初始时，f(m-1,n-1) 为 max(dungeon[m-1][n-1],0)+1，其余为正无穷。
转移时，f(i,j)=min(f(i+1,j),f(i,j+1))-dungeon[i][j]，如果 f(i,j)<=0，表示道路上的补给实在太多了，但此时健康值不能小于0，所以此时需要修正f(i,j)=1，即下限为 1。
最终答案为 f(0,0)。
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        const int m=dungeon.size(),n=dungeon[0].size();
        int f[m][n];
        memset(f,0x3f,sizeof(f));
        for(int i=m-1;~i;i--)
            for(int j=n-1;~j;j--)
                if(i==m-1&&j==n-1) f[i][j]=max(1,1-dungeon[i][j]);
                else
                {
                    if(i<m-1) f[i][j]=f[i+1][j]-dungeon[i][j];
                    if(j<n-1) f[i][j]=min(f[i][j],f[i][j+1]-dungeon[i][j]);
                    f[i][j]=max(1,f[i][j]);
                }
        return f[0][0];
    }
};
