ʹ��ջ���ݽṹ��
���������ţ���Ҫѹջ��
���������ţ��ж�ջ���Ƿ�͵�ǰ������ƥ�䣻����ƥ���򷵻�false������ƥ�䵯��ջ����
����ж�ջ�Ƿ�Ϊ�գ���Ϊ����Ϸ������򲻺Ϸ���
class Solution 
{
public:
    bool isValid(string s) 
    {
        if(s.empty()) return 1;
        const int N=s.size();
        int Stack[N],t=-1;
        for(auto c:s)
        {
            if(c=='(') Stack[++t]=0;
            else if(c=='[') Stack[++t]=1;
            else if(c=='{') Stack[++t]=2;
            else
            {
                if(t<0) return 0;
                if(c==')'&&Stack[t]!=0) return 0;
                if(c==']'&&Stack[t]!=1) return 0;
                if(c=='}'&&Stack[t]!=2) return 0;
                t--;
            }
        }
        return t<0?1:0;    
    }
};
