���Ƚ��������ֽ������������� sum��sum �ض���Ϊ 0��
�ҵ� sum �����Ʊ�ʾ�²�Ϊ 0 ������һ��λ�á���ʱ�����Ը������λ���Ƿ�Ϊ 1���������е����ַ�Ϊ�����֡�ע�⵽�����������ֻ�ֱ�λ��һ�����С�
����һλΪ 0 �����ַ�Ϊһ�飬Ϊ 1 �����ַ�Ϊһ�飬�ֱ������ͣ��õ����յ��������֡�
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int s=0;
        for(auto &c:nums)
            s^=c;
        int t=s&(-s),s1=0,s2=0;
        for(auto &c:nums)
            if(c&t) s1^=c;
            else s2^=c;
        return {s1,s2};
    }
};
