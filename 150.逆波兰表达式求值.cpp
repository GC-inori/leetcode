��������Ԫ�ء������ǰԪ������������ѹ��ջ����������������ջ������Ԫ�ص�������Ӧ���㣬�ٽ������ջ��
���ձ��ʽɨ�����ջ��������ǽ����
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for(auto &c:tokens)
        {
            if(c[0]<='9'&&c[0]>='0'||c[0]=='-'&&c.size()>1)
                s.push(stoi(c));
            else
            {
                auto t=s.top();
                s.pop();
                if(c=="+") t+=s.top();
                else if(c=="*") t*=s.top();
                else if(c=="-") t=s.top()-t;
                else t=s.top()/t;
                s.pop();
                cout<<t<<endl;
                s.push(t);
            }
        }
        return s.top();
    }
};
