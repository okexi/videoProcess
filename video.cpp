#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;

string getName(string a){ 
    string name,na;
     int pos=a.size();
     for(;a[--pos]!=L'.';){}
     for(int i=pos-1;a[i]!='\\';i--){
       name.push_back(a[i]);
   }
   for(;!name.empty();){
       na.push_back(name.back());
       name.pop_back();
   }
   return na;
}
string quchu(string a){
    string res;
     int pos=a.size();
     for(;a[--pos]!=L'.';){}
    for(int i=0;i<pos;i++){
        res.push_back(a[i]);
    }
    return res;
}
int main(){
    const string load="LoadPlugin(\"D:\\Programs\\MeGUI\\tools\\ffms\\ffms2.dll\")\nLoadPlugin(\"D:\\Programs\\MeGUI\\tools\\avisynth_plugin\\VSFilter.dll\")";
    cout<<"�������������ļ�·����\n";
    string origin;
    getline(cin,origin);
    string name=getName(origin);
     ofstream fout;
    fout.open(name+".avs");
        fout<<load<<endl;
        fout<<"video=FFVideoSource(\""<<origin<<"\")";
        cout<<"�Ƿ���ĳߴ磺1-���ġ������ģ�Ĭ�ϣ�,�����룺";
        char isResize=0;
        cin>>isResize;
        if(isResize=='1'){
            fout<<".LanczosResize(1280,720)";
        }
        cout<<"�Ƿ������Ļ��1-��ӡ�����ӣ�Ĭ�ϣ�,�����룺";
        cin>>isResize;
        if(isResize=='1')fout<<".TextSub(\""<<quchu(origin)<<".ass\")";
        fout<<endl;
        fout<<"audio=FFAudioSource(\""<<origin<<"\")"<<endl;
        fout<<"AudioDub(video,audio)"<<endl;
        cout<<"�Ƿ��и���Ƶ��1-�и���иĬ�ϣ�,�����룺";
        cin>>isResize;
        if(isResize=='1'){
            cout<<"��ֱ�������ʼ֡�ͽ���֡��";
            int st,en;
            cin>>st>>en;
            fout<<"trim("<<st<<","<<en<<")"<<endl;
        }
        fout.close();
        cout<<"�Ѿ��ڵ�ǰĿ¼����"<<name<<".avs\n";
        system("pause");
    return 0;
}