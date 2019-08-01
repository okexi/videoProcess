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
        cout << "�������������ļ�·����\n";
        getline(cin, origin);
        name = quchu(getName(origin));
    }
    ofstream fout;
    fout.open(name + ".avs");
    fout << load << endl;
    fout << "video=FFVideoSource(\"" << origin << "\")";
    cout << "�Ƿ������Ƶ�ߴ磺1-����Ϊ720p�������ģ�������,�����룺";
    char isResize = 0;
    cin >> isResize;
    if (isResize == '1')
    {
        fout << ".LanczosResize(1280,720)";
    }
    cout << "�Ƿ������Ļ��1-��ӡ�����ӣ�������,�����룺";
    cin >> isResize;
    if (isResize == '1')
        fout << ".TextSub(\"" << quchu(origin) << ".ass\")";
    fout << endl;
    fout << "audio=FFAudioSource(\"" << origin << "\")" << endl;
    fout << "AudioDub(video,audio)" << endl;
    cout<<"�Ƿ���л��棺1-���С������У��������������룺";
    cin>>isResize;
    if(isResize=='1'){
        cout<<"��ֱ�����Ҫ���е�������(����Ϊż��)���������ϣ��ң��µ�˳���������룺";
        int zuo,you,shang,xia;
        cin>>zuo>>shang>>you>>xia;
        fout<<"crop("<<zuo<<","<<shang<<",-"<<you<<",-"<<xia<<")"<<endl;
    }
    cout<<"�Ƿ���Ӻڱߣ�1-��ӡ�����ӣ��������������룺";
    cin>>isResize;
    if(isResize=='1'){
        cout<<"��ֱ�����Ҫ��ӵ�������(����Ϊż��)���������ϣ��ң��µ�˳���������룺";
        int zuo,you,shang,xia;
        cin>>zuo>>shang>>you>>xia;
        fout<<"addborders("<<zuo<<","<<shang<<","<<you<<","<<xia<<")"<<endl;
    }
    cout << "�Ƿ��ȡƬ�Σ�1-��ȡ������ȡ��������,�����룺";
    cin >> isResize;
    if (isResize == '1')
    {
        cout << "��ֱ�������ʼ֡�ͽ���֡��";
        int st, en;
        cin >> st >> en;
        fout << "trim(" << st << "," << en << ")" << endl;
    }
    fout.close();
    cout << "�Ѿ��ڵ�ǰĿ¼����" << name << ".avs\n";
    system("pause");
    return 0;
}