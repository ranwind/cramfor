# C++基础详解：从简介到基本语法

## 1. C++简介与开发环境搭建

### 1.1 C++的历史与发展
C++是由Bjarne Stroustrup于1979年在贝尔实验室开始开发的一种编程语言，最初被称为"C with Classes"。它是对C语言的扩展，增加了面向对象编程的特性。1983年正式更名为C++，名称中的"++"表示它是C语言的增强版本。

C++的发展经历了多个重要版本：
- 1998年：第一个ISO C++标准(C++98)
- 2003年：小修订版(C++03)
- 2011年：重大更新(C++11，添加了许多现代特性)
- 2014年：C++14(对C++11的小幅改进)
- 2017年：C++17
- 2020年：C++20(添加了模块、协程等重大特性)

### 1.2 C++的特点与应用领域
C++的主要特点包括：
- 高效性：接近硬件，性能接近C语言
- 面向对象：支持封装、继承和多态
- 泛型编程：通过模板支持
- 低级内存操作：可以直接操作内存
- 跨平台：可在多种操作系统上运行

应用领域：
- 系统软件：操作系统、驱动程序
- 游戏开发：大多数游戏引擎使用C++
- 嵌入式系统：资源受限环境
- 高性能计算：科学计算、金融分析
- 图形处理：图像处理、计算机视觉
- 数据库系统：MySQL、MongoDB等

### 1.3 主流编译器介绍
1. **GCC (GNU Compiler Collection)**
   - 开源编译器集合，支持多种语言
   - 跨平台，性能优秀
   - 命令：`g++ program.cpp -o program`

2. **Clang**
   - LLVM项目的一部分，编译速度快
   - 提供更好的错误信息
   - 命令：`clang++ program.cpp -o program`

3. **MSVC (Microsoft Visual C++)**
   - Microsoft开发的编译器
   - Windows平台首选
   - 集成在Visual Studio中

### 1.4 开发环境配置

#### Visual Studio (Windows)
1. 下载并安装Visual Studio Community版
2. 安装时选择"使用C++的桌面开发"工作负载
3. 创建新项目：文件 → 新建 → 项目 → Visual C++ → 空项目
4. 添加源文件：右键项目 → 添加 → 新建项 → C++文件(.cpp)

#### Code::Blocks (跨平台)
1. 下载并安装Code::Blocks
2. 启动后选择"Create a new project"
3. 选择"Console application" → C++
4. 填写项目名称和路径
5. 选择编译器(GNU GCC Compiler)

#### CLion (跨平台)
1. 下载并安装JetBrains CLion
2. 启动后选择"New Project"
3. 选择"C++ Executable"
4. 设置项目位置和语言标准(C++11/14/17等)

### 1.5 第一个C++程序: Hello World

```cpp
// 这是单行注释

/*
   这是多行注释
   可以跨越多行
*/

#include <iostream>  // 包含标准输入输出库

// main函数是程序的入口点
int main() {
    // 使用标准输出打印Hello World!
    std::cout << "Hello World!" << std::endl;
    
    // 返回0表示程序成功执行
    return 0;
}
```

编译运行步骤：
1. 将代码保存为`hello.cpp`
2. 打开终端/命令行，导航到文件所在目录
3. 编译：`g++ hello.cpp -o hello` (GCC) 或 `clang++ hello.cpp -o hello` (Clang)
4. 运行：`./hello` (Linux/macOS) 或 `hello.exe` (Windows)

## 2. 基本语法与程序结构

### 2.1 C++程序的基本结构
一个典型的C++程序包含以下部分：

```cpp
// 1. 预处理指令(引入头文件)
#include <iostream>

// 2. 命名空间声明(可选)
using namespace std;

// 3. 函数声明(可选)
void greet();

// 4. 主函数
int main() {
    // 程序主要逻辑
    greet();
    return 0;
}

// 5. 函数定义
void greet() {
    cout << "Welcome to C++!" << endl;
}
```

### 2.2 注释的使用
C++支持两种注释形式：

1. 单行注释：以`//`开头，直到行尾
   ```cpp
   // 这是一个单行注释
   int x = 5;  // 也可以放在代码后面
   ```

2. 多行注释：以`/*`开始，以`*/`结束
   ```cpp
   /*
   这是一个多行注释
   可以跨越多行
   常用于函数说明或文件头注释
   */
   ```

### 2.3 标识符与关键字
**标识符**是程序员定义的名称，用于变量、函数、类等。命名规则：
- 可以包含字母、数字和下划线
- 必须以字母或下划线开头
- 区分大小写
- 不能使用关键字

**C++关键字**(部分)：
```
alignas     alignof     and         and_eq      asm         auto
bitand      bitor       bool        break       case        catch
char        char8_t     char16_t    char32_t    class       compl
const       consteval   constexpr   const_cast  continue    decltype
default     delete      do          double      dynamic_cast else
enum        explicit    export      extern      false       float
for         friend      goto        if          inline      int
long        mutable     namespace   new         noexcept    not
not_eq      nullptr     operator    or          or_eq       private
protected   public      register    reinterpret_cast return   short
signed      sizeof      static      static_assert static_cast struct
switch      template    this        thread_local throw       true
try         typedef     typeid      typename    union       unsigned
using       virtual     void        volatile    wchar_t     while
xor         xor_eq
```

