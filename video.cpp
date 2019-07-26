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
    cout<<"请输入完整的文件路径：\n";
    string origin;
    getline(cin,origin);
    string name=getName(origin);
     ofstream fout;
    fout.open(name+".avs");
        fout<<load<<endl;
        fout<<"video=FFVideoSource(\""<<origin<<"\")";
        cout<<"是否更改尺寸：1-更改、不更改（默认）,请输入：";
        char isResize=0;
        cin>>isResize;
        if(isResize=='1'){
            fout<<".LanczosResize(1280,720)";
        }
        cout<<"是否添加字幕：1-添加、不添加（默认）,请输入：";
        cin>>isResize;
        if(isResize=='1')fout<<".TextSub(\""<<quchu(origin)<<".ass\")";
        fout<<endl;
        fout<<"audio=FFAudioSource(\""<<origin<<"\")"<<endl;
        fout<<"AudioDub(video,audio)"<<endl;
        cout<<"是否切割视频：1-切割、不切割（默认）,请输入：";
        cin>>isResize;
        if(isResize=='1'){
            cout<<"请分别输入起始帧和结束帧：";
            int st,en;
            cin>>st>>en;
            fout<<"trim("<<st<<","<<en<<")"<<endl;
        }
        fout.close();
        cout<<"已经在当前目录创建"<<name<<".avs\n";
        system("pause");
    return 0;
}