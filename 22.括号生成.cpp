ֱ�����ɺϷ����������� dfs
ÿ�ο��Է��������ŵ������ǵ�ǰ�����ŵ���Ŀ������ n��
ÿ�ο��Է��������ŵ������ǵ�ǰ�����ŵ���Ŀ�����������ŵ���Ŀ��
class Solution {
public:
    int max;
    void dfs(int left,int right,string &cur,vector<string> &res) //left�������� right�������� cur��ǰ�������� res������ max���ʹ�������� 
    {
        if(left==max&&right==max)
        {
            res.push_back(cur);
            return;
        }
        if(left<max)
        {
            cur[left+right]='(';
            dfs(left+1,right,cur,res);
        }
        if(left>right)
        {
            cur[left+right]=')';
            dfs(left,right+1,cur,res);
        }

    }
    vector<string> generateParenthesis(int n) 
    {
        max=n;
        vector<string> res;
        string s(n+n,'(');
        dfs(0,0,s,res);
        return res;    
    }
};
