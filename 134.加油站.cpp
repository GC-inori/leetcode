�����ƻ����� ��need[i]��ʾi%nվ������Ҫ������ ������ʾȱ�� ������ʾ�н���
ԭ����˼����ת��Ϊ��need����һ�γ���Ϊn������ ʹ��need[k]>=0 need[k]+need[k+1]>=0 ...   need[k]+need[k+1]+...+need[k+n-1]>=0 
�ڶ���.˫ָ�� ���ߵ�������ǰ׺�Ͷ����� �˴���˫ָ�� 
��������ָ�� start �� end���ֱ��ʾ��ǰ�������㣬���������������ߵ����յ㣬tot Ϊ��ǰ������
������� tot < 0���������ߵ� end ʱ����Ҫ���������ƶ� start��ʹ�� tot ������Ҫ��ע�⵽������ƶ� start ������ʹ�� [start, end] ֮���������Ϊ���������
��� end - start + 1 == n�����ҵ���һ������·�ߡ�
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        const int n=gas.size();
        for(int i=0;i<n;i++)
            gas[i]-=cost[i];
        vector<int> need;
        for(auto &c:gas) need.push_back(c);
        for(auto &c:gas) need.push_back(c);
        int start=0,end=0,tot=0;
        while(start<n&&end<n+n)
        {
            tot+=need[end];
            while(tot<0)
            {
                tot-=need[start];
                start++;
            }
            if(end-start+1==n) return start;
            end++;
        }
        return -1;
    }
};
