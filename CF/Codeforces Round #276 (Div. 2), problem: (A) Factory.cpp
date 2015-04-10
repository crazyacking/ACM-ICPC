#include <iostream>
#include <set>

using namespace std;

int main() {
    int a,m;
    set<int> s;
    while (cin>>a>>m) {
        s.clear();
        while (1) {
            if (a == 0) {
                cout<<"Yes"<<endl;
                break;
            }
            else if (s.count((a+a)%m)) {
                cout<<"No"<<endl;
                break;
            }
            else {
                a = (a+a) % m;
                s.insert(a);
            }
        }
    }
}
