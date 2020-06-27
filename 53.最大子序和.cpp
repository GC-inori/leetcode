¶¯Ì¬¹æ»® 
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res=INT_MIN,pre=0;
        for(auto c:nums)
        {
            if(pre>0)
                pre+=c;
            else
                pre=c;
            res=max(res,pre);
        }
        return res;    
    }
};
