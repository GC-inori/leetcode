class Solution 
{
//用unordered_map作为hash表保存元素值和在数组中的位置，从头开始遍历数组，如果存在hash表中存在target-hash[i]说明找得到了答案，否则将该数插入哈希表中
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

