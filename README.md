# videoProcess
---
主要功能：后期视频压制avs脚本的生成
### 目前的功能
举个例子：
生成的`神楽七奈b站初放送：中国语合集【片尾嘶哈嘶哈名台词放送】.avs`中的内容
```
LoadPlugin("D:\Programs\MeGUI\tools\ffms\ffms2.dll")
LoadPlugin("D:\Programs\MeGUI\tools\avisynth_plugin\VSFilter.dll")
video=FFVideoSource("H:\video\[sucai]\神楽七奈b站初放送：中国语合集【片尾嘶哈嘶哈名台词放送】.flv").LanczosResize(1280,720).TextSub("H:\video\[sucai]\神楽七奈b站初放送：中国语合集【片尾嘶哈嘶哈名台词放送】.ass")
audio=FFAudioSource("H:\video\[sucai]\神楽七奈b站初放送：中国语合集【片尾嘶哈嘶哈名台词放送】.flv")
AudioDub(video,audio)
trim(232,4546)

```

相信能满足大部分人的后期需求，`LanczosResize`更改分辨率，当前默认更改为720p,`TextSub`添加字幕（字幕需要在同文件夹下，与视频同名），`trim(1,556)` 裁取 1-556 帧。
### 更新
之前不支持中文文件名的原因在于powershell
![运行结果](./Pic/Res.png)