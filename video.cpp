#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

wstring getName(wstring a){ //��ȡ����Ƶ�ļ����ļ���
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
wstring quchu(wstring a){//��ȡȥ����׺����·�������������Ļʱʹ��
    wstring res;
    int pos=a.find(L'.',0);
    for(int i=0;i<pos;i++){
        res.push_back(a[i]);
    }
    return res;
}
int main(){
    system("chcp 936");//���ĵ�ǰ���ڱ��뷽ʽΪGBK����ֹ����
    const wstring load=L"LoadPlugin(\"D:\\Programs\\MeGUI\\tools\\ffms\\ffms2.dll\")\nLoadPlugin(\"D:\\Programs\\MeGUI\\tools\\avisynth_plugin\\VSFilter.dll\")";
    cout<<"��������������Ƶ��ַ��\n";
    wstring ori;
   getline(wcin,ori);
    wstring name=getName(ori);
    string name1;
    for (int i = 0; name.c_str()[i]; i++)
    {
       name1.push_back(name.c_str()[i]);//���ļ���wstringת���string���ͣ���������ļ����ļ���
    }
    cout<<name1<<endl;
    wofstream fout(name1+".avs");
        fout<<load<<endl;
        fout<<L"video=FFVideoSource(\""<<ori<<"\")";
        cout<<"�Ƿ���ĳߴ磺1-���ġ������ģ�Ĭ�ϣ�,�����룺";
        char isResize=0;
        cin>>isResize;
        if(isResize=='1'){
            fout<<L".LanczosResize(1280,720)";
        }
        cout<<"�Ƿ������Ļ��1-��ӡ�����ӣ�Ĭ�ϣ�,�����룺";
        cin>>isResize;
        if(isResize=='1')fout<<L".TextSub(\""<<quchu(ori)<<".ass\")";
        fout<<endl;
        fout<<L"audio=FFAudioSource(\""<<ori<<"\")"<<endl;
        fout<<L"AudioDub(video,audio)"<<endl;
        cout<<"�Ƿ��и���Ƶ��1-�и���иĬ�ϣ�,�����룺";
        cin>>isResize;
        if(isResize=='1'){
            cout<<"��ֱ�������ʼ֡�ͽ���֡��";
            int st,en;
            cin>>st>>en;
            fout<<L"trim("<<st<<","<<en<<")"<<endl;
        }
        fout.close();
        cout<<"�Ѿ��ڵ�ǰĿ¼�´���"<<name1<<".avs,���뷽ʽΪGBK\n";
        system("pause");
    return 0;
}