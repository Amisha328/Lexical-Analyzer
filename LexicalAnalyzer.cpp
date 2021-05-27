#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

string Lexeme_OPERATOR(string op){
    if(op=="=") return "EQUAL_TO";
    else if(op=="+") return "ADDITION";
    else if(op==">>") return "INSERTION";
    else if(op=="<<") return "EXTRACTION";
    else 
    return "NOT_DECLEARED_OPERATOR";
    
}
int main()
{
   
    ofstream fout;
    fout.open("Output");
    char ch;
    fstream fin("File.txt", fstream::in);
    string ans="";
    string str;
    while(fin>> noskipws>>ch){
        
        str=str+ch;
    }

    map<string,string> patterns {

        {"\\int|\\ccin+|\\ccout", " KEYWORD"},
        { "[a-z][a-z][a-z]+"," ID, pointer to symbol table"},
        { "[A-Z]+"," VAR, pointer to symbol table"},
        { "\\*|\\+|\\>>|\\<<"," OPERATOR"},
        { "\\;|\\{|\\}|\\(|\\)|\\,|\\(|\\)", " SPECIAL SYMBOLS"},
        {"[ ]","SPACE"}
             

    };

    map< size_t, pair<string,string> > matches;

    for ( auto pat = patterns.begin(); pat != patterns.end(); ++pat )
    {
        regex r(pat->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pat->second );
    }

    for ( auto match = matches.begin(); match != matches.end(); ++match ){
        if(!(match->second.first==" ") && !(match->second.second=="SPACE")){
            if(match->second.second==" OPERATOR"){

            string operaot_used= Lexeme_OPERATOR(match->second.first);
            fout<<"token ("<< match->second.first << " " <<" ,"<< match->second.second <<"  ,  "<<operaot_used<<" )" <<endl;
            }
            else
            fout<<"token ("<< match->second.first << " " <<" ,"<< match->second.second <<")" <<endl;
        }
        
    }
    return 0;
}

    
