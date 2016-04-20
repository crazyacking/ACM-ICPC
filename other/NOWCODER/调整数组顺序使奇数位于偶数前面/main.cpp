#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   // static void swap(int a,int b){
   //     int tmp = a;
   //     a = b;
   //     b = tmp;
   // }
   // static bool isEven(int a){ // 奇数
   //     return (a%2) != 0 ? true:false;
   // }
     
     bool isEven(int a) {
        if (a & 0x1 == 1)
            return true;
        return false;
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void reOrderArray(vector<int> &array) {
        int length = array.size()-1;
        for (int i = 0; i < length; i++) {
            int j = 0;
            while (j < length) {
                if (!isEven(array[j]) && isEven(array[j+1]))
                    swap(array[j], array[j+1]);
                j++;
            }
              
        }
    }
   // void reOrderArray(vector<int> &array) {
   //     int len = array.size()-1;
    //    if(len <= 1) return;
     //     int i = 0;
     //   int j = 0;
    //    for(i = 0;i<len;i++){
     //       for(int j = 0;j<len;j++){
    //            if(!IsEven(array[j]) && IsEven(array[j+1])){
    //                swap(array[j],array[j+1]);
     //           }
     //       }
     //   }
    //}
};

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		vector<int> nums(n);
		for(int i=0;i<n;++i)
		{
			cin>>nusm[i];
		}
		Solution solution;
		solution.reOrderArray(nums);
		for(int i=0;i<n;++i)
			cout<<nums[i]<<" ";
		cout<<endl;
	}
	return 0;
}