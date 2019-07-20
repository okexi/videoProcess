#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

wstring getName(wstring a){ //获取该视频文件的文件名
    wstring name,na;
    int pos=a.find(L'.',0);
     for(int i=pos-1;a[i]!='\\';i--){
       name.push_back(a[i]);
   }
   for(;!name.empty();){
       na.push_back(name.back());
       name.pop_back();
   }
   return na;
}
wstring quchu(wstring a){//获取去除后缀名的路径，用于添加字幕时使用
    wstring res;
    int pos=a.find(L'.',0);
    for(int i=0;i<pos;i++){
        res.push_back(a[i]);
    }
    return res;
}
int main(){
    system("chcp 936");//更改当前窗口编码方式为GBK，防止乱码
    const wstring load=L"LoadPlugin(\"D:\\Programs\\MeGUI\\tools\\ffms\\ffms2.dll\")\nLoadPlugin(\"D:\\Programs\\MeGUI\\tools\\avisynth_plugin\\VSFilter.dll\")";
    cout<<"请输入完整的视频地址：\n";
    wstring ori;
   getline(wcin,ori);
    wstring name=getName(ori);
    string name1;
    for (int i = 0; name.c_str()[i]; i++)
    {
       name1.push_back(name.c_str()[i]);//将文件名wstring转变成string类型，用于输出文件的文件名
    }
    cout<<name1<<endl;
    wofstream fout(name1+".avs");
        fout<<load<<endl;
        fout<<L"video=FFVideoSource(\""<<ori<<"\")";
        cout<<"是否更改尺寸：1-更改、不更改（默认）,请输入：";
        char isResize=0;
        cin>>isResize;
        if(isResize=='1'){
            fout<<L".LanczosResize(1280,720)";
        }
        cout<<"是否添加字幕：1-添加、不添加（默认）,请输入：";
        cin>>isResize;
        if(isResize=='1')fout<<L".TextSub(\""<<quchu(ori)<<".ass\")";
        fout<<endl;
        fout<<L"audio=FFAudioSource(\""<<ori<<"\")"<<endl;
        fout<<L"AudioDub(video,audio)"<<endl;
        cout<<"是否切割视频：1-切割、不切割（默认）,请输入：";
        cin>>isResize;
        if(isResize=='1'){
            cout<<"请分别输入起始帧和结束帧：";
            int st,en;
            cin>>st>>en;
            fout<<L"trim("<<st<<","<<en<<")"<<endl;
        }
        fout.close();
        cout<<"已经在当前目录下创建"<<name1<<".avs,编码方式为GBK\n";
        system("pause");
    return 0;
}