### 2.3 基本输入输出(cin, cout)
C++使用`iostream`库进行输入输出操作：

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    string name;
    
    // 输出
    cout << "Enter your name: ";
    
    // 输入
    cin >> name;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
    
    return 0;
}
```

说明：
- `cout` (character output)用于输出，配合插入运算符`<<`
- `cin` (character input)用于输入，配合提取运算符`>>`
- `endl` (end line)用于插入换行符并刷新缓冲区
- 可以链式使用：`cout << "a" << "b" << endl;`

### 2.4 命名空间(namespace)的概念与使用
命名空间用于避免名称冲突，将相关标识符组织在一起。

**定义命名空间**：
```cpp
namespace MySpace {
    int x = 10;
    void display() {
        cout << "Inside MySpace" << endl;
    }
}
```

**使用命名空间**：
1. 完全限定名：
   ```cpp
   MySpace::x = 20;
   MySpace::display();
   ```

2. using声明：
   ```cpp
   using MySpace::x;
   x = 30;  // 可以直接使用x
   ```

3. using指令(引入整个命名空间)：
   ```cpp
   using namespace MySpace;
   x = 40;
   display();
   ```

**std命名空间**：
标准库的所有标识符都在`std`命名空间中：
```cpp
#include <iostream>

int main() {
    std::cout << "Using fully qualified name" << std::endl;
    
    using std::cout;
    using std::endl;
    cout << "Using declaration" << endl;
    
    using namespace std;
    cout << "Using directive" << endl;
    
    return 0;
}
```

**匿名命名空间**：
用于限制标识符仅在当前文件可见
```cpp
namespace {
    int localVar = 42;  // 只在当前文件可见
}
```

**嵌套命名空间**：
```cpp
namespace Outer {
    int x = 10;
    
    namespace Inner {
        int y = 20;
    }
}

// C++17引入的更简洁语法
namespace Outer::Inner {
    int z = 30;
}
```

**命名空间别名**：
```cpp
namespace VeryLongNamespaceName {
    int value = 100;
}

namespace VLN = VeryLongNamespaceName;

int main() {
    cout << VLN::value << endl;
    return 0;
}
```

这些内容构成了C++编程的基础，理解并掌握这些概念对于后续学习至关重要。建议通过实际编写代码来巩固这些知识，从简单的程序开始，逐步增加复杂度。




## 3. C++数据类型与变量详解

### 3.1 基本数据类型

#### 1. 整数类型

| 类型        | 大小(字节) | 范围                           | 说明                     |
|-------------|------------|--------------------------------|--------------------------|
| `short`     | 2          | -32,768 到 32,767              | 短整型                   |
| `int`       | 4          | -2,147,483,648 到 2,147,483,647 | 整型                     |
| `long`      | 4/8        | 平台相关                       | 长整型                   |
| `long long` | 8          | -9.2×10¹⁸ 到 9.2×10¹⁸          | 长长整型(C++11)          |
| `unsigned`  | 同对应类型 | 0 到 2ⁿ-1                      | 无符号版本(加前缀unsigned)|

示例：
```cpp
short s = 1000;
int i = -2000000;
long l = 3000000000L;
long long ll = 9000000000000000000LL;
unsigned int ui = 4000000000U;
```

#### 2. 浮点类型

| 类型     | 大小(字节) | 精度          | 范围                     |
|----------|------------|---------------|--------------------------|
| `float`  | 4          | 6-7位有效数字 | ±1.18×10⁻³⁸ 到 ±3.4×10³⁸ |
| `double` | 8          | 15-16位       | ±2.23×10⁻³⁰⁸ 到 ±1.80×10³⁰⁸ |
| `long double` | 8/16 | 平台相关      | 更大范围和精度           |

示例：
```cpp
float f = 3.14159f;       // 注意f后缀
double d = 2.718281828;
long double ld = 1.4142135623730950488L;
```

#### 3. 字符类型

| 类型      | 大小(字节) | 说明                          |
|-----------|------------|-------------------------------|
| `char`    | 1          | 基本字符类型(-128到127或0到255)|
| `wchar_t` | 2/4        | 宽字符(Unicode)               |
| `char16_t`| 2          | UTF-16字符(C++11)             |
| `char32_t`| 4          | UTF-32字符(C++11)             |

示例：
```cpp
char c = 'A';
wchar_t wc = L'你';
char16_t c16 = u'字';
char32_t c32 = U'🍎';
```

#### 4. 布尔类型
- `bool`：只有两个值`true`(1)和`false`(0)
- 大小通常为1字节

示例：
```cpp
bool isCppFun = true;
bool isEasy = false;
```

### 3.2 变量声明与初始化

#### 1. 变量声明基本形式
```cpp
数据类型 变量名;
数据类型 变量名 = 初始值;
数据类型 变量名{初始值};  // C++11统一初始化语法
```

#### 2. 初始化方式对比

```cpp
int a;          // 默认初始化(值不确定)
int b = 5;      // 拷贝初始化
int c(10);      // 直接初始化
int d{15};      // 列表初始化(C++11)
int e = {20};   // 带等号的列表初始化
auto f = 25;    // 使用auto推导类型
```

#### 3. 列表初始化的优势(C++11)
```cpp
int x{5};       // 正确
int y = 5.5;    // 隐式转换，y=5
int z{5.5};     // 错误:  narrowing conversion
```

#### 4. 多变量声明
```cpp
int x = 1, y = 2, z = 3;
double d1, d2{3.14}, d3 = 2.718;
```

### 3.3 常量(const与constexpr)

#### 1. const常量
```cpp
const double PI = 3.1415926;
const int MAX_SIZE = 100;

