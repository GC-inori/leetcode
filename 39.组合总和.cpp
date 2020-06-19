class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)  //ת��Ϊ�������Ⲣ���淽�� 
    {
        vector<vector<vector<int>>> path(target+1);
        path[0]={{}};
        for(auto &c:candidates)
            for(int i=0;i<=target-c;i++)
                for(auto t:path[i])
                {
                    t.push_back(c);
                    path[i+c].push_back(t);
                }
        return path[target];
    }
    
    void dfs(vector<int>& candidates,int now,int &target,vector<vector<int>> &res,int pos,vector<int> &t) 
    {    
		if(now>target) return; //dfs�汾  now��ǰ����֮�� targetĿ�� res��  t��ǰѡ����Щ���� 
        if(now==target) 
        {
            res.push_back(t);
            return;
        }
        t.push_back(candidates[pos]);
        dfs(candidates,now+candidates[pos],target,res,pos,t);
        t.pop_back();
        if(pos+1<candidates.size())
            dfs(candidates,now,target,res,pos+1,t); //dfs�������ʱҪôѡ��Ҫô��ѡ ��ѡʱ״̬�������仯 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> t;
        dfs(candidates,0,target,res,0,t);
        return res;
    }
};
