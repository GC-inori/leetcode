��Ϊint�������������ܻ��������������Ҫ��long long��¼�м�����
��C++�У�������ȡģ�������ѧ�����ϵ�ȡģ���㲻ͬ��������Ǹ��������� ?12%10=?2���������ǲ���Ҫ�Ը������ж��⴦��
class Solution 
{
public:
    int reverse(int x) {
        long long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
    //���������long long�Ļ�
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;  //�ж��Ƿ����
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