// const指针
int value = 10;
const int* ptr1 = &value;  // 指向常量的指针
int* const ptr2 = &value;  // 指针本身是常量
const int* const ptr3 = &value;  // 两者都是常量
```

#### 2. constexpr常量表达式(C++11)
```cpp
constexpr int size = 100;  // 编译期常量
constexpr double scale = 2.5;

constexpr int square(int x) {
    return x * x;
}
constexpr int val = square(5);  // 编译期计算
```

#### 3. const与constexpr区别
- `const`表示"只读"，可能在运行时确定
- `constexpr`必须在编译期确定值

### 3.4 类型转换

#### 1. 隐式类型转换
```cpp
int i = 3.14;    // 3 (double→int)
double d = i;    // 3.0 (int→double)
char c = 'A';
int n = c;       // 65 (ASCII值)
bool b = d;      // true (非零)
```

#### 2. 显式类型转换(C风格)
```cpp
double d = 3.14;
int i = (int)d;      // C风格强制转换
int j = int(d);      // 函数式转换
```

#### 3. C++四种强制类型转换
```cpp
// 1. static_cast: 相关类型间的转换
double d = 3.14;
int i = static_cast<int>(d);

// 2. dynamic_cast: 多态类型安全向下转换
class Base { virtual void foo() {} };
class Derived : public Base {};
Base* b = new Derived;
Derived* d = dynamic_cast<Derived*>(b);

// 3. const_cast: 移除const属性
const int ci = 10;
int* mod = const_cast<int*>(&ci);

// 4. reinterpret_cast: 低级别重新解释
int i = 42;
float f = reinterpret_cast<float&>(i);
```

### 3.5 auto关键字与类型推导(C++11)

#### 1. 基本用法
```cpp
auto i = 5;          // int
auto d = 3.14;       // double
auto c = 'A';        // char
auto b = true;       // bool
auto s = "hello";    // const char*
```

#### 2. 复合类型
```cpp
auto p = new auto(10);       // int*
const auto* const ptr = &i;  // const int* const

std::vector<int> vec;
auto it = vec.begin();       // std::vector<int>::iterator
```

#### 3. 与引用和const结合
```cpp
int x = 10;
const int& rx = x;
auto a = rx;         // int (忽略顶层const和引用)
auto& b = rx;        // const int&
const auto c = rx;   // const int
```

#### 4. decltype类型推导(C++11)
```cpp
int x = 10;
decltype(x) y = 20;      // int
decltype((x)) z = x;     // int& (注意双括号)

const int& crx = x;
decltype(crx) crx2 = x;  // const int&
```

### 3.6 字面量(literals)与后缀

#### 1. 整数字面量
```cpp
10      // 十进制
010     // 八进制(8)
0x10    // 十六进制(16)
0b1010  // 二进制(10, C++14)

// 后缀
100U    // unsigned
100L    // long
100UL   // unsigned long
100LL   // long long
100ULL  // unsigned long long
```

#### 2. 浮点字面量
```cpp
3.14     // double
3.14f    // float
3.14L    // long double

// 科学计数法
1.23e4   // 12300.0
1.23e-4  // 0.000123
```

#### 3. 字符和字符串字面量
```cpp
'A'          // char
u'你'        // char16_t
U'🍎'        // char32_t
L'字'        // wchar_t

"hello"      // const char[6]
u8"UTF-8"    // UTF-8字符串(C++11)
L"wide"      // wchar_t字符串
u"UTF-16"    // char16_t字符串(C++11)
U"UTF-32"    // char32_t字符串(C++11)
```

#### 4. 原始字符串字面量(C++11)
```cpp
// 普通字符串需要转义
std::string path = "C:\\Program Files\\Microsoft";

// 原始字符串
std::string rawPath = R"(C:\Program Files\Microsoft)";

// 带分隔符的原始字符串
std::string complexRaw = R"delimiter(Embedded )" quote)delimiter";
```

#### 5. 用户定义字面量(C++11)
```cpp
// 定义字面量操作符
constexpr long double operator"" _km(long double x) {
    return x * 1000.0;
}

// 使用
auto distance = 5.5_km;  // 5500.0
```

### 3.7 综合示例

```cpp
#include <iostream>
#include <string>
#include <typeinfo>

// 用户定义字面量
constexpr long double operator"" _c(long double deg) {
    return deg + 273.15;  // 摄氏度转开尔文
}

