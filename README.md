# videoProcess
主要功能：后期视频压制时简单avs脚本的生成
### 使用方式
* 双击运行,需要输入视频的完整路径
* 加入环境变量后在视频目录下使用参数调用，在视频目录下直接输入文件名更方便

需要配合MEGUI使用，直接将生成的avs脚本拖入即可，需要注意修改下视频输出文件名，防止覆盖原视频。
#### 运行实例
比如我要截取视频右下角可爱的狗妈
![使用脚本](./Pic/shiyong.png)

生成的`【Bilibili限定7.18】晚酌歌回~【假酒七奈】.avs`中的内容
```
LoadPlugin("D:\Programs\MeGUI\tools\ffms\ffms2.dll")
LoadPlugin("D:\Programs\MeGUI\tools\avisynth_plugin\VSFilter.dll")
video=FFVideoSource("G:\video\[sucai]\核爆神曲《ALIEZ》现场版\【Bilibili限定7.18】晚酌歌回~【假酒七奈】.flv")
audio=FFAudioSource("G:\video\[sucai]\核爆神曲《ALIEZ》现场版\【Bilibili限定7.18】晚酌歌回~【假酒七奈】.flv")
AudioDub(video,audio)
crop(1476,638,-0,-0)
addborders(0,16,0,16)
trim(27995,28150)

```
只适用于在`简体中文windows`环境下，编码方式为`GBK`，相信能满足一部分人的后期需求。
* `LanczosResize(1280,720)`更改分辨率为1280*720，当前默认更改尺寸,本例未更改
* `TextSub`添加字幕（字幕需要在同文件夹下，与视频同名）本例未添加
* `crop(1476,638,-0,-0)`裁去左边1476个像素，上面638个像素
* `addborders(0,16,0,16)`添加上下各16个像素的黑边
* `trim(27995,28150)` 裁取 27995-28150 帧。

