���α���ʽ��һ���������� ��0���͵�n������ͬʱѡ
���Է��������
1.��ѡ��0�� 1-nΪ��ʽ
2.ѡ��0����ѡ��n�� 
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int res=0,a=0,b=0;
        for(int i=1,n=nums.size(),c;i<n;i++)//��ѡ��0�� 
        {
            c=a;//a��ʾ���ٵ�i�����ӵ�������� 
            a=b+nums[i];//b��ʾ�����ٵ�i�����ӵ�������� 
            b=max(c,b);
        }
        res=max(a,b);
        a=nums[0],b=0;
        for(int i=1,n=nums.size(),c;i<n;i++)//��ѡ��n�� 
        {
            c=a;
            a=b+nums[i];
            b=max(c,b);
        }
        return max(nums.size()>1?b:a,res);//��ֹֻ��һ��Ԫ�ص���� 
    }
};