int main() {
    // 基本数据类型
    int count = 10;
    double price = 9.99;
    char grade = 'A';
    bool is_valid = true;
    
    // 类型推导
    auto auto_int = 42;  // int
    auto auto_dbl = 3.14;  // double
    decltype(auto_dbl) decl_dbl = 2.718;
    
    // 常量
    const int MAX_USERS = 100;
    constexpr double PI = 3.141592653589793;
    
    // 类型转换
    double x = 3.14;
    int y = static_cast<int>(x);
    
    // 字符串和原始字符串
    std::string path = "C:\\Windows\\System32";
    std::string raw_path = R"(C:\Windows\System32)";
    
    // 用户定义字面量
    auto temperature = 25.0_c;  // 298.15K
    
    // 输出类型信息
    std::cout << "auto_int type: " << typeid(auto_int).name() << "\n"
              << "auto_dbl type: " << typeid(auto_dbl).name() << "\n"
              << "25.0_c = " << temperature << "K\n";
    
    return 0;
}
```

### 3.8 最佳实践建议

1. **变量命名**：使用有意义的名称，遵循命名约定(如驼峰式或下划线式)
   ```cpp
   int studentCount;  // 驼峰式
   double max_score;  // 下划线式
   ```

2. **类型选择**：
   - 整数：优先使用`int`，大数用`long long`
   - 浮点：优先使用`double`，除非有内存限制
   - 避免使用`short`和`unsigned`除非有特殊需求

3. **常量使用**：
   - 能用`constexpr`就不用`const`
   - 宏定义尽量用`constexpr`替代
     ```cpp
     // 避免
     #define PI 3.14159
     
     // 推荐
     constexpr double PI = 3.14159;
     ```

4. **类型转换**：
   - 避免C风格强制转换，使用C++的四种强制转换
   - 警惕隐式类型转换带来的精度损失

5. **auto使用场景**：
   - 适合类型名很长或类型明显的情况
   - 避免过度使用导致代码可读性下降
   - 结合`const`和引用使用时要小心

6. **初始化**：
   - 推荐使用统一初始化语法`{}`
   - 防止窄化转换
   - 总是初始化变量，避免未定义行为




## 4. C++运算符与表达式全面详解

### 4.1 算术运算符

#### 基本算术运算符
| 运算符 | 描述       | 示例       | 结果 |
|--------|------------|------------|------|
| `+`    | 加法       | `5 + 3`    | 8    |
| `-`    | 减法       | `5 - 3`    | 2    |
| `*`    | 乘法       | `5 * 3`    | 15   |
| `/`    | 除法       | `5 / 3`    | 1    |
| `%`    | 取模(取余) | `5 % 3`    | 2    |

示例代码：
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    
    cout << "a + b = " << a + b << endl;  // 13
    cout << "a - b = " << a - b << endl;  // 7
    cout << "a * b = " << a * b << endl;  // 30
    cout << "a / b = " << a / b << endl;  // 3 (整数除法)
    cout << "a % b = " << a % b << endl;  // 1
    
    double x = 10.0, y = 3.0;
    cout << "x / y = " << x / y << endl;  // 3.33333 (浮点除法)
    
    return 0;
}
```

#### 自增自减运算符
| 运算符 | 描述               | 示例     | 结果 |
|--------|--------------------|----------|------|
| `++i`  | 前置递增(先增后用) | `j = ++i`| i+1, j=i+1 |
| `i++`  | 后置递增(先用后增) | `j = i++`| j=i, i+1 |
| `--i`  | 前置递减(先减后用) | `j = --i`| i-1, j=i-1 |
| `i--`  | 后置递减(先用后减) | `j = i--`| j=i, i-1 |

示例代码：
```cpp
int i = 5;
cout << "i++: " << i++ << endl;  // 输出5，然后i变为6
cout << "++i: " << ++i << endl;  // i变为7，输出7

int j = 10;
cout << "j--: " << j-- << endl;  // 输出10，然后j变为9
cout << "--j: " << --j << endl;  // j变为8，输出8
```

### 4.2 关系运算符

| 运算符 | 描述       | 示例     | 结果 |
|--------|------------|----------|------|
| `==`   | 等于       | `5 == 3` | false |
| `!=`   | 不等于     | `5 != 3` | true  |
| `>`    | 大于       | `5 > 3`  | true  |
| `<`    | 小于       | `5 < 3`  | false |
| `>=`   | 大于等于   | `5 >= 3` | true  |
| `<=`   | 小于等于   | `5 <= 3` | false |

示例代码：
```cpp
int x = 5, y = 3;
bool result;

result = (x == y);  // false
result = (x != y);  // true
result = (x > y);   // true
result = (x < y);   // false
result = (x >= y);  // true
result = (x <= y);  // false

// 常用于条件语句
if (x > y) {
    cout << "x is greater than y" << endl;
}
```

### 4.3 逻辑运算符

| 运算符 | 描述       | 示例            | 结果 |
|--------|------------|-----------------|------|
| `&&`   | 逻辑与     | `true && false` | false |
| `||`   | 逻辑或     | `true || false` | true  |
| `!`    | 逻辑非     | `!true`         | false |

示例代码：
```cpp
bool a = true, b = false;

cout << (a && b) << endl;  // 0 (false)
cout << (a || b) << endl;  // 1 (true)
cout << (!a) << endl;      // 0 (false)

// 短路求值特性
int i = 0;
if (a || (++i)) {  // ++i不会执行
    cout << "i = " << i << endl;  // 输出 i = 0
}

if (b && (++i)) {  // ++i不会执行
    // 不会执行
}
cout << "i = " << i << endl;  // 输出 i = 0
```

### 4.4 位运算符

