#include <iostream>
#include <fstream>
#include <stdio.h>
#include <direct.h>
#include <string>
using namespace std;

string getName(string a)
{
    return a.substr(a.find_last_of('\\') + 1);
}
string quchu(string a)
{
    return a.substr(0, a.find_last_of('.'));
}
int main(int argc, char *argv[])
{
    const string load = "LoadPlugin(\"D:\\Programs\\MeGUI\\tools\\ffms\\ffms2.dll\")\nLoadPlugin(\"D:\\Programs\\MeGUI\\tools\\avisynth_plugin\\VSFilter.dll\")";
    string n1, name, origin;
    if (argc > 1)
    {
        n1+=argv[1];
        for(int i=2;i<argc;i++)
        n1 =n1+' '+argv[i];
        name = quchu(n1);
        char pwd[256];
        getcwd(pwd, 256);
        origin = pwd;
        origin = origin + '\\' + n1;
    }
    else
    {
        cout << "请输入完整的文件路径：\n";
        getline(cin, origin);
        name = quchu(getName(origin));
    }
    ofstream fout;
    fout.open(name + ".avs");
    fout << load << endl;
    fout << "video=FFVideoSource(\"" << origin << "\")";
    cout << "是否更改视频尺寸：1-更改为720p、不更改（其他）,请输入：";
    char isResize = 0;
    cin >> isResize;
    if (isResize == '1')
    {
        fout << ".LanczosResize(1280,720)";
    }
    cout << "是否添加字幕：1-添加、不添加（其他）,请输入：";
    cin >> isResize;
    if (isResize == '1')
        fout << ".TextSub(\"" << quchu(origin) << ".ass\")";
    fout << endl;
    fout << "audio=FFAudioSource(\"" << origin << "\")" << endl;
    fout << "AudioDub(video,audio)" << endl;
    cout<<"是否裁切画面：1-裁切、不裁切（其他），请输入：";
    cin>>isResize;
    if(isResize=='1'){
        cout<<"请分别输入要裁切的像素数(必须为偶数)，按照左，上，右，下的顺序依次输入：";
        int zuo,you,shang,xia;
        cin>>zuo>>shang>>you>>xia;
        fout<<"crop("<<zuo<<","<<shang<<",-"<<you<<",-"<<xia<<")"<<endl;
    }
    cout<<"是否添加黑边，1-添加、不添加（其他），请输入：";
    cin>>isResize;
    if(isResize=='1'){
        cout<<"请分别输入要添加的像素数(必须为偶数)，按照左，上，右，下的顺序依次输入：";
        int zuo,you,shang,xia;
        cin>>zuo>>shang>>you>>xia;
        fout<<"addborders("<<zuo<<","<<shang<<","<<you<<","<<xia<<")"<<endl;
    }
    cout << "是否截取片段：1-截取、不截取（其他）,请输入：";
    cin >> isResize;
    if (isResize == '1')
    {
        cout << "请分别输入起始帧和结束帧：";
        int st, en;
        cin >> st >> en;
        fout << "trim(" << st << "," << en << ")" << endl;
    }
    fout.close();
    cout << "已经在当前目录创建" << name << ".avs\n";
    system("pause");
    return 0;
}