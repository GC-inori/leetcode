�������� 
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int> &nums,int pos)//pos��ǰ�����ڼ������� 
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
        while(pos<nums.size()&&nums[pos]==nums[pos-1]) pos++;//��ֹ�ظ� 
        dfs(nums,pos); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
};
