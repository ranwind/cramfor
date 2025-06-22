# C++核心概念详解

## 1. 函数

### 函数定义与声明
函数是完成特定任务的独立代码块，由返回类型、函数名、参数列表和函数体组成。

```cpp
// 函数声明（原型）
int add(int a, int b);

// 函数定义
int add(int a, int b) {
    return a + b;
}
```

### 函数参数传递
C++支持三种参数传递方式：
1. 值传递：创建参数的副本
2. 引用传递：直接操作原变量
3. 指针传递：通过地址操作原变量

```cpp
// 值传递
void swap_val(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 引用传递
void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 指针传递
void swap_ptr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### 函数返回值
函数可以返回一个值，也可以不返回（void）。C++11引入了尾置返回类型。

```cpp
// 传统返回类型
int multiply(int x, int y) {
    return x * y;
}

// 尾置返回类型(C++11)
auto divide(double x, double y) -> double {
    return x / y;
}
```

### 函数重载
同一作用域内，函数名相同但参数列表不同的多个函数构成重载。

```cpp
void print(int i) {
    cout << "整数: " << i << endl;
}

void print(double f) {
    cout << "浮点数: " << f << endl;
}

void print(const string& s) {
    cout << "字符串: " << s << endl;
}
```

### 默认参数
函数参数可以有默认值，调用时可省略这些参数。

```cpp
void createWindow(int width=800, int height=600, string title="My App") {
    // 创建窗口
}
```

### 内联函数
使用`inline`关键字建议编译器将函数代码直接插入调用处，减少函数调用开销。

```cpp
inline int max(int a, int b) {
    return a > b ? a : b;
}
```

### 递归函数
函数直接或间接调用自身称为递归。

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

### 函数指针
指向函数的指针变量，可用于回调机制。

```cpp
int compute(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

// 使用
int result = compute(5, 3, add); // 8
```

### lambda表达式(C++11)
匿名函数对象，常用于STL算法。

```cpp
auto sum = [](int a, int b) { return a + b; };
cout << sum(2, 3); // 5

vector<int> nums {1, 2, 3, 4, 5};
int count = count_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
```

## 2. 数组与字符串

### 一维数组与多维数组
数组是相同类型元素的集合，存储在连续内存中。

```cpp
// 一维数组
int arr1[5] = {1, 2, 3, 4, 5};

// 二维数组
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### 数组的初始化与遍历
数组有多种初始化方式，可通过循环遍历。

```cpp
// 初始化
double temps[5] = {20.5, 22.0, 18.5}; // 后两个元素为0

// 遍历
for (int i = 0; i < 5; i++) {
    cout << temps[i] << " ";
}

// 范围for循环(C++11)
for (double temp : temps) {
    cout << temp << " ";
}
```

### 数组作为函数参数
数组作为参数传递时退化为指针，通常需要传递大小。

```cpp
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```

### C风格字符串
以空字符'\0'结尾的字符数组。

```cpp
char str1[] = "Hello"; // 自动添加'\0'
char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// 常用函数
#include <cstring>
strlen(str1); // 长度
strcpy(str2, str1); // 复制
strcat(str1, " World"); // 连接
```

### C++ string类
更安全、更强大的字符串处理类。

```cpp
#include <string>
string s1 = "Hello";
string s2 = "World";

// 常用操作
s1.length(); // 长度
s1 + " " + s2; // 连接
s1.substr(1, 3); // 子串
s1.find("ell"); // 查找
```

### 原始字符串字面量(C++11)
避免转义字符的麻烦。

```cpp
string path = R"(C:\Program Files\MyApp\config.ini)";
string html = R"(
<html>
    <body>
        <p>Hello World</p>
    </body>
</html>
)";
```

## 3. 指针与引用

### 指针的概念与声明
指针是存储内存地址的变量。

```cpp
int num = 10;
int *p = &num; // p指向num的地址
cout << *p; // 解引用，输出10
```

### 指针运算
指针支持加减运算，移动的是所指向类型的大小。

```cpp
int arr[] = {10, 20, 30};
int *p = arr;
cout << *(p + 1); // 20
```

### 指针与数组
数组名在多数情况下会退化为指向首元素的指针。

```cpp
int arr[3] = {1, 2, 3};
int *p = arr; // 等价于 &arr[0]
```

### const指针与指向const的指针
```cpp
int num = 5;
const int *p1 = &num; // 指向const的指针，不能通过p1修改num
int *const p2 = &num; // const指针，p2不能指向其他地址
const int *const p3 = &num; // 指向const的const指针
```

### 引用概念
引用是变量的别名，必须初始化且不能改变绑定。

```cpp
int x = 10;
int &ref = x; // ref是x的引用
ref = 20; // x现在为20
```

### 指针与引用的区别
1. 引用必须初始化，指针可以不初始化
2. 引用不能改变绑定，指针可以改变指向
3. 引用更安全，指针更灵活
4. 引用没有空值，指针可以有nullptr

### 动态内存分配(new与delete)
在堆上分配内存，必须手动释放。

```cpp
int *p = new int; // 分配一个int
*p = 10;
delete p;

int *arr = new int[5]; // 分配数组
delete[] arr;
```

### 智能指针简介(C++11)
自动管理内存，防止内存泄漏。

```cpp
#include <memory>
unique_ptr<int> p1(new int(10)); // 独占所有权
shared_ptr<int> p2 = make_shared<int>(20); // 共享所有权
weak_ptr<int> p3(p2); // 不增加引用计数
```

## 4. 结构体与枚举

### 结构体定义与使用
结构体是用户自定义的复合数据类型。

```cpp
struct Point {
    double x;
    double y;
};

Point p1;
p1.x = 3.5;
p1.y = 2.8;
```

### 结构体数组
```cpp
Point points[3] = {
    {1.0, 2.0},
    {3.0, 4.0},
    {5.0, 6.0}
};
```

### 结构体指针
```cpp
Point p = {1.0, 2.0};
Point *ptr = &p;
cout << ptr->x; // 1.0
```

### 结构体作为函数参数
```cpp
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
```

### 枚举类型
```cpp
enum Color { RED, GREEN, BLUE };
Color c = GREEN;
```

### 强类型枚举(C++11)
解决传统枚举的问题：作用域污染和隐式转换。

```cpp
enum class Color { RED, GREEN, BLUE };
Color c = Color::GREEN;

enum class Pixel : uint8_t { RED = 255, GREEN = 255, BLUE = 255 }; // 指定底层类型
```

## 5. 面向对象编程基础

### 类与对象的概念
类是对象的蓝图，对象是类的实例。

### 类的定义与实现
```cpp
class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }
    void setWidth(double w) { width = w; }
};
```

### 访问控制
- public: 任何代码都可访问
- private: 仅类成员和友元可访问
- protected: 类成员、派生类和友元可访问

### 构造函数与析构函数
```cpp
class Student {
    string name;
    int age;
public:
    Student() : name(""), age(0) {} // 默认构造
    Student(string n, int a) : name(n), age(a) {} // 参数化构造
    ~Student() { cout << "Destructor called"; } // 析构函数
};
```

### this指针
指向当前对象的指针，用于区分成员和局部变量。

```cpp
class Person {
    string name;
public:
    void setName(string name) {
        this->name = name; // 使用this区分
    }
};
```

### 静态成员
属于类而非对象的成员。

```cpp
class Counter {
    static int count; // 声明
public:
    Counter() { count++; }
    static int getCount() { return count; }
};
int Counter::count = 0; // 定义并初始化
```

### 友元函数与友元类
允许非成员函数或其他类访问私有成员。

```cpp
class Box {
    double width;
public:
    friend void printWidth(Box box); // 友元函数
    friend class BoxPrinter; // 友元类
};

void printWidth(Box box) {
    cout << box.width; // 可以访问私有成员
}
```

### 对象数组与对象指针
```cpp
Rectangle rects[3] = {
    Rectangle(1, 2),
    Rectangle(3, 4),
    Rectangle(5, 6)
};

Rectangle *ptr = &rects[0];
cout << ptr->area();
```

以上是C++核心概念的详细讲解和示例代码，涵盖了函数、数组与字符串、指针与引用、结构体与枚举以及面向对象编程基础等关键内容。