暴力搜索 
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int> &nums,int pos)//pos当前处理到第几个数字 
    {
        if(pos==nums.size())
        {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[pos]);
        dfs(nums,pos+1);
        tmp.pop_back();
        pos++;
        while(pos<nums.size()&&nums[pos]==nums[pos-1]) pos++;//防止重复 
        dfs(nums,pos); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
};
