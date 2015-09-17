#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

map<string ,set<pair<int,int>>> dic;
vector<vector<string>> doc;

#define FILE

void updatedic(string str,int doc_id,int row_id)
{
      string word;
      for(int i=0; i<str.size(); i++)
      {
            if(isalpha(str[i]))
                  str[i]=tolower(str[i]);
            else
                  str[i]=' ';
      }
      stringstream s(str);
      while(s>>word)
            dic[word].insert(pair<int,int>(doc_id,row_id));
}

void get_doc_id(set<pair<int,int>>table,set<int> &res)
{
      for(set<pair<int,int>>::iterator it=table.begin(); it!=table.end(); it++)
      {
            res.insert((*it).first);
      }
}

int main(int argc, char* argv[])
{
      int N,M;
      string str;
      while(cin>>N)
      {
            cin.get();
            int doc_id=0;
            for(int i=0; i<N; i++)
            {
                  int row_id=0;
                  while(getline(cin,str))
                  {
                        if(str=="**********")
                              break;
                        else
                        {
                              if(doc_id==doc.size())
                              {
                                    vector<string> temp;
                                    doc.push_back(temp);
                              }
                              doc[doc_id].push_back(str);
                              updatedic(str,doc_id,row_id);
                              row_id++;
                        }
                  }
                  doc_id++;
            }
            cin>>M;
            cin.get();
            for(int i=0; i<M; i++)
            {
                  getline(cin,str);
                  if(str[0]=='N')
                  {
                        string keyword = str.substr(4);
                        set<pair<int,int>>table = dic[keyword];
                        if(table.size()==doc.size())
                        {
                              cout<<"Sorry, I found nothing."<<endl<<"=========="<<endl;
                              continue;
                        }
                        map<int,int>res;
                        for(set<pair<int,int>>::iterator it=table.begin(); it!=table.end(); it++)
                        {
                              pair<int,int> val= *it;
                              res[val.first] = 1;
                        }
                        int num =0,doc_num=0 ;
                        for(int i=0; i<doc.size(); i++)
                        {
                              if(res.count(i)==0)
                              {
                                    if(num!=0)
                                    {
                                          if(doc_num!=i)
                                          {
                                                cout<<"----------"<<endl;
                                                doc_num=i;
                                          }
                                    }
                                    num++;
                                    for(int j=0; j<doc[i].size(); j++)
                                    {
                                          cout<<doc[i][j]<<endl;
                                    }
                              }
                        }
                        cout<<"=========="<<endl;
                  }
                  else if(str.find("AND")!=string::npos)
                  {
                        int p = str.find("AND");
                        string keyword1 = str.substr(0,p-1),keyword2 = str.substr(p+4);
                        set<pair<int,int>>table1 = dic[keyword1];
                        set<pair<int,int>>table2 = dic[keyword2];
                        set<pair<int,int>>res;
                        set<int> table,table1_temp,table2_temp;
                        get_doc_id(table1,table1_temp);
                        get_doc_id(table2,table2_temp);
                        set_intersection(table1_temp.begin(),table1_temp.end(),table2_temp.begin(),table2_temp.end(),inserter(table,table.begin()));
                        set_union(table1.begin(),table1.end(),table2.begin(),table2.end(),inserter(res,res.begin()));
                        if(table.size()==0)
                        {
                              cout<<"Sorry, I found nothing."<<endl<<"=========="<<endl;
                              continue;
                        }
                        int doc_num=*(table.begin()),i=0;
                        for(set<int>::iterator it=table.begin(); it!=table.end(); it++)
                        {
                              if(i!=0)
                              {
                                    if((*it)!=doc_num)
                                    {
                                          cout<<"----------"<<endl;
                                          doc_num = *it;
                                    }
                              }
                              for(int j=0; j<doc[*it].size(); j++)
                              {
                                    if(res.find(pair<int,int>(*it,j))!=res.end())
                                    {
                                          cout<<doc[*it][j]<<endl;
                                          i++;
                                    }
                              }
                        }
                        cout<<"=========="<<endl;
                  }
                  else if(str.find("OR")!=string::npos)
                  {
                        int p = str.find("OR");
                        string keyword1 = str.substr(0,p-1),keyword2 = str.substr(p+3);
                        set<pair<int,int>>table1 = dic[keyword1];
                        set<pair<int,int>>table2 = dic[keyword2];
                        set<pair<int,int>>res ;
                        set_union(table1.begin(),table1.end(),table2.begin(),table2.end(),inserter(res,res.begin()));
                        if(res.size()==0)
                        {
                              cout<<"Sorry, I found nothing."<<endl<<"=========="<<endl;
                              continue;
                        }
                        int i =0;
                        int doc_num=(*res.begin()).first;
                        for(set<pair<int,int>>::iterator it=res.begin(); it!=res.end(); it++,i++)
                        {
                              pair<int,int> val= *it;
                              if(i!=0)
                              {
                                    if(val.first!=doc_num)
                                    {
                                          cout<<"----------"<<endl;
                                          doc_num = val.first;
                                    }
                              }
                              cout<<doc[val.first][val.second]<<endl;
                        }
                        cout<<"=========="<<endl;
                  }
                  else
                  {
                        string keyword = str;
                        set<pair<int,int>>table = dic[keyword];
                        if(table.size()==0)
                        {
                              cout<<"Sorry, I found nothing."<<endl<<"=========="<<endl;
                              continue;
                        }
                        int i =0,doc_num=(*table.begin()).first;
                        for(set<pair<int,int>>::iterator it=table.begin(); it!=table.end(); it++,i++)
                        {
                              pair<int,int> val= *it;
                              if(i!=0)
                              {
                                    if(doc_num!=val.first)
                                    {
                                          cout<<"----------"<<endl;
                                          doc_num=val.first;
                                    }
                              }
                              cout<<doc[val.first][val.second]<<endl;
                        }
                        cout<<"=========="<<endl;
                  }
            }
            dic.clear();
            doc.clear();
      }
      return 0;
}
