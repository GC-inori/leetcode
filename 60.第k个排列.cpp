������λdp 
class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int cnt[10],res=0;
        bool use[10]={0};
        cnt[0]=1;
        for(int i=1;i<n;i++) cnt[i]=cnt[i-1]*i; //���ǵ�i+1λ���䣬 1~iλ�ж��������� 
        for(int i=n-1;~i;i--)
            for(int j=0;j<n;j++) //�ҵ�δʹ�ù������� 
                if(!use[j])
                {
                    if(k>cnt[i]) //�����i+1λ��j�ķ���������k�֣�Ѱ����һ��δʹ�ù������� 
                        k-=cnt[i];
                    else
                    {
                        res=res*10+j+1;  //����ʹ��j 
                        use[j]=1;
                        break;
                    }
                }
        return to_string(res);
    }
};