| 运算符 | 描述       | 示例       | 结果(二进制) |
|--------|------------|------------|--------------|
| `&`    | 按位与     | `5 & 3`    | 0101 & 0011 = 0001 (1) |
| `|`    | 按位或     | `5 | 3`    | 0101 | 0011 = 0111 (7) |
| `^`    | 按位异或   | `5 ^ 3`    | 0101 ^ 0011 = 0110 (6) |
| `~`    | 按位取反   | `~5`       | ~0101 = 1010 (-6) |
| `<<`   | 左移       | `5 << 1`   | 0101 << 1 = 1010 (10) |
| `>>`   | 右移       | `5 >> 1`   | 0101 >> 1 = 0010 (2) |

示例代码：
```cpp
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011

cout << "a & b = " << (a & b) << endl;  // 1
cout << "a | b = " << (a | b) << endl;  // 7
cout << "a ^ b = " << (a ^ b) << endl;  // 6
cout << "~a = " << ~a << endl;          // 4294967290 (32位系统)
cout << "a << 1 = " << (a << 1) << endl; // 10
cout << "a >> 1 = " << (a >> 1) << endl; // 2

// 位运算实用技巧
int x = 16;
// 判断奇偶
if (x & 1) {
    cout << x << " is odd" << endl;
} else {
    cout << x << " is even" << endl;
}

// 交换两个数
a = a ^ b;
b = a ^ b;
a = a ^ b;
cout << "After swap: a=" << a << ", b=" << b << endl;
```

### 4.5 赋值运算符

| 运算符 | 描述       | 示例     | 等价于    |
|--------|------------|----------|-----------|
| `=`    | 简单赋值   | `a = 5`  | `a = 5`   |
| `+=`   | 加后赋值   | `a += 3` | `a = a + 3` |
| `-=`   | 减后赋值   | `a -= 3` | `a = a - 3` |
| `*=`   | 乘后赋值   | `a *= 3` | `a = a * 3` |
| `/=`   | 除后赋值   | `a /= 3` | `a = a / 3` |
| `%=`   | 取模后赋值 | `a %= 3` | `a = a % 3` |
| `&=`   | 按位与后赋值 | `a &= 3` | `a = a & 3` |
| `|=`   | 按位或后赋值 | `a |= 3` | `a = a | 3` |
| `^=`   | 按位异或后赋值 | `a ^= 3` | `a = a ^ 3` |
| `<<=`  | 左移后赋值 | `a <<= 3` | `a = a << 3` |
| `>>=`  | 右移后赋值 | `a >>= 3` | `a = a >> 3` |

示例代码：
```cpp
int a = 10;
a += 5;   // a = 15
a -= 3;   // a = 12
a *= 2;   // a = 24
a /= 4;   // a = 6
a %= 4;   // a = 2

int b = 6;  // 0110
b &= 5;     // 0100 (4)
b |= 3;     // 0111 (7)
b ^= 5;     // 0010 (2)
b <<= 2;    // 1000 (8)
b >>= 1;    // 0100 (4)
```

### 4.6 条件运算符(三目运算符)

语法：`条件 ? 表达式1 : 表达式2`

如果条件为true，返回表达式1的值，否则返回表达式2的值。

示例代码：
```cpp
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max = 20

// 嵌套使用
int x = 5, y = 10, z = 15;
int largest = (x > y) ? (x > z ? x : z) : (y > z ? y : z);

// 用于输出
cout << "The number is " << (a % 2 == 0 ? "even" : "odd") << endl;

// 返回引用(C++11)
int& ref = (a > b) ? a : b;
ref = 100;  // 修改b的值
```

### 4.7 逗号运算符

语法：`表达式1, 表达式2, ..., 表达式N`

从左到右依次计算各个表达式，返回最后一个表达式的值。

示例代码：
```cpp
int a = (1, 2, 3);  // a = 3

// 在for循环中常用
for (int i = 0, j = 10; i < j; i++, j--) {
    cout << "i=" << i << ", j=" << j << endl;
}

// 多个操作
int x = 10;
int y = (x += 5, x *= 2, x - 3);  // x=30, y=27

// 注意与函数参数中的逗号区分
void func(int a, int b);  // 这里的逗号是分隔符，不是运算符
```

### 4.8 sizeof运算符

返回类型或对象的大小(以字节为单位)。

语法：
- `sizeof(类型)`
- `sizeof 表达式`
- `sizeof...` (C++11, 用于参数包)

示例代码：
```cpp
cout << "sizeof(int): " << sizeof(int) << endl;        // 通常4
cout << "sizeof(double): " << sizeof(double) << endl;  // 通常8

int arr[10];
cout << "sizeof(arr): " << sizeof(arr) << endl;  // 10 * sizeof(int)

struct Point { double x, y; };
cout << "sizeof(Point): " << sizeof(Point) << endl;  // 通常16

// 用于动态分配内存
int* ptr = new int[100];
size_t size = 100 * sizeof(int);

// 注意：sizeof不会计算表达式，只确定类型
int x = 10;
cout << sizeof(x++) << endl;  // 输出4，x仍然是10
```

### 4.9 运算符优先级与结合性

#### 运算符优先级表(从高到低)

