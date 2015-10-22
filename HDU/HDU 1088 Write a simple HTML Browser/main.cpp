/*
* result:Accept
* this code is made by crazyacking
*/

/*
 Mean:
write a small html-browser. It should only display the content of the input-file and knows only the html commands (tags) <br> which is a linebreak and <hr> which is a horizontal ruler. Then you should treat all tabulators, spaces and newlines as one space and display the resulting text with no more than 80 characters on a line.
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
      string line;
      int count = 0;
      while(getline(cin,line))
      {
            stringstream stream(line);
            string word;
            while(stream>>word)
            {
                  if(word == "<br>")
                  {
                        count = 0;
                        cout<<endl;
                        continue;
                  }

                  if(word == "<hr>")
                  {
                        if(count != 0)
                              cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
                        else
                              cout<<"--------------------------------------------------------------------------------"<<endl;

                        count = 0;
                        continue;
                  }
                  if(count == 0)
                  {
                        count = word.size();
                        cout<<word;
                        continue;
                  }
                  if(count + word.size() + 1 > 80)
                  {
                        count = word.size();
                        cout<<endl<<word;
                        continue;
                  }
                  count += (word.size() + 1);
                  cout<<" "<<word;
            }

      }
      cout<<endl;


}
