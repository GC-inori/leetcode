����ı������ҵ�ÿ����������ߺ��ұ�����ı��Լ��͵ľ�������Ȼ���ÿ�ȳ��ϵ�ǰ�������ĸ߶���Ϊ��ѡ�𰸡�
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
            if(heights[i]>heights[q[tt]]) q[++tt]=i; //�������ֱ�ӽ�ջ 
            else
            {
                while(~tt&&heights[q[tt]]>heights[i])  
                {
                    int t=tt?q[tt-1]+1:-1; //���߽� �Ҳ�߽�Ϊi 
                    res=max(heights[q[tt]]*(i-t),res);
                    tt--;
                }
                q[++tt]=i;
            }
        }
        return res;
    }
};
