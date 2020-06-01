class Solution 
{
//��unordered_map��Ϊhash����Ԫ��ֵ���������е�λ�ã���ͷ��ʼ�������飬�������hash���д���target-hash[i]˵���ҵõ��˴𰸣����򽫸��������ϣ����
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hash;
        vector<int> v;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(hash.count(target-nums[i]))
            {
                v.push_back(hash[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            hash[nums[i]]=i;
        }
        return v;
    }
};

