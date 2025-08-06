# Awesome Information
<p align='center'>
    <img src="https://capsule-render.vercel.app/api?type=waving&color=auto&height=300&section=header&text=Store%20Management&fontSize=90&animation=fadeIn&fontAlignY=38&desc=Decorate%20GitHub%20like%20me!&descAlignY=61&descAlign=62"/>
</p>

![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)![C++ Badge](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)  
---
# Sections 🚧

- [Awesome Information](#awesome-information)
 [](#)
- [Sections](#sections)
  - [Features](#features)
  - [To-DO](#to-do-)
  - [Folder Structure](#folder-structure-)
  - [Pre-requisite](#pre-requisite)
  - [Build & Run](#build---run)
  - [Diagram ⚡](#diagram-)
  - [Contributors 🚑](#contributors-)

## Features 🎨
- CRUD - create, read, update, delete
- User Interface - sleek table
- File creation - CSV format, import, export

## To-DO 🔧
<pre>
[x] 1  - _Account_ & User Management
[x] 2  - Stock Tracker
[ ] 3  - Currency Calculator
[x] 4  - Log status
[x] 5  - CRUD
[x] 6  - File csv
[x] 7  - Table Display
[x] 8  - Sort Algorithm
[x] 9  - Search Algorithm
[x] 10 - Profit & Loss revenue report
[x] 11 - Product Range List
[ ] 12 - Log Bugs
[x] 13 - Documentation
[x] 14 - Clean & Link Library
</pre>

## Folder Structure 🔖
```
.
├── item_chaos.csv
├── lib
│   ├── Benchmark.cpp
│   ├── Benchmark.h
│   ├── DisplayManager.cpp
│   ├── DisplayManager.h
│   ├── FileManager.cpp
│   ├── FileManager.h
│   ├── Item.h
│   ├── label.cpp
│   ├── label.h
│   ├── modifier.cpp
│   ├── modifier.h
│   ├── Search.cpp
│   ├── Search.h
│   ├── SortHelper.cpp
│   ├── SortHelper.h
│   ├── StockList.cpp
│   ├── StockList.h
│   ├── SystemLog.cpp
│   ├── SystemLog.h
│   ├── User.cpp
│   └── User.h
├── main.cpp
├── Makefile
├── README.md
└── test
    ├── animated-test.cpp
    ├── ansii-test.cpp
    ├── cerr_cout-test.cpp
    ├── class-stock.cpp
    ├── export-reader.cpp
    ├── header-ptr-test.cpp
    ├── leven_test.cpp
    ├── read-test.cpp
    ├── timecall-test.cpp
    └── unsolved
        └── futureFilePath.cpp
________________________________        
21 files, 3 directories
```

## Pre-requisite
- MUST HAVE [MSYS2](https://www.msys2.org/) installed - native Windows GNU environment 

## Build - Run
\+ Window MSYS2, from [Visual Studio code](https://code.visualstudio.com/docs/languages/cpp#_example-install-mingwx64-on-windows "Install C/C++ toolchain"):
- Ensure `mingw toolchain` is installed in MSYS2,  to compile C++ code. Use `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain` in MSYS2
- run `mingw32-make` in project folder `Stock Information System`

## Diagram ⚡
In development use : [drawio](https://app.diagrams.net/#G1M2pyj16JH6AFf1WA127I3CwtmYwmrxLA#%7B%22pageId%22%3A%22eA5-_UtGZlGp_2mV5G3s%22%7D)

## Contributors 🚑
- [Theany](https://github.com/Sotheany-web) : Logical Dev - on Update & Delete of CRUD, Menu Designer
- [Soklang](https://github.com/11Soklang) : Security Dev - mini hash concept, FileManager