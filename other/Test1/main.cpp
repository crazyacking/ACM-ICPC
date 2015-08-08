#include<iostream>
using namespace std;
int fuc( int *a,int l,int r )
{
      int sum=0;
      if( l==r ) sum=a[r]>0?a[r]:0;
      else
      {
            int mid=( l+r )/2;
            int lv=fuc( a,l,mid );
            int rv=fuc( a,mid+1,r );
            int s1=0,s2=0,i,tempa;
            tempa=0;
            for( i=mid; i>=l; i-- )
            {
                  tempa=tempa+a[i];
                  s1=max(s1,tempa);
            }
            tempa=0;
            for( i=mid+1; i<=r; i++ )
            {
                  tempa=tempa+a[i];
                  s2=max(s2,tempa);
            }
            int midv=s1+s2;
            lv=max(lv,rv);
            sum=max(midv,lv);
      }
      return sum;
}
int main()
{
      int n,k,a[102],j,v;
      while( 1 )
      {
            cin>>k;
            for( j=0; j<k; j++ )
                  cin>>a[j];
            v=fuc( a,0,k-1 );
            cout<<v<<endl;
      }
      return 0;
}
