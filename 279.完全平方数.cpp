��1 �ҵ�����С��n����ȫƽ���� ��ȫ��������
2.��ѧ��
����������ƽ���Ͷ���ÿ�����������ɱ�ʾΪ4��������ƽ���͡� 
���õ���ƽ���Ͷ��� ��x=a*a+b*b+c*c ���ҽ��� n!=4^(p)*(8q+7) 
class Solution {
public:
    bool check(int x)
    {
        int r=sqrt(x);
        return r*r==x;
    }
    int numSquares(int n) 
    {
        if(check(n)) return 1;
        for(int i=1;i<=n/i;i++)
            if(check(n-i*i)) return 2;
        while(n%4==0) n/=4;
        return n%8==7?4:3;
    }
};
