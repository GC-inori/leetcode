从下往上爬比较简单
f[i][j] 表示从底层爬到第i层第j列的最小值
f[i][j]= triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);//前者是从左边爬上来 后者是从右边爬上来 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        for(int i=n-2;~i;i--)
            for(int j=0;j<=i;j++)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        return triangle[0][0];
    }
};
