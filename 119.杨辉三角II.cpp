class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res(rowIndex+1);
        res[0]=1;
        long long t=1;
        for(int i=rowIndex,j=1;i;i--,j++)//计算组合数 即为杨辉三角形 
        {
            t=t*i/j;
            res[j]=t;
        }
        return res;    
    }
};
