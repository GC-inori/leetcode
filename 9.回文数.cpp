类似第7题，反转后判断是否相等即可
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return 0;
        long long re=0,tmp=x;
        while(x)  //re反转后的数字，tmp原数字
        {
            re=re*10+x%10;
            x/=10;
        }
        return tmp==re;
    }
};
