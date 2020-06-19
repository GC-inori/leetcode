双指针算法
初始时l = 0, r = n - 1，lmax,rmax分别代表l指针左侧最大值，和r指针右侧最大值。如果height[l] < height[r]，说明此时阻碍当前盛水的是左侧，所以将l指针右移。
如果height[l] < height[r]
1. rmax>=lmax 显然在 height[l]可以盛水lmax-height[l];
2. rmax<lmax 那么l指针不会移动，直到 height[l] < height[r] 此时 height[l]可以盛水lmax-height[l]。（height[l]不会是最大值因为height[l] < height[r]） 
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int lmax=0,rmax=0,l=0,r=height.size()-1,res=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>lmax) lmax=height[l];
                res+=lmax-height[l++];
            }
            else
            {
                if(height[r]>rmax) rmax=height[r];
                res+=rmax-height[r--];
            }
        }
        return res;    
    }
};
