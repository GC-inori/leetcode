�м�������5��β���м���0 ��Ϊ2�������϶���5�� ÿ��5�����Ժ�2�ճ�10 
class Solution {
public:
    int trailingZeroes(int n) 
    {
        int res=0;
        while(n)
        {
            res+=n/5;//����5 25 125������������ 
            n/=5;
        }
        return res;
    }
};
