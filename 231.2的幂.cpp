class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n>0&&!(n-(n&(-n))); //n<=0 �϶����� n&(-n) �����������λ��1 ���ֻ����һ��1�Ļ����Ƕ��������� 
    }
};
