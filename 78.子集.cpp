集合的二进制表示
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        const int n=nums.size();
        vector<vector<int>> res;
        for(int i=0,t=1<<n;i<t;i++)
        {
            vector<int> tmp;
            for(int j=0;i>>j;j++)//每个数表示一个子集，假设这个数的二进制表示的第j位是1，则表示该子集包含第 j个数，否则表示不包含。 
            {
                if(i&(1<<j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;    
    }
};
