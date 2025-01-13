## 添加spdlog库
` git submodule add https://github.com/gabime/spdlog.git .\HazelGameEngine\vendor\spdlog`

如果网速太慢遇到`RPC failed`
![[Pasted image 20250112231341.png]]
可以给`git`添加代理，以clash为例：
```
git config --global http.proxy 'http://127.0.0.1:7890'

git config --global https.proxy 'http://127.0.0.1:7890'
```
## 添加Log类

在`src\HzaelGameEngine\`添加Log.h Log.cpp
Log类是在spdlog基础上的再封装，spdlog提供了基础了日志功能，具体功能可以查看[wiki](https://github.com/gabime/spdlog/wiki)：
spdlog使用为不同的Logger创建了不同的线程，在Log类中定义两个`std::shared_ptr<spdlog::logger>`类型的静态变量，该变量在**Init**函数中初始化，通过定义宏完成二次封装，同时也让日志的打印更加灵活

```
//Core log macros
#define HZ_CORE_TRACE(...)   ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)    ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)    ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)   ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)   ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...)		 ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		 ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		 ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		 ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)		 ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
```

## 初始化Log
在Hazel.h头文件中，在entrypoint之前引入Log.h头文件，并在entrypoint main函数中调用Log::Init()
并打印日志信息