## 创建github库

![[Pasted image 20250112194549.png]]
## 创建VS project hazel

`git clone 仓库`

将.git等所有文件拷贝到创建的vs project中

## 修改项目属性

我们希望我们的引擎最后生成一个dll文件，而我们的游戏只需要链接这个dll则可以使用引擎的所有内容

- 修改游戏引擎的属性：

	修改游戏引擎的配置类型为动态库dll

	修改游戏引擎输出目录为
	`$(SolutionDir)\bin\$(Configuration)-$(Platform)\$(ProjectName)\`

	修改游戏引擎中间目录为`$(SolutionDir)\bin\int\$(Configuration)-$(Platform)\$(ProjectName)\`

- 创建一个游戏项目

	修改游戏的属性：

	复制游戏引擎输出目录以及中间目录

	右键游戏项目，添加引用为游戏引擎，这样游戏引擎输出的lib库将被链接到游戏项目中，因为游戏项目要调用游戏引擎的dll，而C++在链接时需要链接对应信息，所以需要lib通过链接，而在运行时则通过dll加载对应内容

- 在游戏引擎中创建Hazel文件夹

	在文件夹中添加Core.h以及Application.cpp  Application.h EntryPoint.h

	Application用于应用程序继承，然后重写自己的Run方法；

	Core.h用于添加Hazel__API宏，

	```
	#ifdef HZ_BUILD_DLL
	
	       #define HAZEL_API __declspec(dllexport)
	
	#else
	
	       #define HAZEL_API __declspec(dllimport)
	
	#endif
	```

	在编译时进行判断，在游戏引擎编译时导出dll,在游戏编译时，引用dll

	EntryPoint.h用于定义程序入口main方法，在main中生成游戏的Application，游戏的Application由客户端通过Create Application方法自己定义，而CreateApplication方法在Application声明；

- 在Hazel文件夹同级下创建Hazel.h文件，添加需要使用到的游戏引擎性能
	```
	#pragma once
	
	//For use by Hazel applications
	
	#include <stdio.h>
	
	#include "Hazel/Application.h"
	
	// ---Entry Point--------------
	
	#include "Hazel/EntryPoint.h"
	
	//-----------
	```

- 在游戏项目中创建SandBoxApp.cpp

	先导入<hazel.h>,然后定义自己的类SandBox并实现CreateApplication方法