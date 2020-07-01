¶þ·Ö·¨ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.empty()||matrix[0].empty()) return 0;
        const int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1,mid;
        while(l<r)
        {
            mid=l+r>>1;
            if(matrix[mid/n][mid%n]>=target) r=mid;
            else l=mid+1;
        }   
        return matrix[l/n][l%n]==target;
    }
};
