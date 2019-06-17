// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

using namespace std;
int canArrangeWords(int num,char** arr){
    // WRITE YOUR CODE HERE
    vector<pair<char,char> > words;
    char** t_arr=arr;
    for(int i=0;i<num;++i)
    {
        char *now_str=(*(t_arr));
        char first_ch=now_str[0],last_ch;
        for(;(*now_str)!='\0';++now_str)
            last_ch=(*now_str);
        words.push_back(make_pair(first_ch,last_ch));
        ++t_arr;
    }

    bool vis[200];
    memset(vis,0,sizeof vis);
}
// FUNCTION SIGNATURE ENDS

// DO NOT IMPLEMENT THE main( ) METHOD