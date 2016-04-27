#include <bits/stdc++.h>
using namespace std;

class BigNumber
{
public:
	BigNumber(int x){
		while(x){
			num.append(string('0'+x%10));
			x/=10;
		}
		reverse(num.begin(),num.end());
	}
	~BigNumber(){}

	void add(BigNumber &x){
		string tmp;
		int len1=this->num.length()-1;
		int len2=x.num.length()-1;
		int carry=0;
		while(len1 && len2){
			int cur=(this.num[len1]+x.num[len2]-'0'-'0')+carry;
			tmp.append(string(cur%10+'0'));
			carry=cur/10;
			--len1,--len2;
		}
		while(len1){
			int cur=this.num[len1]-'0'+carry;
			tmp.append(string(cur%10+'0'));
			carry=cur/10;
			--len1;
		}
		while(len2){
			int cur=x.num[len2]-'0'+carry;
			tmp.append(string(cur%10+'0'));
			carry=cur/10;
			--len2;
		}
		while(carry){
			tmp.append(string(carry%10+'0'));
			carry/=10;
		}
		reverse(tmp.begin(),tmp.end());
		this.num.copy(tmp,tmp.length(),0);
	}
	void print(){
		cout<<this->num<<endl;
	}
private:
	string num;	
};

int main()
{
	BigNumber a(24);
	BigNumber b(35);
	a.add(b);
	a.print();
	return 0;
}