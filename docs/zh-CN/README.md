# Enhanced

强大的C/C++开发框架

此软件遵循[Enhanced License](../../LICENSE)。

[版权声明](../../COPYRIGHT)

仓库：[GitHub](https://github.com/sharedwonder/Enhanced)

[其它语言](../README.Languages.md) | [网站](https://sharedwonder.github.io/enhanced-website) | [自述文件](README.md) | [帮助&支持](Help-Support.md) | [关于](About.md)

---

## ⚠ **警告：此软件还不能投入生产使用！**

该项目仍处于早期阶段，许多特性尚不成熟或未实现。

请不要在生产环境中使用。***否则，请自己承担风险！***

---

## 1.介绍

此软件是一个C/C++库。
它包含了许多有用的模块，具有各种功能强大的类和函数（方法）：

注意：许多功能尚未开发，会在未来逐渐添加。

- 1. 基本的数据类型（比如：String、Integer）
- 2. 更强大的异常处理（包括C语言的支持）
- 3. 容器 （集合、组、图等）
- 4. 模板（泛型）类和函数（只有C++支持）
- 5. 线程
- 6. 跨平台的底层API
- 7. 数据处理
- 8. ……

## 2.安装/卸载

目前还没有安装程序，你可以下载源代码，自己构建项目。

- 安装程序和卸载程序将在未来提供。

## 3.如何使用此软件？

### 支持的环境

- 这些是使用此库的所支持环境，而不是构建环境。

编译器：[Microsoft Visual C++](https://visualstudio.microsoft.com/vs/features/cplusplus/)、[GNU C/C++ Compiler](https://gcc.gnu.org/)、[Clang](https://clang.llvm.org/)

操作系统：Microsoft Windows操作系统、Linux

处理器：amd64 (x86_64)、x86

支持的C标准：C11

支持的C++标准：C++17、C++20

## 4.构建

必需环境：

- C标准: C11
- C++标准: C++17
- 构建系统: CMake

推荐环境：

- C标准: C11
- C++标准: C++20
- 构建系统: CMake与Ninja

## 5.愿望

我希望这个库能使C/C++语言的软件开发更加方便和高效。

## 6.技术

### 关于这个项目中的泛型（模板）

在这个项目中，类名后面带着“Impl”的类是泛型类的通用实现类。
大部分泛型类的实现都在实现类中（除了少部分特殊的泛型类）

它们通过类型擦除（伪泛型）分离了泛型类的实现。

你不应该从另一个类继承实现类，也不应该直接实例化实现类。
正确的方法是实例化模板类，因为实现类没有公共方法。
