旋转90度等价于：
先以左上-右下对角条线为轴做翻转；aij->aji 
再以中心的竖线为轴做翻转； aji->aj(n-1-i)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()) return;
        int n=matrix.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int j=0;j<n/2;j++)
            for(int i=0;i<n;i++)
                swap(matrix[i][j],matrix[i][n-1-j]); 
    }
};
