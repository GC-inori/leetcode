class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(!numRows) return {};
        vector<vector<int>> res={{1}};
        if(numRows==1) return res;
        for(int i=0;i<numRows-1;i++)
        {
            vector<int> tmp(i+2);//每行有i+2个数字 
            tmp[0]=tmp[i+1]=1;//第一个和最后一个时1 
            for(int j=1;j<i+1;j++)
                tmp[j]=res[i][j]+res[i][j-1];//中间等于上面两数之和 
            res.push_back(tmp);
        }
        return res;
    }
};
