�����������Ƚϼ�
f[i][j] ��ʾ�ӵײ�������i���j�е���Сֵ
f[i][j]= triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);//ǰ���Ǵ���������� �����Ǵ��ұ������� 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        for(int i=n-2;~i;i--)
            for(int j=0;j<=i;j++)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        return triangle[0][0];
    }
};
