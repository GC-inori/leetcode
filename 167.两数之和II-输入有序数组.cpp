双指针 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i=0,j=numbers.size()-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]<target) i++;//小于目标值i移动 
            else if(numbers[i]+numbers[j]>target) j--;
            else return {i+1,j+1};
        }
        return {};
    }
};
