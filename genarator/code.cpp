#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
int main()
{
   ofstream outdata;
    char s[100]="/home/mestu/Documents/git/MyProgramming/";
    
    int solution=0;
    cout<<"For solution writing? (0/1): ";cin>>solution;
    string Problem_Link="",Judge_Name="",Algorithm="",Problem_Name="",Solution_Link="";
    if(solution){
        cin.ignore();
        cout<<"Problem Name: ";getline(cin,Problem_Name);
        for(int i=0; i<Problem_Name.size(); i++)if(Problem_Name[i]==' ')Problem_Name[i]='_';
        cout<<"Problem link: ";cin>>Problem_Link;
        cout<<"Judge Name: ";cin>>Judge_Name;
        int s_len = strlen(s),i;
        for(i=s_len; i<s_len+Judge_Name.size(); i++)s[i]=Judge_Name[i-s_len];s[i++]='/';s_len+=Judge_Name.size()+1;
        for(i=s_len; i<s_len+Problem_Name.size(); i++)s[i]=Problem_Name[i-s_len];s[i++]='.';s[i++]='m';s[i++]='d';s[i]='\0';
        cout<<"Algorigm: ";cin>>Algorithm;
        Solution_Link = "/home/mestu/Documents/git/MyProgramming/blob/master/"+Judge_Name+"/"+Problem_Name+".md";
        outdata.open(s);
        outdata<<"<h2> Algorithm: "<<Algorithm<<"</h2>"<<endl;
        outdata<<"<h2> Problem: <a href=\""<<Problem_Link<<"\">"<<Problem_Name<<"</a></li></h3>"<<endl;
        outdata<<endl<<"```c++\n\n```"<<endl;
        outdata.close();
        cout<<"Done first part"<<endl;
    }
    cout<<"2nd part start"<<endl;
    int New=0;
    if(Problem_Name.size()==0){cin.ignore();cout<<"Problem Name: ";getline(cin,Problem_Name);
    for(int i=0; i<Problem_Name.size(); i++)if(Problem_Name[i]==' ')Problem_Name[i]='_';}
    if(Problem_Link.size()==0){cout<<"Problem link: ";cin>>Problem_Link;}
    if(Judge_Name.size()==0){cout<<"Judge Name: ";cin>>Judge_Name;}
    if(Algorithm.size()==0){cout<<"Algorigm: ";cin>>Algorithm;}
    Solution_Link = "/home/mestu/Documents/git/MyProgramming/blob/master/"+Judge_Name+"/"+Problem_Name+".md";
    cout<<"It is new judge for this algo (1/0): ";cin>>New;


    outdata.open("/home/mestu/Documents/git/MyProgramming/genarator/output.txt");
    if(!outdata.is_open()){
        cout<<"sorry error"<<endl;
        return 0;
    }
    if(New){
        outdata<<"\t<details>\n\t\t<summary>"<<Judge_Name<<"</summary>\n\t\t<ol>"<<endl;
        outdata<<"\t\t\t<li>Problem: <a href=\""<<Problem_Link<<"\">"<<Problem_Name<<"</a></li>"<<endl;
        outdata<<"\t\t\t<ul>\n\t\t\t\t<li>Solution: <a href=\""<<Solution_Link<<"</a></li>\n\t\t\t</ul>\n\t\t</ol>\n\t</details>"<<endl;
    }
    else{
        outdata<<"\t\t\t<li>Problem: <a href=\""<<Problem_Link<<"\">"<<Problem_Name<<"</a></li>"<<endl;
        outdata<<"\t\t\t<ul>\n\t\t\t\t<li>Solution: <a href=\""<<Solution_Link<<"></a>"<<Problem_Name<<"</li>\n\t\t\t</ul>\n"<<endl;
    }
    outdata.close();
    return 0;
}