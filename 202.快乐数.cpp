class Solution {
public:
    bool isHappy(int n) 
    {
        bool f[810];//int��Χ���������ĸ�λ���ֵ�ƽ����С��10��9��ƽ���ͼ�810 ������һ��bool��������������Ƿ���ֹ� 
        memset(f,0,sizeof(f));
        while(n!=1)
        {
            int t=0;
            while(n)
            {
                t+=(n%10)*(n%10);
                n/=10;
            }
            if(f[t]) return 0;//�����ظ�����ѭ�� 
            f[t]=1;
            n=t;
        }    
        return 1;
    }
};
