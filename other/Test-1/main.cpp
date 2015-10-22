#include<cstdio>
#include<sstream>
#include<iostream>
using namespace std;
string str;
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\in.txt","r",stdin);
      freopen("C:\\Users\\crazyacking\\Desktop\\out.txt","w",stdout);

//      while(getline(cin,str))
//      {
//           stringstream stringStream(str);
           while(cin>>str)
           {
                 cout<<str<<endl;
           }
//      }
      return 0;
}
