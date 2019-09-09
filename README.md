# QT-MinGW_64-OpenCV
用MinGW_64编译的OpenCV库，可以导入QtCreator使用, 最初下载的是编译好的OpenCV发现编译的时候报连接错误，可能与官方使用的编译链不同导致。

# 编译过程
1. 下载最新的OpenCV 4.1.1 Sources
2. 下载QtCreator4.9.2, 选择Mingw-64编译链安装
3. 下载CMake
4. 配置环境变量PATH：
   cmake.exe的环境变量：C:\Program Files\CMake\bin
   编译链的环境变量: C:\Qt\Tools\mingw730_64\bin;C:\Qt\5.13.0\mingw73_64\bin
5. 解压源码
   cd到源码下，执行cmake-gui配置编译选项
   指定源码路径
   指定生成bin的路径
   指定编译工具g++,gcc
   点击Configure
       勾选WITH_QT，WITH_OPENGL
   点击Configure
   
       设置 Qt5Concurrent_DIR C:\Qt\5.13.0\mingw73_64\lib\cmake\Qt5Concurrent
       设置 Qt5Core_DIR ...
       设置 Qt5Gui_DIR ...
       设置 Qt5Test_DIR ...
       设置 Qt5Widgets_DIR ...
       设置 Qt5OpenGL_DIR ...
       设置 CMAKE_BUILD_TYPE 为 Release 或者 RelWithDebInfo
       
   点击Generate
   源码下编译：mingw32-make; mingw32-make install
   
   PS：编译中有个小错误，找不到test_common.hpp，copy到那个报错的目录就可以了
   
   编译好的bin放到百度网盘：
   链接：https://pan.baidu.com/s/19WFspPR7IUC74G9ksaYcUA 
   提取码：uutc
