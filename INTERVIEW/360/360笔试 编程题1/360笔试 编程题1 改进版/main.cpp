#include <bits/stdc++.h>
using namespace std;
const int MAXN=600010;

int a[1010];
char b[1010],s[MAXN];

int build_map(map<int,int>&mp)
{
    int res=0,len=strlen(s),j;
    for(int i=0; i<len; ++i)
    {
        if(s[i]=='.')
        {
            j=i;
            while(s[j++]=='.');
            mp.insert(make_pair(i,j-2));
            res+=(j-2-i);
            i=j-1;
        }
    }
    return res;
}

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        scanf("%s",s);
        int len=strlen(s);
        map<int,int> mp;
        int res=build_map(mp);
        for(int i=0; i<m; ++i)
        {
            scanf("%d %c",&a[i],&b[i]);
            int idx=a[i]-1;
            char ch=b[i];
            if(s[idx]==ch || (isalpha(s[idx])&&isalpha(ch))) // The same properties
            {
                s[idx]=ch;
                printf("%d\n",res);
                continue;
            }
            //
            if(ch=='.') // alpha --> point
            {
                if(!((idx-1>=0 && s[idx-1]=='.') || (idx+1<len && s[idx+1]=='.'))) // previous_pos ans next_pos are all alpha
                {
                    s[idx]=ch;
                    mp.insert(make_pair(idx,idx));
                    printf("%d\n",res);
                    continue;
                }
                //
                bool is_middle=false;
                if((idx-1>=0 && s[idx-1]=='.') && (idx+1<len && s[idx+1]=='.')) // point in the middle
                    is_middle=true;
                //There must be in a certain range
                auto iter=mp.lower_bound(idx);
                if(is_middle)
                {
                    res+=2;
                    auto it1=iter;
                    auto it2=++iter;
                    pair<int,int> new_pair(make_pair((*it1).first,(*it2).second));
                    mp.erase(it1),mp.erase(it2);
                    mp.insert(new_pair);
                }
                else
                {
                    res+=1;
                    if(!(idx==(*iter).first-1 || idx==(*iter).second+1))
                        --iter;
                    if(idx==(*iter).first-1)
                    {
                        pair<int,int> new_pair(make_pair((*iter).first-1,(*iter).second));
                        mp.erase(iter);
                        mp.insert(new_pair);
                    }
                }
            }
            else // point --> alpha
            {
                // must exist a segment,maked (sta_pos <= idx <= end_pos)
                auto iter=mp.lower_bound(idx);
                if(!((idx-1>=0 && isalpha(s[idx-1])) || (idx+1<len && isalpha(s[idx+1])))) // previous_pos and next_pos are all point
                {
                    res-=2;
                    // broken down into two segments
                    if(idx<(*iter).first)
                        --iter;
                    pair<int,int> new_pair1(make_pair((*iter).first,idx-1));
                    pair<int,int> new_pair2(make_pair(idx+1,(*iter).second));
                    mp.erase(iter);
                    mp.insert(new_pair1);
                    mp.insert(new_pair2);
                }
                //
                if(((idx-1>=0 && isalpha(s[idx-1])) || (idx+1<len && isalpha(s[idx+1])))) // there is a alpha
                {
                    res-=1;
                    if(!((*iter).first==idx+1 || (*iter).second==idx-1))
                        --iter;
                    if((*iter).first==idx+1)
                    {
                        pair<int,int> new_pair(make_pair((*iter).first-1,(*iter).second));
                        mp.erase(iter);
                        mp.insert(new_pair);
                    }
                    else
                    {
                        pair<int,int> new_pair(make_pair((*iter).first,(*iter).second+1));
                        mp.erase(iter);
                        mp.insert(new_pair);
                    }
                }
                else// previous_pos ans next_pos are all alpha
                    mp.erase(iter);
            }
            printf("%d\n",res);
            s[idx]=ch;
        }
    }
    return 0;
}
/*

*/
