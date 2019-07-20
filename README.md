# videoProcess
---
主要功能：后期视频压制avs脚本的生成
### 目前的功能
举个例子：
```
LoadPlugin("D:\Programs\MeGUI\tools\ffms\ffms2.dll")
LoadPlugin("D:\Programs\MeGUI\tools\avisynth_plugin\VSFilter.dll")
video=FFVideoSource("H:\video\在地下城寻求邂逅是否搞错了什么\[Danmachi][NCED3].mp4").LanczosResize(1280,720).TextSub("H:\video\在地下城寻求邂逅是否搞错了什么\[Danmachi][NCED3].ass")
audio=FFAudioSource("H:\video\在地下城寻求邂逅是否搞错了什么\[Danmachi][NCED3].mp4")
AudioDub(video,audio)
trim(1,556)
```

相信能满足大部分人的后期需求，`LanczosResize`更改为分辨率，当前默认更改为720p,`TextSub`添加字幕，`trim(1,556)` 裁取 1-556 帧