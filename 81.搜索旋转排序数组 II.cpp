�����������33����ͬ��������������������ܰ�����ͬԪ�ء�
Ŀǰ���뵽�Ķ����������ʱ�临�Ӷȶ��� O(n)�����Ծ�����ɨ���� 
class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        for(auto &c:nums)
            if(c==target) return 1;
        return 0;
    }
};
