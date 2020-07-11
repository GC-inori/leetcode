此题的本质是找到每个柱形条左边和右边最近的比自己低的矩形条，然后用宽度乘上当前柱形条的高度作为备选答案。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {   
        heights.push_back(0); 
        const int n=heights.size();
        int q[n],tt=0,res=0;
        q[0]=0;
        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[q[tt]]) q[++tt]=i; //如果大于直接进栈 
            else
            {
                while(~tt&&heights[q[tt]]>heights[i])  
                {
                    int t=tt?q[tt-1]+1:-1; //左侧边界 右侧边界为i 
                    res=max(heights[q[tt]]*(i-t),res);
                    tt--;
                }
                q[++tt]=i;
            }
        }
        return res;
    }
};
