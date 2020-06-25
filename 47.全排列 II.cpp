class Solution {
public:
    int N;
    void dfs(int state,vector<int> &t,vector<vector<int>> &res,vector<int> &nums)
    {
        if(state==(1<<N)-1)
        {
            res.push_back(t);
            return;
        }
        int pre=-1e9; //��¼��һ��ѡ���Ǹ�Ԫ�� 
        for(int i=0;i<N;i++)   //ö��ѡ�ĸ�Ԫ�� 
        {
            if(state&(1<<i)||pre==nums[i]) continue;  //�����ظ��� ͬһ��λ��ѡͬһ��Ԫ�� 
            pre=nums[i]; 
            t.push_back(nums[i]);
            dfs(state+(1<<i),t,res,nums);
            t.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        N=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> t; 
        vector<vector<int>> res;
        dfs(0,t,res,nums);
        return res;    
    }
};
