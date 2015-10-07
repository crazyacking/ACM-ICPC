#include<iostream>
#include<string>
using namespace std;
string a,b,c;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,t;
      cin>>n>>t;
      t=n-t;
      cin>>a>>b;
      c=a;
      for(int i=0; i<n; i++)
      {
            c[i]='a';
            while(c[i]==a[i]||c[i]==b[i])
            {
                  c[i]++;
            }
      }
      for(int i=0; i<n; i++)
      {
            if(t==0)
            {
                  break;
            }
            if(a[i]==b[i])
            {
                  c[i]=a[i];
                  t--;
            }
      }
      int ind1=0,ind2=n-1;
      while(t)
      {
            while(ind1<n&&a[ind1]==b[ind1])
            {
                  ind1++;
            }
            while(ind2>=0&&a[ind2]==b[ind2])
            {
                  ind2--;
            }
            if(ind1>=ind2)
            {
                  cout<<"-1\n";
                  return 0;
            }
            c[ind1]=a[ind1];
            ind1++;
            c[ind2]=b[ind2];
            ind2--;
            t--;
      }
      cout<<c<<"\n";
      return 0;
}
