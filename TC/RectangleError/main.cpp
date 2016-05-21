#include <bits/stdc++.h>
using namespace std;

class RectangleError
{
public:
    double bottomRange(double topMin, double topMax, double leftMin, double leftMax, double rightMin, double rightMax)
    {

        double Max = max(hypot(topMax, leftMin-rightMax) , hypot(topMax, leftMax-rightMin));

        double y;
        if(rightMin >= leftMax)
            y = rightMin - leftMax;
        else if(leftMin >= rightMax)
            y = rightMax - leftMin;
        else
            y = 0;

        double Min = hypot(topMin, y);
        return fabs(Max-Min);
    }
};

 int main()
 {
     double topMin,topMax,leftMin, leftMax, rightMin,rightMax;
     while(cin>>topMin>>topMax>>leftMin>>leftMax>>rightMin>>rightMax)
     {
         RectangleError rectangleError;
         double ans=rectangleError.bottomRange(topMin,topMax,leftMin,leftMax,rightMin,rightMax);
         printf("%.2f\n",ans);
     }
     return 0;
 }
 /*

 */
