class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res(rowIndex+1);
        res[0]=1;
        long long t=1;
        for(int i=rowIndex,j=1;i;i--,j++)//��������� ��Ϊ��������� 
        {
            t=t*i/j;
            res[j]=t;
        }
        return res;    
    }
};
