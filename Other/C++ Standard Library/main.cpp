///*
//* -----------------------------------------------------------------
//* Copyright (c) 2015 crazyacking All rights reserved.
//* -----------------------------------------------------------------
//*       Author: crazyacking
//*       Verdict: Accepted
//*       Submission Date: 2015-11-26-09.37
//*/
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define max(a,b) (a>b?a:b)
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//template<class T>
//inline const T& MAX(const T& a,const T& b)
//{
//	return a>b?a:b;
//}
//
//
//template<class T,class container=vector<T> >
//class MyClass
//{
//public:
//      MyClass(){}
//      ~MyClass(){}
//protected:
//private:
//};
//
//template<typename SubType>
//struct BaseType
//{
//      SubType a;
//};
//
//template <class T>
//class MyClass1
//{
//      typename T::SubType *ptr;
//      // ...
//};
//
//
//
//
//int main()
//{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
////      auto a=1.44,b=5.099;
////      cout<<MAX(a,b)<<endl;
//      MyClass<int> x1;
//      MyClass<int,vector<int> > x2;
//
//      return 0;
//}
///*
//
//*/

//
///*
//* -----------------------------------------------------------------
//* Copyright (c) 2015 crazyacking All rights reserved.
//* -----------------------------------------------------------------
//*       Author: crazyacking
//*       Verdict: Accepted
//*       Submission Date: 2015-11-26-11.02
//*/
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define max(a,b) (a>b?a:b)
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//class MyClass
//{
//      //...
//      template<class T>
//      void f(T);
//};
//
//int main()
//{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
//
//      return 0;
//}
///*
//
//*/
//
///*
//* -----------------------------------------------------------------
//* Copyright (c) 2015 crazyacking All rights reserved.
//* -----------------------------------------------------------------
//*       Author: crazyacking
//*       Verdict: Accepted
//*       Submission Date: 2015-11-26-11.21
//*/
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define max(a,b) (a>b?a:b)
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//
//template<class T>
//class MyClass
//{
//public:
//      MyClass();
//      ~MyClass();
//      void assign(const MyClass<T>& x) // x must have same type as *this
//      {
//            value=x.value;
//      }
//      // ...
//protected:
//private:
//      T value;
//};
//
//
//void fun()
//{
//      MyClass<double> d;
//      MyClass<int> i;
//
//      d.assign(d); // OK
//      d.assign(i); // ERROR: i is MyClass<int> but MyClass<double> is required
//}
//
//int main()
//{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
//
//      return 0;
//}
///*
//
//*/

//
///*
//* -----------------------------------------------------------------
//* Copyright (c) 2015 crazyacking All rights reserved.
//* -----------------------------------------------------------------
//*       Author: crazyacking
//*       Verdict: Accepted
//*       Submission Date: 2015-11-26-11.32
//*/
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define max(a,b) (a>b?a:b)
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//template<class T>
//class MyClass
//{
//public:
//      MyClass();
//      ~MyClass();
//      template<class X> // member template
//      void assign(const MyClass<X>& x) // allow different template types
//      {
//            value = x.getValu();
//      }
//      T getValue() const
//      {
//            return value;
//      }
//      // ...
//protected:
//private:
//      T value;
//};
//
//void fun()
//{
//      MyClass<double> d;
//      MyClass<int> i;
//
//      d.assign(d); // OK
//      i.assign(i); // OK (int is assigned to double)
//}
//
//int main()
//{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
//
//      return 0;
//}
///*
//
//*/


/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-26-11.32
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      return 0;
}
/*

*/