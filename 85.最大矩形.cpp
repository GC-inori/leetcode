��84.��״ͼ�����ľ���������չ����ά��
һ��һ�п��ǣ���� 84.��״ͼ�����ľ��Σ�һ���������������ĸ߶� h[i] ���ǵ�ǰ (i, j) λ����������������߶ȡ�
ֱ������ 84.��״ͼ�����ľ��� �ĵ���ջ�㷨���ɡ�
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
            if(matrix[i][0]=='1') h[0]++;//�����λ��Ϊ1 �����֮ǰ�ĸ߶� ����߶�Ϊ0 
            else h[0]=0;
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
                if(h[j]>h[s[tt]]) s[++tt]=j;//�������ջ��Ԫ�� ֱ����ջ 
                else
                {
                    while(~tt&&h[j]<=h[s[tt]])
                    {
                        int l=tt?s[tt-1]+1:0; //������߽� ���tt=0 ˵��֮ǰԪ�ض���h[j]�� 
                        res=max(res,h[s[tt]]*(j-l));//������� 
                        tt--;
                    }
                    s[++tt]=j;//��ջ 
                }
            }
            while(~tt&&h[s[tt]]) //��ʣ�����0��Ԫ�س�ջ 
            {
                int l=tt?s[tt-1]+1:0;
                res=max(res,h[s[tt]]*(n-l));
                tt--;
            }
        }
        return res;
    }
};
