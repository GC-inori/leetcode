���ϵĶ����Ʊ�ʾ
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        const int n=nums.size();
        vector<vector<int>> res;
        for(int i=0,t=1<<n;i<t;i++)
        {
            vector<int> tmp;
            for(int j=0;i>>j;j++)//ÿ������ʾһ���Ӽ�������������Ķ����Ʊ�ʾ�ĵ�jλ��1�����ʾ���Ӽ������� j�����������ʾ�������� 
            {
                if(i&(1<<j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;    
    }
};
