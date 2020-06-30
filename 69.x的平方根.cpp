二分法 
class Solution {
public:
    int mySqrt(int x) 
    {
        long long l=0,r=x,mid; //用long long防止爆int 
        while(l<r)
        {
            mid=l+r+1>>1;
            if(mid*mid>x) r=mid-1;
            else l=mid;
        }
        return l;   
    }
};
