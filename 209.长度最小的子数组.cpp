对于每个位置 i，找到尽可能小的 j，满足 [i, j] 的和大于 s。如果 j >= i，则我们更新答案 j - i + 1，这是因为此时 [i, j] 的和一定是大于等于 s 的，而且对于 i 来说 j 是满足条件中尽可能小的。
由于 j 是随着 i 增大单调不减的，故我们可以用双指针。
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int res=1e9,now=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            now+=nums[j];
            while(now>=s)
            {
                res=min(res,j-i+1);
                now-=nums[i++];
            }
            j++;
        }
        return res==1e9?0:res;
    }
};
