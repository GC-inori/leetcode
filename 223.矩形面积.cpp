(���㼸��) O(1)
�������β�������� = �������ε������ - �������ν����������

������������н�������ô����һ���Ǿ��Σ�ʣ�µ���������������ĳ��Ϳ�

�󽻼��ĳ��Ϳ���һ��һά���⣬���������ϸ����߶� [A,B] �� [C,D]�������ǽ����ĳ��ȡ�
�佻���ĳ��ȣ�L=min(B,D)-max(A,C)��� L<0��˵�������߶β��غϡ�
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        long long s=1ll*(C-A)*(D-B)+1ll*(G-E)*(H-F);//��ֹ���ݱ�int 
        long long x=max(0ll,0ll+min(C,G)-max(A,E)),y=max(0ll,0ll+min(D,H)-max(B,F));
        return s-x*y;
    }
};
