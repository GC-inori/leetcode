用l和r分别从两边遍历数组，如果l的高度小于r的高度，那么以l为边界的最大面积就是l-r围成的，面积为h[l]*(r-l) l++
否则移动r指针 每次求出以一个为边界且盛水高度为h[l]或h[r]的最大面积 
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l=0,r=height.size()-1,res=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                res=max((r-l)*height[l],res);  //左边盛水 
                l++;
            }
            else
            {
                res=max((r-l)*height[r],res); //已右边界盛水 
                r--;
            }
        }
        return res;
    }
};
