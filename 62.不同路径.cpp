������� �ܹ�Ҫ��n+m-2�� ����ѡm-1�������� 
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        long long res=1;
        if(m>n) swap(m,n); //��m��n�н�Сֵ��������� 
        for(int i=1,j=m+n-2;i<m;i++,j--) //����C(m+n-2,m-1); 
        {
            res=res*j/i;
        }
        return res;    
    }
};
