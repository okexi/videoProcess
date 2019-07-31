# videoProcess
主要功能：后期视频压制时简单avs脚本的生成
### 目前的功能
运行实例：
>![运行结果](./Pic/Res.png)

<<<<<<< HEAD
加入环境变量后支持参数调用，在视频目录下直接输入文件名更方便
=======
输入的文件路径为 
> G:\video\[sucai]\核爆神曲《ALIEZ》现场版\《ALIEZ》 现场版.mp4
>>>>>>> 4b5e83dab3fa5425648b5a3a80667795686e1d74

生成的`《ALIEZ》 现场版.avs`中的内容
```
LoadPlugin("D:\Programs\MeGUI\tools\ffms\ffms2.dll")
LoadPlugin("D:\Programs\MeGUI\tools\avisynth_plugin\VSFilter.dll")
video=FFVideoSource("G:\video\[sucai]\核爆神曲《ALIEZ》现场版\《ALIEZ》 现场版.mp4").LanczosResize(1280,720).TextSub("G:\video\[sucai]\核爆神曲《ALIEZ》现场版\《ALIEZ》 现场版.ass")
audio=FFAudioSource("G:\video\[sucai]\核爆神曲《ALIEZ》现场版\《ALIEZ》 现场版.mp4")
AudioDub(video,audio)
trim(23,546)

```
只适用于在`简体中文windows`环境下，编码方式为`GBK`，相信能满足一部分人的后期需求，`LanczosResize`更改分辨率，当前默认更改为720p,`TextSub`添加字幕（字幕需要在同文件夹下，与视频同名），`trim(23,546)` 裁取 23-546 帧。

### 使用方式
配合MEGUI使用，直接将生成的avs脚本拖入即可，需要注意修改下视频输出文件名，防止覆盖原视频
![使用脚本](./Pic/shiyong.png)