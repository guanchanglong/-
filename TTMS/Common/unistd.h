/*
TTMS系统 西安邮电大学软件工程19级课设
创建于2020/6/10
*/

//许多在Linux下开发的C程序都需要头文件unistd.h，但VC中没有这个头文件，所以用VC编译总是报错。把下面的内容保存为unistd.h，可以解决这个问题。

//unistd即unix std，是POSIX标准定义的unix类系统定义符号常量的头文件，包含了许多UNIX系统服务的函数原型，例如read函数、write函数和getpid函数。

//unistd.h在unix中类似于window中的windows.h。

#pragma once

#ifndef _UNISTD_H

#define _UNISTD_H

#include <io.h>

#include <process.h>

#endif /* _UNISTD_H */