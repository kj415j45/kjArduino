# kjArduino

使用本框架让您的 Arduino 源码简洁易读又高效。

-----

master构建状态:[![Build Status](https://travis-ci.org/kj415j45/kjArduino.svg?branch=master)](https://travis-ci.org/kj415j45/kjArduino)

构建状态仅代表主流板型是否可以正常编译运行本框架，一切以实际运行时为准。

## 安装

1. 在 Releases 中下载源码的 zip 压缩包
2. 在 Arduino IDE 中选择 `项目 -> 加载库 -> 添加一个.ZIP库` 然后选中源码的压缩包

## 用法

导入成功后在您的 `.ino` 文件头添加
```C++
#include <kjArduino.h>
```
现在您已成功导入本框架，享受本框架带来的全新编程方式吧


## 如何贡献自己的力量

如果有什么地方写得不够好,或是需要添加某些特性,欢迎前往Pull Requests/issues提交您的想法.

如果是PR请确保您的改动不会导致编译问题(板型兼容问题)，提交PR后Travis CI将自动进行检查。

如果遭遇问题并且您无法定位，请在issues中详细描述发生该问题前您的操作。