| 优先级 | 运算符                     | 结合性   |
|--------|----------------------------|----------|
| 1      | `::` (作用域解析)          | 从左到右 |
| 2      | `()` `[]` `->` `.` `++` `--` (后缀) | 从左到右 |
| 3      | `++` `--` (前缀) `+` `-` (一元) `!` `~` `*` (解引用) `&` (取地址) `sizeof` | 从右到左 |
| 4      | `.*` `->*` (成员指针)      | 从左到右 |
| 5      | `*` `/` `%`                | 从左到右 |
| 6      | `+` `-` (二元)             | 从左到右 |
| 7      | `<<` `>>`                  | 从左到右 |
| 8      | `<` `<=` `>` `>=`          | 从左到右 |
| 9      | `==` `!=`                  | 从左到右 |
| 10     | `&` (按位与)               | 从左到右 |
| 11     | `^`                        | 从左到右 |
| 12     | `|`                        | 从左到右 |
| 13     | `&&`                       | 从左到右 |
| 14     | `||`                       | 从左到右 |
| 15     | `?:` (条件运算符)          | 从右到左 |
| 16     | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `|=` | 从右到左 |
| 17     | `,` (逗号运算符)           | 从左到右 |

#### 常见优先级问题示例

```cpp
int a = 5, b = 3, c = 2;

// 算术运算符优先级高于关系运算符
bool result = a + b > c * b;  // 等价于 (a + b) > (c * b)

// 关系运算符优先级高于逻辑运算符
if (a > b && b > c) {  // 等价于 (a > b) && (b > c)
    cout << "Descending order" << endl;
}

// 位运算符优先级低于关系运算符
int flags = 5;
if (flags & 1 == 0) {  // 错误: 等价于 flags & (1 == 0)
    // 不会执行
}

// 正确写法
if ((flags & 1) == 0) {
    cout << "Even" << endl;
}

// 赋值运算符优先级很低
int x = a + b * c;  // 等价于 x = (a + (b * c))

// 条件运算符优先级高于赋值运算符
int max = a > b ? a : b;  // 等价于 max = (a > b ? a : b)
```

#### 结合性示例

```cpp
// 赋值运算符右结合
int a, b, c;
a = b = c = 5;  // 等价于 a = (b = (c = 5))

// 条件运算符右结合
int x = 1, y = 2, z = 3;
int result = x > y ? x : y > z ? y : z;  // 等价于 x > y ? x : (y > z ? y : z)

// 算术运算符左结合
int val = a - b - c;  // 等价于 (a - b) - c
```

### 4.10 综合示例

```cpp
#include <iostream>
using namespace std;

int main() {
    // 算术运算符
    int a = 10, b = 3;
    cout << "Arithmetic:\n";
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " % " << b << " = " << a % b << endl;
    
    // 关系运算符
    cout << "\nRelational:\n";
    cout << a << " == " << b << " : " << (a == b) << endl;
    cout << a << " != " << b << " : " << (a != b) << endl;
    cout << a << " > " << b << " : " << (a > b) << endl;
    cout << a << " < " << b << " : " << (a < b) << endl;
    
    // 逻辑运算符
    bool t = true, f = false;
    cout << "\nLogical:\n";
    cout << t << " && " << f << " : " << (t && f) << endl;
    cout << t << " || " << f << " : " << (t || f) << endl;
    cout << "!" << t << " : " << !t << endl;
    
    // 位运算符
    unsigned int x = 5, y = 3;
    cout << "\nBitwise:\n";
    cout << x << " & " << y << " : " << (x & y) << endl;
    cout << x << " | " << y << " : " << (x | y) << endl;
    cout << x << " ^ " << y << " : " << (x ^ y) << endl;
    cout << "~" << x << " : " << ~x << endl;
    cout << x << " << 1 : " << (x << 1) << endl;
    cout << x << " >> 1 : " << (x >> 1) << endl;
    
    // 条件运算符
    cout << "\nConditional:\n";
    cout << "Max of " << a << " and " << b << " is " 
         << (a > b ? a : b) << endl;
    
    // sizeof运算符
    cout << "\nsizeof:\n";
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(\"Hello\"): " << sizeof("Hello") << endl;
    
    // 运算符优先级演示
    cout << "\nPrecedence:\n";
    int res = a + b * 2 > a - b && b != 0;
    cout << "a + b * 2 > a - b && b != 0: " << res << endl;
    // 等价于 ((a + (b * 2)) > (a - b)) && (b != 0)
    
    return 0;
}
```

### 4.11 最佳实践建议

1. **明确优先级**：当表达式复杂时，使用括号明确运算顺序，即使不是必须的也能提高可读性
   ```cpp
   // 不易读
   if (a & b == c)
   
   // 更清晰
   if ((a & b) == c)
   ```

2. **避免过度复杂表达式**：将复杂表达式拆分为多个简单表达式
   ```cpp
   // 不易读
   int result = (a + b) * (c - d) + (e / f) % g;
   
   // 更清晰
   int temp1 = a + b;
   int temp2 = c - d;
   int temp3 = e / f;
   int result = temp1 * temp2 + temp3 % g;
   ```

3. **注意自增自减的副作用**：避免在同一个表达式中对同一变量多次使用++/--
   ```cpp
   // 未定义行为
   int i = 0;
   int j = i++ + i++;
   
   // 明确分开
   int i = 0;
   int j = i++;
   j += i++;
   ```

4. **合理使用条件运算符**：适合简单的条件赋值，复杂逻辑还是用if语句
   ```cpp
   // 适合
   int max = (a > b) ? a : b;
   
   // 不适合
   (a > b) ? (a = 0) : (b = 0, cout << "b is larger");
   ```

