#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))

class MonstersValley2{
public:
    int minimumPrice(vector <int> dread, vector <int> price){
        return f(0, 0, dread, price);
    }

    int f(long long sum, int idx, vector <int> &dread, vector <int> &price){
        if (idx >= dread.size()) {
            return 0;
        }
        if (sum >= dread[idx]) {
            int m = min(price[idx] + f(sum + dread[idx], idx + 1, dread, price), 
                f(sum, idx + 1, dread, price));    
            return m;
        } else {
            int m = price[idx] + f(sum + dread[idx], idx + 1, dread, price);
            return m; 
        }
    }
};
