#include <cstring>
#include <cstdio>
using namespace std;

char a[200020];

int main()
{
    scanf("%s", a);
    for(int i = 1; a[i]; i++)
    {
        if(a[i] == a[i-1])
            while(a[i] == a[i-1] || a[i] == a[i+1])
                a[i] = (a[i]-'a'+1)%26 + 'a';
    }
    printf("%s\n", a);
    return 0;
}
