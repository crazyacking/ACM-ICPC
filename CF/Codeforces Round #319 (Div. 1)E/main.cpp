#include <iostream>

using namespace std;

int main()
{
    vector<int> ve;
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        for(auto p : ve)
        {
            cout<<p<<endl;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