5. **注意类型转换**：混合类型运算时注意隐式类型转换规则
   ```cpp
   double d = 3.14;
   int i = 2;
   auto result = d / i;  // result是double
   ```

6. **位运算优化**：只在性能关键路径使用位运算优化，并添加充分注释
   ```cpp
   // 快速判断是否为2的幂
   bool isPowerOfTwo = (n & (n - 1)) == 0;
   ```

7. **sizeof注意事项**：
   - 对指针使用sizeof得到的是指针大小，不是指向对象大小
   - 对数组参数使用sizeof在函数内部不起作用(数组退化为指针)
   - 对类使用sizeof考虑对齐填充的影响












## C++流程控制全面详解

### if-else语句

#### 基本语法
```cpp
if (条件表达式) {
    // 条件为真时执行的代码
} else {
    // 条件为假时执行的代码
}
```

#### 多级if-else
```cpp
if (条件1) {
    // 条件1为真时执行
} else if (条件2) {
    // 条件2为真时执行
} else if (条件3) {
    // 条件3为真时执行
} else {
    // 所有条件都为假时执行
}
```

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "请输入考试成绩(0-100): ";
    cin >> score;

    if (score >= 90) {
        cout << "优秀" << endl;
    } else if (score >= 80) {
        cout << "良好" << endl;
    } else if (score >= 60) {
        cout << "及格" << endl;
    } else {
        cout << "不及格" << endl;
    }

    // 单语句可以省略大括号(但不推荐)
    if (score == 100)
        cout << "满分！" << endl;
    else
        cout << "不是满分" << endl;

    return 0;
}
```

#### 嵌套if语句
```cpp
int age;
bool hasLicense;
cout << "请输入年龄和是否有驾照(1/0): ";
cin >> age >> hasLicense;

if (age >= 18) {
    if (hasLicense) {
        cout << "可以合法驾驶" << endl;
    } else {
        cout << "需要考取驾照" << endl;
    }
} else {
    cout << "未达到法定驾驶年龄" << endl;
}
```

### switch-case语句

#### 基本语法
```cpp
switch (表达式) {
    case 常量1:
        // 表达式等于常量1时执行
        break;
    case 常量2:
        // 表达式等于常量2时执行
        break;
    // ...
    default:
        // 没有匹配的case时执行
}
```

#### 注意事项
1. 表达式必须是整型或枚举类型
2. case后面必须是常量表达式
3. break语句用于退出switch，没有break会继续执行下一个case(称为"case穿透")

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "请输入成绩等级(A-E): ";
    cin >> grade;

    switch (grade) {
        case 'A':
            cout << "优秀 (90-100分)" << endl;
            break;
        case 'B':
            cout << "良好 (80-89分)" << endl;
            break;
        case 'C':
            cout << "中等 (70-79分)" << endl;
            break;
        case 'D':
            cout << "及格 (60-69分)" << endl;
            break;
        case 'E':
            cout << "不及格 (0-59分)" << endl;
            break;
        default:
            cout << "无效的等级" << endl;
    }

    // 利用case穿透的例子
    int month, year;
    cout << "请输入月份和年份: ";
    cin >> month >> year;

    int days = 0;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            // 判断闰年
            if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
                days = 29;
            else
                days = 28;
            break;
        default:
            cout << "无效的月份" << endl;
    }
    
    if (days > 0)
        cout << year << "年" << month << "月有" << days << "天" << endl;

    return 0;
}
```

### while循环

#### 基本语法
```cpp
while (条件表达式) {
    // 循环体
}
```

#### 特点
1. 先判断条件，再决定是否执行循环体
2. 循环体可能一次都不执行

##### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    // 计算1到100的和
    int sum = 0, i = 1;
    while (i <= 100) {
        sum += i;
        i++;
    }
    cout << "1到100的和是: " << sum << endl;

    // 密码验证
    string password = "123456";
    string input;
    int attempts = 3;
    
    while (attempts > 0) {
        cout << "请输入密码(还剩" << attempts << "次机会): ";
        cin >> input;
        
        if (input == password) {
            cout << "密码正确，欢迎登录！" << endl;
            break;
        } else {
            attempts--;
            if (attempts > 0)
                cout << "密码错误，请重试" << endl;
            else
                cout << "账户已锁定" << endl;
        }
    }

    return 0;
}
```

### do-while循环

#### 基本语法
```cpp
do {
    // 循环体
} while (条件表达式);
```

#### 特点
1. 先执行循环体，再判断条件
2. 循环体至少执行一次
3. 注意结尾的分号

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    // 计算用户输入数字的位数
    int num, count = 0;
    cout << "请输入一个正整数: ";
    cin >> num;
    
    int temp = num;
    do {
        temp /= 10;
        count++;
    } while (temp != 0);
    
    cout << num << " 是 " << count << " 位数" << endl;

    // 菜单选择
    char choice;
    do {
        cout << "\n请选择操作:" << endl;
        cout << "1. 查询余额" << endl;
        cout << "2. 存款" << endl;
        cout << "3. 取款" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入选项: ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                cout << "余额查询中..." << endl;
                break;
            case '2':
                cout << "存款操作..." << endl;
                break;
            case '3':
                cout << "取款操作..." << endl;
                break;
            case '0':
                cout << "感谢使用，再见！" << endl;
                break;
            default:
                cout << "无效选项，请重新输入" << endl;
        }
    } while (choice != '0');

    return 0;
}
```

