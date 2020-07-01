用两个变量记录第一行和第一列是否有0。
遍历整个矩阵，用矩阵的第一行和第一列记录对应的行和列是否有0。
把含有0的行和列都置成0。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        const int m=matrix.size(),n=matrix[0].size();
        bool x=1,y=1;
        for(int i=0;i<m;i++) 
            if(!matrix[i][0])
            {
                y=0;
                break;
            }
        for(int i=0;i<n;i++) 
            if(!matrix[0][i])
            {
                x=0;
                break;
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!matrix[i][j])
                    matrix[0][j]=matrix[i][0]=0;
        for(int i=1;i<m;i++)
            if(!matrix[i][0])
                for(int j=1;j<n;j++)
                    matrix[i][j]=0;
        for(int i=1;i<n;i++)
            if(!matrix[0][i])
                for(int j=1;j<m;j++)
                    matrix[j][i]=0;
        if(!x) for(int i=0;i<n;i++) matrix[0][i]=0;
        if(!y) for(int i=0;i<m;i++) matrix[i][0]=0;
    }
};
