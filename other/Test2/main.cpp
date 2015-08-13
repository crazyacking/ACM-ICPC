#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const  int maxn = 100000+50;
int js;
struct node
{
      int Next[27];//每一个节点可以扩展到的字母
      int fail; //每一个结点的失配指针
      int count;//记录每一个可以构成单词的字符串
      int pos;
      void init()//构造
      {
            memset(Next,-1,sizeof(Next));//next初始化为-1，代表不连接任何值
            fail = 0; //失配指针为空
            count = 0;//一开始没有单词，为0.
            pos=0;
      }
} s[maxn];

int sind;//记录结点的编号
char str[11111];//模版串，“单词”、
char des[111111][11111];//“文章”
int q[maxn],qin,qout;//队列

void cas_init()//在整个程序前构造root
{
      s[0].init();//初始化头结点
      sind = 1; //当前有一个结点
}

void ins(int p)//向树中插入字母
{
      int len = strlen(str);
      int i, j, ind;
      for(i = ind = 0; i < len; i++)
      {
            j = str[i]-97;//求出字母在next中的编号
            if(s[ind].Next[j]== -1)//如果不存在子节点j，则构造新的
            {
                  s[sind].init();//初始化
                  s[ind].Next[j] = sind++;//连向当前结点，并sind++代表总结点数
            }
            ind = s[ind].Next[j]; //向下走
      }
      s[ind].count++;//增加离根结点这条路径上字符串的个数，一条路上可能不止一个单词
      s[ind].pos=p;
}

void make_fail()//构造失配指针
{
      qin = qout = 0;//初始化队列
      int i,ind,ind_f;
      for(i=0; i<27; i++)
      {
            if(s[0].Next[i]!=-1)
                  q[qin++]=s[0].Next[i];//先考虑根结点，和根结点相连的都入队
      }
      while(qin!=qout)
      {
            ind = q[qout++];//记录队首结点
            for(i = 0; i < 27; i++) //遍历队首结点的Next
            {
                  if(s[ind].Next[i]!=-1)//如果结点Next不为空
                  {
                        q[qin++] = s[ind].Next[i];//将儿子节点入队
                        ind_f = s[ind].fail;//记录节点的失配指针指向
                        while(ind_f>0 && s[ind_f].Next[i]==-1)
                              /*当失配指针不为root时，一直循环直到找到一个结点是儿子是i值或者到了root*/
                              ind_f = s[ind_f].fail;
                        if(s[ind_f].Next[i]!=-1) //如果当前结点有儿子的话记录下来备用
                              ind_f = s[ind_f].Next[i];
                        s[s[ind].Next[i]].fail = ind_f; //使当前结点的失配指针指向刚才记录的结点完成失配指针的寻找构造
                  }
            }
      }
}

int fd(int ii)
{
      int ct = 0; //记录“单词的个数”
      int di,i,ind ,p; //di为指向“文章”的指针，ind为指向失配结点的指针（即trie树中失配的指针）
      int len = strlen(des[ii]);//文章的长度
      for(di = ind =0; di < len ; di++)
      {
            i = des[ii][di]-97;
            while(ind>0 && s[ind].Next[i] == -1)
                  /*当ind指针不是root和找不到结点的儿子是i时一直找下去(类似于KMP中while循环)*/
                  ind = s[ind].fail; //一直寻找失配指针
            if(s[ind].Next[i]!= -1)//找到了合适的失配指针
            {
                  ind = s[ind].Next[i]; //指向这个儿子的节点，更新ind的值进行下一次匹配
                  p = ind; //用p来临时代替ind
                  while(p>0 && s[p].count!=-1)
                        /* p>0 表示还没到root，count！=-1表示指针前还有单词*/
                  {
                        if(s[p].count>0)
                        {
                              ct+=s[p].count;//加上有的单词的个数
                        }
                        //s[p].count = -1;//不重复计算，注意这里很重要
                        p = s[p].fail;//一直寻找失配指针
                  }
            }
      }
      return ct;//返回单词个数
}


int main()
{
      int test;
      cin>>test;
      while(test--)
      {
            int n,m;
            js=0;
            scanf("%d%d",&n,&m);
            cas_init();//初始化trie树
            for(int i = 1; i<=n; i++)
                  scanf("%s",des[i]);
            for(int i=1; i<=m; i++)
            {
                  scanf("%s",str);
                  ins(i);//构造trie树
            }
            make_fail(); //构造失配指针
            for(int i = 1; i<=n; i++)
                  printf("%d\n",fd(i));
      }
      return 0;
}
