class Solution {
public:
    void dfs(vector<vector<int>> &res,int now,int use,int k,vector<int> &tmp)//now��n��ʼö�٣�ö�ٵ�������now use��ǰʹ�����ָ��� tmp��ǰ�� 
    {
        if(use==k)
        {
            res.push_back(tmp);
            return;
        }
        if(!now||now+use<k) return;//���ʣ�����ֲ������� 
        tmp[use]=now;//ѡ����now 
        dfs(res,now-1,use+1,k,tmp);
        dfs(res,now-1,use,k,tmp);//��ѡ����now 
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>  res;
        vector<int> tmp(k);
        dfs(res,n,0,k,tmp);
        return res;  
    }
};
