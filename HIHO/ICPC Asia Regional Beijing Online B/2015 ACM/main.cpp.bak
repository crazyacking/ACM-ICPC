/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-20-15.09
* Time: 0MS
* Memory: 137KB
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

int up;
struct Node
{
      char ch;
      Node *fa,*son;
};

char s[10010];
char clipboard[10010];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d",&up);
            scanf("%s",s);
            int s_len=strlen(s);
            Node *head=NULL;
            Node *now=head;
            bool isInsert=true;
            bool isNothing=true;
            Node *sta;
            int lnum=0;
            int rnum=0;
            int content_len=0;
            int clipboard_len=0;
            for(int i=0; i<s_len; ++i)
            {
                  if(s[i]=='L')
                  {
                        if(now!=NULL)
                        {
                              now=now->fa;
                        }
                        if(!isNothing)
                        {
                              ++lnum;
                        }
                  }
                  else if(s[i]=='R')
                  {
                        if(now!=NULL)
                        {
                              now=now->son;
                        }
                        if(!isNothing)
                        {
                              ++rnum;
                        }
                  }
                  else if(s[i]=='S')
                  {
                        lnum=rnum=0;
                        isInsert=!isInsert;
                        isNothing=true;
                  }
                  else if(s[i]=='D')
                  {
                        if(isNothing)
                        {
                              if(now->son!=NULL)
                              {
                                    Node nson=*now->son;
                                    now->son=nson.son;
                                    (*(nson.son)).fa=now;
                              }
                        }
                        else
                        {
                              if(lnum>rnum)
                              {
                                    if(now->son!=NULL)
                                          now->son=sta->son;
                                    (*(sta->son)).fa=now;
                              }
                              else if(lnum<rnum)
                              {
                                    sta->son=now;
                                    now->fa=sta;
                              }
                              else
                              {
                                    if(now->son!=NULL)
                                    {
                                          Node nson=*now->son;
                                          now->son=nson.son;
                                          (*(nson.son)).fa=now;
                                    }
                              }
                        }
                        lnum=rnum=0;
                  }
                  else if(s[i]=='B')
                  {
                        lnum=rnum=0;
                        isNothing=true;
                        if(now->fa!=NULL)
                        {
                              Node nfa=*now->fa;
                              now->fa=nfa.fa;
                              (*(nfa.fa)).son=now;
                        }
                  }
                  else if(s[i]=='C')
                  {
                        lnum=rnum=0;
                        isNothing=false;
                        sta=now;
                  }
                  else if(s[i]=='V')
                  {
                        lnum=rnum=0;
                        isNothing=true;
                        if(content_len+clipboard_len>up || clipboard_len==0)
                              continue;
                        for(int i=0;i<clipboard_len;++i)
                        {
                              Node newNode;
                              newNode.ch=clipboard[i];
                              now->son=&newNode;
                              newNode.fa=now;
                        }
                  }
                  else
                  {
                        if(content_len+1>up)
                              continue;
                        ++content_len;

                        if(!isNothing)
                        {
                              clipboard[clipboard_len++]=s[i];
                        }
                        else clipboard_len=0;
                        lnum=rnum=0;
                        isNothing=true;
                        Node p;
                        p.ch=s[i];
                        p.fa=now;
                        if(now==NULL)
                        {
                              p.fa=now;
                              p.son=NULL;
                        }
                        else
                        {
                              p.fa=now;
                              p.son=now->son;
                        }
                  }
            }
            // output
            for(head=head->son;head->son!=NULL;head=head->son)
            {
                  printf("%c",head->ch);
            }
            puts("");
      }
      return 0;
}
/*

*/
