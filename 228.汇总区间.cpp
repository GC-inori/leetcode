class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<string> res;
        for(int i=0;i<nums.size();)
        {
            int j=i+1;
            while(j<nums.size()&&0ll+nums[j]-nums[i]==j-i) j++;
            if(j==i+1) res.push_back(to_string(nums[i]));
            else res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            i=j;
        }
        return res;
    }
};

