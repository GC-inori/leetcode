��̬�滮
f[len][i][j] ��ʾs1[i~i+len-1] �� s2[j~j+len-1] �ǲ��������ַ���
class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        const int n=s1.size();
        bool f[n+1][n][n];
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                f[1][i][j]=s1[i]==s2[j];//f[1][i][j]��ʾs1[i]�Ƿ����s2[j] 
        for(int len=2;len<=n;len++) //ö���ַ������� 
            for(int l1=0;l1+len<=n;l1++) //s1��ʼλ�� 
                for(int l2=0;l2+len<=n;l2++) //s2�Ŀ�ʼλ�� 
                    for(int k=1;k<len;k++) //��s1��s2��Ϊ������ ��һ���ֳ�Ϊk �ڶ����� len-k 
                        if((f[k][l1][l2]&&f[len-k][l1+k][l2+k])|| //�������Ҫ���� 
                           (f[k][l1][l2+len-k]&&f[len-k][l1+k][l2])) //��Ҫ���������� 
                        {
                            f[len][l1][l2]=1;
                            break; //��һ�ֽ�����ʽ�����ͷ��� 
                        }
        return f[n][0][0];
    }
};
