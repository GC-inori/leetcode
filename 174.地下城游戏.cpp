���ⲻ��ֱ�Ӵ�����̬�滮��ԭ���ǲ�ȷ����ʼ���ֵ�������Է��֣����յ�֮�󽡿�ֵΪ 1 һ�������ŵġ�
���Կ��Ǵ��յ㵽�����ж�̬�滮��
��״̬ f(i,j) ��ʾ�� (i, j) �ɹ������յ㣬(i, j) ����Ҫ�߱������ٽ���ֵ��
��ʼʱ��f(m-1,n-1) Ϊ max(dungeon[m-1][n-1],0)+1������Ϊ�����
ת��ʱ��f(i,j)=min(f(i+1,j),f(i,j+1))-dungeon[i][j]����� f(i,j)<=0����ʾ��·�ϵĲ���ʵ��̫���ˣ�����ʱ����ֵ����С��0�����Դ�ʱ��Ҫ����f(i,j)=1��������Ϊ 1��
���մ�Ϊ f(0,0)��
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        const int m=dungeon.size(),n=dungeon[0].size();
        int f[m][n];
        memset(f,0x3f,sizeof(f));
        for(int i=m-1;~i;i--)
            for(int j=n-1;~j;j--)
                if(i==m-1&&j==n-1) f[i][j]=max(1,1-dungeon[i][j]);
                else
                {
                    if(i<m-1) f[i][j]=f[i+1][j]-dungeon[i][j];
                    if(j<n-1) f[i][j]=min(f[i][j],f[i][j+1]-dungeon[i][j]);
                    f[i][j]=max(1,f[i][j]);
                }
        return f[0][0];
    }
};
