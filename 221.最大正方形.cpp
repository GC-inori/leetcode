其实这道题可以是一个动态规划问题，用f[i][j]记录以(i, j)位置为右下角所能组成的最大正方形的边长。
首先来考虑边界情况，也就是当i或j为0的情况，那么在首行或者首列中，必定有一个方向长度为1，那么就无法组成长度超过1的正方形，最多能组成长度为1的正方形，条件是当前位置为1。
而对于递推公式，对于任意一点f[i][j]，由于该点是正方形的右下角，所以该点的右边，下边，右下边都不用考虑，关心的就是左边，上边，和左上边，只有当前(i, j)位置为1，
f[i][j]才有可能大于0，否则dp[i][j]一定为0。当(i, j)位置为1，此时要看f[i-1][j-1], f[i][j-1]，和f[i-1][j]这三个位置，找其中最小的值，并加上1，就是f[i][j]的当前值了，
因为不能有0存在，所以只能取交集，最后再用f[i][j]的值来更新结果res的值即可。

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty()) return 0;
        const int m=matrix.size(),n=matrix[0].size();
        int f[m+1][n+1],res=0;
        memset(f,0,sizeof(f));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]=='1')
                {
                    f[i+1][j+1]=1+min(f[i][j],min(f[i+1][j],f[i][j+1]));
                    if(f[i+1][j+1]>res) res=f[i+1][j+1];
                }
        return res*res;
    }
};
