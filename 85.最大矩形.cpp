将84.柱状图中最大的矩形问题扩展到二维。
一行一行考虑，类比 84.柱状图中最大的矩形，一行内所有柱形条的高度 h[i] 就是当前 (i, j) 位置能往上延伸的最大高度。
直接套用 84.柱状图中最大的矩形 的单调栈算法即可。
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty()) return 0;
        const int m=matrix.size(),n=matrix[0].size();
        int s[n+1],tt,res=0,h[n];
        memset(h,0,sizeof(h));
        for(int i=0;i<m;i++)
        {
            s[0]=0,tt=0;
            if(matrix[i][0]=='1') h[0]++;//如果该位置为1 类加上之前的高度 否则高度为0 
            else h[0]=0;
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
                if(h[j]>h[s[tt]]) s[++tt]=j;//如果大于栈顶元素 直接入栈 
                else
                {
                    while(~tt&&h[j]<=h[s[tt]])
                    {
                        int l=tt?s[tt-1]+1:0; //计算左边界 如果tt=0 说明之前元素都比h[j]矮 
                        res=max(res,h[s[tt]]*(j-l));//计算面积 
                        tt--;
                    }
                    s[++tt]=j;//入栈 
                }
            }
            while(~tt&&h[s[tt]]) //将剩余大于0的元素出栈 
            {
                int l=tt?s[tt-1]+1:0;
                res=max(res,h[s[tt]]*(n-l));
                tt--;
            }
        }
        return res;
    }
};
