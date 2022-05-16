#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
string start_time(string str){
string word,s[3];
stringstream iss(str);
int i=0;
while(iss>>word){
    s[i]=word;
    i++;
}
return s[1];
}
string duration_time(string str){
string word,s[3];
stringstream iss(str);
int i=0;
while(iss>>word){
    s[i]=word;
    i++;
}
return s[2];
}
int main(){
ifstream in1;
ifstream in2;
string l1,l2,s1[2],s2[2];
float count=0, value=0;
in1.open("schedule.txt");
while(in1.eof()==0){
    getline(in1,l1);
    s1[0]=start_time(l1);
    s1[1]=duration_time(l1);
    if(s1[1]=="2"){
    in2.open("schedule.txt");
    while(in2.eof()==0){
        getline(in2,l2);
        s2[0]=start_time(l2);
        s2[1]=duration_time(l2);
        if((s1[0]==s2[0])&&(s2[1]=="2")){
            count=count+1;
        }
    }
    
    in2.close();
    if(count==1){
        value=value+1;
    }
    else{
        value=value+(1/count);
    }
    count=0;
    }
}
cout<<"Maximum number of times a person attended WnCC sessions are "<<value;
in1.close();
return 0;
}