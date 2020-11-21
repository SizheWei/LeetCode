// File: debug05_02.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int lines;
    cout<<"Lines = ";
    cin>>lines;
    
    string s="";
    
    cout<<"Contents:"<<endl;
    for(int i=0; i<lines; ++i){
        string temp;
        cin.getline(temp, 80, '\n');
        s = s+temp;
    }
    
    int letters=0, numbers=0, others=0, slength;
    
    slength = int(s.size());
    
    for (int i=0; i<slength; ++i) {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')) ++letters;
        else if (s[i]>='0' && s[i]<='9') ++numbers;
        else ++others;
    }
    
    cout<<"letters = "<<letters<<endl;
    cout<<"numbers = "<<numbers<<endl;
    cout<<"others = "<<others<<endl;
    return 0;
}


 

 
