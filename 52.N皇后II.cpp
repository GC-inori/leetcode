����ö��
class Solution {
public:
    int cnt=0;
     void dfs(int pos,vector<int> &tmp) //tmp[i] ��ʾ�ڵ�i��tmp[j]�з����˻ʺ�  pos��ǰ����  cnt������ 
    {
        if(pos==tmp.size())
        {
            cnt++;
            return;
        }
        for(int i=0;i<tmp.size();i++)
        {
            bool f=1;
            for(int j=0;j<pos;j++)
            {
                if(tmp[j]==i||abs(tmp[j]-i)==abs(pos-j))
                {
                    f=0;
                    break;
                }
            }
            tmp[pos]=i;
            if(f) dfs(pos+1,tmp);
        }
    }
    int totalNQueens(int n) 
    {
        vector<int> tmp(n);
        cnt=0;
        dfs(0,tmp);
        return cnt;    
    }
}; 
