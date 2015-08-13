#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m<ceil((float)n/2.0))
      cout<<m+1;
    else if(m>1)
      cout<<m-1;
    else cout<<1;
    return 0;
}
