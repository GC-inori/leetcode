������������������ͬԪ��һ�������ڵġ�
����һ��ָ�� len����ʾ�������ĩβ��Ȼ���ǰ����ɨ��ԭ���飬�����ǰ�������� nums[len] �Ҳ����� nums[len-1]��nums[k-2]���򽫵�ǰ�������������ĩβ��
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len=0;
        for(auto &c:nums)
            if(len<2||nums[len-1]!=c||nums[len-2]!=c)
                nums[len++]=c;
        return len;
    }
};
