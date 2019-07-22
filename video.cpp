#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string getName(string a){ //获取该视频文件的文件名
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
string quchu(string a){//获取去除后缀名的路径，用于添加字幕时使用
    string res;
     int pos=a.size();
     for(;a[--pos]!=L'.';){}
    for(int i=0;i<pos;i++){
        res.push_back(a[i]);
    }
    return res;
}
int main(){
   system("chcp 65001");//更改当前窗口编码方式为utf-8，保证生成的格式为utf-8
    const string load="LoadPlugin(\"D:\\Programs\\MeGUI\\tools\\ffms\\ffms2.dll\")\nLoadPlugin(\"D:\\Programs\\MeGUI\\tools\\avisynth_plugin\\VSFilter.dll\")";
    cout<<"请输入完整的视频地址：\n";
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
        cout<<"已经在当前目录下创建"<<name<<".avs,编码方式为UTF-8\n";
        system("pause");
    return 0;
}