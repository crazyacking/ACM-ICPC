#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iterator>
#include <functional>
using namespace std;


string NumString(int number)
{
  stringstream c;
  c<<number;
  return c.str();
}

vector<string> tokenize(string &line, const string delims=" \t,;")
{
  vector<string> words;
  string ret="";
  int count=0;
  string::size_type begIdx, endIdx;
  begIdx=line.find_first_not_of(delims);
  while(begIdx != string::npos)
  {
    words.push_back("");
    endIdx=line.find_first_of(delims, begIdx);
    if(endIdx==string::npos)
      endIdx=line.length();
    for(int i=begIdx; i<static_cast<int>(endIdx); ++i)
    {
      words[count]+=line[i];
      ret+=line[i];
    }
    ret+=' ';
    begIdx=line.find_first_not_of(delims, endIdx);
    count++;
  }
  line=ret;
  return words;
}

string tokenize_block(string &line,const string delims=" ")
{
  for(int idx=0;idx<line.size();)
    if(line.substr(idx,delims.length())==delims)
      line.replace(idx,delims.length(), "");
    else
      ++idx;
  return line;
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////Contest Code/////////////////////////////////
///////////////////////////////////////////////////////////////////////////

struct Education
{
  int minimize(string desire, vector<int> tests)
  {
    int d;
    if(desire=="A")
      d=90;
    if(desire=="B")
      d=80;
    if(desire=="C")
      d=70;
    if(desire=="D")
      d=60;
    for(int c=0;c<=100;c++)
    {
      int f=0;
      for(int d=0;d<tests.size();d++)
        f+=tests[d];
      if((double)(f+c)/(tests.size()+1)>=d)
        return c;
    }
    return -1;
  }
};

int main()
{
    string s;
    while(cin>>s)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        {
            cin>>nums[i];
        }
        Education edu;
        int ans=edu.minimize(s,nums);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
