#pragma once
#ifndef _MAKE_STANDARD_CODE_FILE_H_

#include "build.h"


// standart code from "..\\standard_code_file\\main.cpp"
vector<string> code_buffer;

bool is_main_func(string code_line);


/*
find the first '{' int main() function.
In order to add redirect code to main() function later.
*/
bool find_main_func(int &row,int &col)
{
    code_buffer.clear();
    ifstream fin("..\\standard_code_file\\main.cpp");
//    ofstream fout("..\\bin\\main.cpp");
    string code_line;
    
    // in order to add define information later.
    code_buffer.push_back("");
    code_buffer.push_back("");
    code_buffer.push_back("");


    while(getline(fin,code_line))
    {
        code_buffer.push_back(code_line);
    }
    fin.close();
    int code_length=code_buffer.size();
    bool f1=0,f2=0;
    for(int i=0;i<code_length;++i)
    {
        if(is_main_func(code_buffer[i]))
            f1=1;
        if(f1)
        {
            for(int j=0;j<code_buffer[i].length();++j)
            {
                if(code_buffer[i][j]=='{')
                {
                    string str=code_buffer[i].substr(0,j+1);
                    string redirect_stdin="_FREOPEN_STDIN_ ;";
                    string redirect_stdout="_FREOPEN_STDOUT_ ;";
                    str+=" ";
                    str+=redirect_stdin;
                    str+=redirect_stdout;
                    cout<<str<<endl;
                    code_buffer[i]=str;
                    cout<<code_buffer[i]<<endl;
                	row=i;;
                	col=j;
                    // string str=code_buffer[i](0,j+1);
                    // cout<<str<<endl;
                    // string redirect_stdin="";
                    // string redirect_stdout="";
                    f2=1;
                    break;
                }
            }
        }
        if(f2) break;
    }
    if(row==0 && col==0)
    {
    	puts("error : can't find main() function in standard code file, or \"..\\standard_code_file\\main.cpp\" not exist.");
    	exit(-1);
    }
    return 1;
}


/*
matching the main() function by regex
*/
bool is_main_func(string code_line)
{
    const std::regex pattern_of_main(".*(\\ +)main(\\(|\\ *).*");
    return std::regex_match(code_line,pattern_of_main);
}



#endif // _MAKE_STANDARD_CODE_FILE_H_
