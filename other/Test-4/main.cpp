#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

const double s_h = 719. / 120, s_m = 59. / 10, m_h = 11. / 120;
// 三根指针间的相对角速度

const double tsh = 43200. / 719, tsm = 3600. / 59, tmh = 43200. / 11;
// 将相对角速度变成周期。（即两针间需要多久出现夹角的循环）

inline double MAX( double a, double b, double c )
{
    double max = a;
    if( b > max )
        max = b;
    if( c > max )
        max = c;
    return max;
}

inline double MIN( double a, double b, double c )
{
    double min = a;
    if( b < min )
        min = b;
    if( c < min )
        min = c;
    return min;
}

int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\in.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\out.txt","w",stdout);

//      cout<<tsh<<endl;
//      cout<<tmh<<endl;
//      cout<<tsm<<endl;
    double D;
    while( scanf( "%lf", &D ), D != -1 )
    {
        double bsm, bsh, bmh, esm, esh, emh, begin, end, total = 0;
        // 计算第一次满足条件的时间
         bsm = D / s_m;
        bsh = D / s_h;
        bmh = D / m_h;
        // 计算第一次不满足条件的时间
         esm = ( 360 - D ) / s_m; // = tsm - bsm
        esh = ( 360 - D ) / s_h; // = tsh - bsh
        emh = ( 360 - D ) / m_h; // = tmh - bmh

        // 三重循环找出所有的时间总和，当然这三重循环的顺序是可以打乱的
        for( double bt3 = bsh, et3 = esh; et3 <= 43200.000001; bt3 += tsh, et3 += tsh )
        {
            for( double bt2 = bmh, et2 = emh; et2 <= 43200.000001; bt2 += tmh, et2 += tmh )
            {
                if( et2 < bt3 )  // 这是为了提前判断是否有交集
                       continue;
                if( bt2 > et3 )
                    break;
                for( double bt1 = bsm, et1 = esm; et1 <= 43200.000001; bt1 += tsm, et1 += tsm )
                {
                    if( et1 < bt2 || et1 < bt3 )
                        continue;
                    if( bt1 > et2 || bt1 > et3 )
                        break;
                    begin = MAX( bt1, bt2, bt3 ); // 取它们的交集
                       end = MIN( et1, et2, et3 );
                    total += ( end - begin )>0.?end-begin:0.;
                }
            }
        }
        cout<<"total="<<total<<endl;
//        printf( "%.3lf\n", total / 432 );
    }
}
