线性扫面 每次去除一行或一列 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size()&&~j)
            if(matrix[i][j]<target) i++;
            else if(matrix[i][j]>target) j--;
            else return 1;
        return 0;
    }
};