### for循环

#### 基本语法
```cpp
for (初始化语句; 条件表达式; 更新语句) {
    // 循环体
}
```

### 执行流程
1. 执行初始化语句
2. 检查条件表达式，如果为false则退出循环
3. 执行循环体
4. 执行更新语句
5. 回到第2步

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    // 计算1到100的偶数和
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    cout << "1到100的偶数和是: " << sum << endl;

    // 九九乘法表
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "×" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }

    // for循环的变体
    // 1. 省略初始化
    int i = 0;
    for (; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 2. 省略条件和更新(相当于while(true))
    for (;;) {
        cout << "无限循环，按Ctrl+C退出" << endl;
        break; // 这里只是为了演示，实际不会立即退出
    }

    // 3. 多个变量
    for (int x = 0, y = 10; x < y; x++, y--) {
        cout << "x=" << x << ", y=" << y << endl;
    }

    return 0;
}
```

### 范围for循环(C++11)

#### 基本语法
```cpp
for (声明 : 表达式) {
    // 循环体
}
```

#### 特点
1. 用于遍历序列(数组、容器等)
2. 更简洁，不易出错
3. 不能直接获取当前元素的索引

#### 示例代码
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 遍历数组
    int arr[] = {1, 2, 3, 4, 5};
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // 遍历字符串
    string str = "Hello, C++11";
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;

    // 使用auto自动推导类型
    vector<double> vec = {1.1, 2.2, 3.3, 4.4};
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 修改元素需要使用引用
    for (auto &val : vec) {
        val *= 2;
    }
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 遍历初始化列表
    for (int x : {10, 20, 30, 40}) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### break与continue语句

#### break语句
1. 用于立即退出当前循环或switch语句
2. 只能跳出一层循环

#### continue语句
1. 跳过当前循环的剩余部分，直接进入下一次循环
2. 在for循环中，会先执行更新语句，再检查条件

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    // break示例
    cout << "break示例:" << endl;
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        cout << i << " ";
    }
    cout << "\n循环结束" << endl;

    // continue示例
    cout << "\ncontinue示例:" << endl;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        cout << i << " ";
    }
    cout << "\n循环结束" << endl;

    // 多层循环中的break
    cout << "\n多层循环中的break:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                break;  // 只跳出内层循环
            }
            cout << "i=" << i << ", j=" << j << endl;
        }
    }

    // 查找质数
    cout << "\n100以内的质数:" << endl;
    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}
```

### goto语句(慎用)

#### 基本语法
```cpp
goto 标签;
// ...
标签:
    // 代码
```

#### 注意事项
1. 会破坏程序的结构化，降低可读性
2. 可能导致难以发现的错误
3. 只在极少数情况下使用(如多层嵌套循环中一次性跳出)

#### 示例代码
```cpp
#include <iostream>
using namespace std;

int main() {
    // 不推荐的使用方式
    int i = 0;
start:
    cout << i << " ";
    i++;
    if (i < 10) {
        goto start;
    }
    cout << "\n循环结束" << endl;

    // 可能合理的用法: 从多层嵌套中跳出
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                cout << x << "," << y << "," << z << endl;
                if (x == 2 && y == 2 && z == 2) {
                    goto exit_all_loops;
                }
            }
        }
    }
exit_all_loops:
    cout << "已跳出所有循环" << endl;

    // 错误示例: 跳过变量初始化
    /*
    goto skip;
    int a = 10;  // 跳过这个初始化会导致未定义行为
skip:
    cout << a << endl;  // 错误
    */

    return 0;
}
```

### 流程控制最佳实践

1. **选择适当的控制结构**：
   - 条件判断用if-else或switch
   - 已知循环次数用for
   - 未知循环次数用while或do-while
   - 遍历容器用范围for

2. **避免深层嵌套**：
   - 嵌套超过3层考虑重构
   - 可以使用函数提取部分逻辑

3. **循环控制**：
   - 明确循环终止条件
   - 避免无限循环(除非确实需要)
   - 修改循环变量要谨慎

4. **代码可读性**：
   - 即使单语句也使用大括号
   - 适当使用空格和缩进
   - 复杂的条件表达式可以拆分成多个变量

5. **性能考虑**：
   - 将最可能成立的条件放在前面
   - 循环中避免不必要的计算
   - 考虑循环展开等优化技术(在性能关键代码中)

6. **异常处理**：
   - 不要用流程控制处理异常情况
   - 应该使用try-catch机制

7. **现代C++特性**：
   - 优先使用范围for代替传统for
   - 考虑使用算法库代替手写循环
   - 使用constexpr if(C++17)进行编译期条件判断

#### 示例：重构深层嵌套代码
```cpp
// 重构前
void processData() {
    if (condition1) {
        for (int i = 0; i < n; i++) {
            if (condition2) {
                while (condition3) {
                    if (condition4) {
                        // 复杂逻辑
                    }
                }
            }
        }
    }
}

// 重构后
void handleCondition4() {
    // 提取condition4的处理逻辑
}

void processInnerLoop() {
    while (condition3) {
        if (condition4) {
            handleCondition4();
        }
    }
}

void processData() {
    if (!condition1) return;
    
    for (int i = 0; i < n; i++) {
        if (!condition2) continue;
        processInnerLoop();
    }
}
```