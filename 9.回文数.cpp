���Ƶ�7�⣬��ת���ж��Ƿ���ȼ���
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return 0;
        long long re=0,tmp=x;
        while(x)  //re��ת������֣�tmpԭ����
        {
            re=re*10+x%10;
            x/=10;
        }
        return tmp==re;
    }
};
