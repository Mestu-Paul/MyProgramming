#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
string Cut(string s, char Current, char Replace){
    for(int i=0; i<s.size(); i++)if(s[i]==Current)s[i]=Replace;
    return s;
}
int main()
{
    ofstream outdata;
    char s[100]="G:\kali\documents\programming\git\MyProgramming";
    
    int solution=0;
    cout<<"For solution writing? (0/1): ";cin>>solution;
    string Problem_Link="",Judge_Name="",Algorithm="",Problem_Name="",Solution_Link="";
    string Sub_Algorithm;
    int depth=0;
    bool First_part=1;
    if(solution){
        First_part=0;
        cin.ignore();
        cout<<"Problem Name: ";getline(cin,Problem_Name);
        for(int i=0; i<Problem_Name.size(); i++)if(Problem_Name[i]==' ')Problem_Name[i]='_';
        cout<<"Problem link: ";cin>>Problem_Link;
        cout<<"Judge Name: ";cin>>Judge_Name;
        ///create link
        int s_len = strlen(s),i;
        for(i=s_len; i<s_len+Judge_Name.size(); i++)s[i]=Judge_Name[i-s_len];s[i++]='/';s_len+=Judge_Name.size()+1;
        for(i=s_len; i<s_len+Problem_Name.size(); i++)s[i]=Problem_Name[i-s_len];s[i++]='.';s[i++]='m';s[i++]='d';s[i]='\0';
        cin.ignore();cout<<"Algorigm: ";getline(cin,Algorithm);
        cout<<"Sub Algorithm: ";getline(cin,Sub_Algorithm);
        Solution_Link = "./"+Judge_Name+"/"+Problem_Name+".md";
        ///Create new file
        outdata.open(s);
        if(!outdata.is_open()){
            cout<<"sorry error"<<endl;
            return 0;
        }
        outdata<<"<h2> Algorithm: "<<Cut(Algorithm,'_',' ')<<"</h2>"<<endl;
        outdata<<"<h2> Problem: <a href=\""<<Problem_Link<<"\">"<<Cut(Problem_Name,'_',' ')<<"</a></h2>"<<endl;
        outdata<<endl<<"```c++\n\n```"<<endl;
        //File Close
        outdata.close();
        cout<<"Done first part"<<endl;
    }
    cout<<"2nd part start"<<endl;
    int New=0;
    if(First_part){
        cin.ignore();cout<<"Problem Name: ";getline(cin,Problem_Name);
        for(int i=0; i<Problem_Name.size(); i++)if(Problem_Name[i]==' ')Problem_Name[i]='_';
        cout<<"Problem link: ";cin>>Problem_Link;
        cout<<"Judge Name: ";cin>>Judge_Name;
        cin.ignore();cout<<"Sub Algorithm: ";getline(cin,Sub_Algorithm);
        Solution_Link = "./"+Judge_Name+"/"+Problem_Name+".md";
    }
    cout<<"It is new algo (1/0): ";cin>>New;


    outdata.open("/home/paul/Documents/programming/git/MyProgramming/genarator/output.txt");
    if(!outdata.is_open()){
        cout<<"sorry error"<<endl;
        return 0;
    }
    if(New){
        outdata<<"\t<tr>\n\t\t<td>"<<Cut(Algorithm,'_',' ')<<"</td>\n\t</tr>\n";
    }
    outdata<<"\t<tr>\n\t\t<td><a href=\""<<Problem_Link<<"\">"<<Cut(Problem_Name,'_',' ')<<"</a></td>\n";
    outdata<<"\t\t<td>"<<Judge_Name<<"</td>\n";
    outdata<<"\t\t<td>"<<Cut(Sub_Algorithm,'_',' ')<<"</td>\n";
    outdata<<"\t\t<td><a href=\""<<Solution_Link<<"\">"<<Cut(Problem_Name,'_',' ')<<"</a></td>\n";
    outdata<<"\t</tr>\n";
    outdata.close();
    return 0;
}