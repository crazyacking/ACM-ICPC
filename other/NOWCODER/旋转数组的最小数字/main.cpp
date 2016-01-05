#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int size = rotateArray.size();
        if(size == 0)
        {
            return 0;
        }//if
        int left = 0,right = size - 1;
        int mid = 0;
        // rotateArray[left] >= rotateArray[right] ȷ����ת
        while(rotateArray[left] >= rotateArray[right])
        {
            // �ֽ��
            if(right - left == 1)
            {
                mid = right;
                break;
            }//if
            mid = left + (right - left) / 2;
            // rotateArray[left] rotateArray[right] rotateArray[mid]�������
            // �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
            // ֻ��˳�����
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            {
                return MinOrder(rotateArray,left,right);
            }//if
            // �м�Ԫ��λ��ǰ��ĵ���������
            // ��ʱ��СԪ��λ���м�Ԫ�صĺ���
            if(rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }//if
            // �м�Ԫ��λ�ں���ĵ���������
            // ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
            else
            {
                right = mid;
            }//else
        }//while
        return rotateArray[mid];
    }
private:
    // ˳��Ѱ����Сֵ
    int MinOrder(vector<int> &num,int left,int right)
    {
        int result = num[left];
        for(int i = left + 1; i < right; ++i)
        {
            if(num[i] < result)
            {
                result = num[i];
            }//if
        }//for
        return result;
    }
};

int main()
{
    Solution s;
    //vector<int> num = {0,1,2,3,4,5};
    //vector<int> num = {4,5,6,7,1,2,3};
    vector<int> num = {2,2,2,2,1,2};
    int result = s.minNumberInRotateArray(num);
    // ���
    cout<<result<<endl;
    return 0;
}
