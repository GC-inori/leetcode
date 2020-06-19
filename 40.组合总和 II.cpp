����ö�� 
class Solution {
public:
    void dfs(vector<vector<int>> &res,vector<int>& candidates,int now,int pos,int target,vector<int>& t) //res�����  now��������֮�� pos��ǰ�ڼ������� t��ǰ�� 
    {
        if(now==target)  //�������Ŀ��ֵ ���� 
        {
            res.push_back(t);
            return;
        }
        if(now>target||candidates.size()<=pos) return;
        t.push_back(candidates[pos]);
        dfs(res,candidates,now+candidates[pos],pos+1,target,t);  //ѡ��pos������ 
        t.pop_back();
        do pos++;while(pos<candidates.size()&&candidates[pos]==candidates[pos-1]); //�����ѡ��pos������ ������ candidates[pos]��ȵ����� �����ظ��� 
        dfs(res,candidates,now,pos,target,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(),candidates.end()); //������ ����֮������ 
        dfs(res,candidates,0,0,target,t);
        return res;
    }
};
