class Solution {
public:
    vector<int> grayCode(int n) 
    {
        if(n==0) return {0};
        vector<int> res={0,1};
        for(int i=2;i<=n;i++)
        {
            for(int i=res.size()-1;~i;i--)
                res.push_back(res[i]);  //中心对称 前一半末尾补零 后一半末尾补1 
            for(int i=0,n=res.size();i<n;i++)
            {
                if(i<n/2) res[i]=res[i]<<1;
                else res[i]=(res[i]<<1)+1;
            }
        }
        return res;
    }
};
