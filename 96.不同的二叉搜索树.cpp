��h(n)Ϊcatalan���ĵ�n+1���h(0)=1,h(1)=1��catalan���������ʽ ��
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)
����һ���֪
�������㿨�������Ĺ���
class Solution {
public:
    int numTrees(int n) 
    {
        if(n<1) return 0;
        long long res=1;
        for(int i=2*n,j=1;i>n;i--,j++)
            res=res*i/j;
        return res/(n+1);
    }
}; 
