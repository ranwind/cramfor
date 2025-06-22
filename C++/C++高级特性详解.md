# C++高级特性详解

## 1. 面向对象高级特性

### 继承的概念与实现
继承是面向对象编程的重要特性，允许派生类继承基类的特性并扩展新功能。

```cpp
class Shape {  // 基类
protected:
    int width, height;
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
};

class Rectangle: public Shape {  // 派生类
public:
    int getArea() { return width * height; }
};
```

### 继承中的访问控制
继承方式影响基类成员在派生类中的访问权限：

| 基类成员访问 | 公有继承 | 保护继承 | 私有继承 |
|--------------|----------|----------|----------|
| public       | public   | protected| private  |
| protected    | protected| protected| private  |
| private      | 不可访问 | 不可访问 | 不可访问 |

```cpp
class Base {
public:
    int publicMember;
protected:
    int protectedMember;
private:
    int privateMember;
};

class PublicDerived : public Base {
    // publicMember是public
    // protectedMember是protected
    // privateMember不可访问
};

class ProtectedDerived : protected Base {
    // publicMember和protectedMember都是protected
    // privateMember不可访问
};

class PrivateDerived : private Base {
    // publicMember和protectedMember都是private
    // privateMember不可访问
};
```

### 派生类构造与析构
派生类构造函数需要初始化基类子对象，构造和析构顺序如下：
1. 基类构造函数
2. 派生类成员构造函数
3. 派生类构造函数体
4. 派生类析构函数
5. 派生类成员析构函数
6. 基类析构函数

```cpp
class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};
```

### 多重继承
一个类可以继承多个基类，可能导致菱形继承问题。

```cpp
class Worker {
public:
    void work() { cout << "Working" << endl; }
};

class Student {
public:
    void study() { cout << "Studying" << endl; }
};

class WorkingStudent : public Worker, public Student {
};

// 菱形继承问题
class A { public: int data; };
class B : public A {};
class C : public A {};
class D : public B, public C {};  // D中有两份A的副本
```

### 虚函数与多态
虚函数实现运行时多态，通过基类指针或引用调用派生类实现。

```cpp
class Animal {
public:
    virtual void speak() { cout << "Animal sound" << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow!" << endl; }
};

// 使用多态
Animal* animals[2] = {new Dog(), new Cat()};
for (Animal* a : animals) {
    a->speak();  // 调用各自派生类的实现
}
```

### 抽象类与纯虚函数
包含纯虚函数的类是抽象类，不能实例化。

```cpp
class Shape {
public:
    virtual double area() = 0;  // 纯虚函数
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14 * radius * radius; }
};
```

### 虚析构函数
基类析构函数应声明为虚函数，确保通过基类指针删除派生类对象时正确调用派生类析构函数。

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() override { cout << "Derived destructor" << endl; }
};

Base* b = new Derived();
delete b;  // 正确调用Derived和Base的析构函数
```

### 运行时类型识别(RTTI)
dynamic_cast和typeid用于运行时类型检查。

```cpp
class Base { virtual void foo() {} };
class Derived : public Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);  // 安全向下转型

if (typeid(*b) == typeid(Derived)) {
    cout << "b points to a Derived object" << endl;
}
```

### final与override关键字(C++11)
- final: 禁止类被继承或虚函数被重写
- override: 显式声明重写虚函数

```cpp
class Base final {};  // 不能被继承

class Animal {
public:
    virtual void speak() {}
};

class Dog : public Animal {
public:
    void speak() override final {}  // 必须重写且不能被进一步重写
};

class Bulldog : public Dog {
    // void speak() {}  // 错误，不能重写final函数
};
```

## 2. 运算符重载

### 运算符重载的概念
通过operator关键字为类定义运算符行为。

```cpp
class Complex {
    double real, imag;
public:
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

### 成员函数重载与友元函数重载
大多数运算符可以重载为成员函数或友元函数。

```cpp
// 成员函数重载
class Vector {
public:
    Vector operator+(const Vector& other) const;
};

// 友元函数重载
class Matrix {
    friend Matrix operator+(const Matrix& a, const Matrix& b);
};
```

### 常用运算符重载
```cpp
class Fraction {
    int num, den;
public:
    // 算术运算符
    Fraction operator+(const Fraction& other) const {
        return Fraction(num*other.den + other.num*den, den*other.den);
    }
    
    // 比较运算符
    bool operator==(const Fraction& other) const {
        return num*other.den == other.num*den;
    }
    
    // 递增运算符
    Fraction& operator++() {  // 前置++
        num += den;
        return *this;
    }
    
    Fraction operator++(int) {  // 后置++
        Fraction temp = *this;
        ++(*this);
        return temp;
    }
};
```

### 输入输出运算符重载
通常重载为友元函数。

```cpp
class Student {
    string name;
    int age;
public:
    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};

ostream& operator<<(ostream& os, const Student& s) {
    os << "Name: " << s.name << ", Age: " << s.age;
    return os;
}

istream& operator>>(istream& is, Student& s) {
    is >> s.name >> s.age;
    return is;
}
```

### 函数调用运算符重载
使对象可以像函数一样调用。

```cpp
class Adder {
    int sum = 0;
public:
    int operator()(int x) {
        sum += x;
        return sum;
    }
};

Adder add;
cout << add(10);  // 10
cout << add(20);  // 30
```

### 类型转换运算符重载
定义类到其他类型的隐式或显式转换。

```cpp
class Rational {
    int num, den;
public:
    operator double() const {  // 隐式转换
        return static_cast<double>(num) / den;
    }
    
    explicit operator bool() const {  // 显式转换(C++11)
        return num != 0;
    }
};

Rational r(1, 2);
double d = r;  // 隐式转换为0.5
if (static_cast<bool>(r)) {}  // 显式转换为bool
```

## 3. 模板与泛型编程

### 函数模板
编写与类型无关的通用函数。

```cpp
template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

// 使用
cout << max(10, 20);  // 20
cout << max(3.14, 2.71);  // 3.14
```

### 类模板
定义通用类，成员可以是任意类型。

```cpp
template <typename T>
class Stack {
    vector<T> elements;
public:
    void push(const T& elem) {
        elements.push_back(elem);
    }
    T pop() {
        T elem = elements.back();
        elements.pop_back();
        return elem;
    }
};

Stack<int> intStack;
Stack<string> stringStack;
```

### 模板参数
模板可以有类型参数和非类型参数。

```cpp
template <typename T, int size>
class Array {
    T data[size];
public:
    T& operator[](int index) {
        return data[index];
    }
};

Array<double, 10> arr;
```

### 模板特化与偏特化
为特定类型提供特殊实现。

```cpp
// 全特化
template <>
class Stack<bool> {
    // 位级实现
};

// 偏特化
template <typename T>
class Stack<T*> {
    // 指针类型的特殊处理
};
```

### 可变参数模板(C++11)
接受任意数量参数的模板。

```cpp
template <typename... Args>
void print(Args... args) {
    (cout << ... << args) << endl;  // 折叠表达式(C++17)
}

print(1, "hello", 3.14);  // 1hello3.14
```

### 模板元编程简介
在编译期执行的计算。

```cpp
template <int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

cout << Factorial<5>::value;  // 120 (编译期计算)
```

### 类型推导(auto与decltype)
自动推导变量或表达式类型。

```cpp
auto x = 10;  // int
auto y = 3.14;  // double

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}
```

### 别名模板(C++11)
为模板创建别名。

```cpp
template <typename T>
using Vec = std::vector<T>;

Vec<int> v;  // std::vector<int>
```

## 4. 异常处理

### 异常处理机制
try-throw-catch结构处理运行时错误。

```cpp
try {
    if (error) throw runtime_error("Something went wrong");
} catch (const runtime_error& e) {
    cerr << "Error: " << e.what() << endl;
}
```

### try-catch块
可以捕获多种异常类型。

```cpp
try {
    // 可能抛出异常的代码
} catch (const invalid_argument& e) {
    // 处理无效参数异常
} catch (const out_of_range& e) {
    // 处理越界异常
} catch (...) {
    // 处理所有其他异常
}
```

### 异常规格说明
C++11引入noexcept替代动态异常规范。

```cpp
void func() noexcept {  // 保证不抛出异常
    // ...
}

void mightThrow() noexcept(false) {  // 可能抛出异常
    // ...
}
```

### 标准异常类
标准库定义的异常类层次结构：

- exception
  - logic_error
    - invalid_argument
    - domain_error
    - length_error
    - out_of_range
  - runtime_error
    - range_error
    - overflow_error
    - underflow_error
    - system_error

### 自定义异常类
从标准异常类派生自定义异常。

```cpp
class MyException : public std::exception {
    string msg;
public:
    MyException(const string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
```

### noexcept关键字(C++11)
指示函数是否会抛出异常。

```cpp
void safeFunction() noexcept {
    // 保证不会抛出异常
}

void unsafeFunction() noexcept(false) {
    // 可能抛出异常
}
```

## 5. 标准模板库(STL)

### STL概述与组成
STL六大组件：
1. 容器(Containers)
2. 算法(Algorithms)
3. 迭代器(Iterators)
4. 函数对象(Functors)
5. 适配器(Adapters)
6. 分配器(Allocators)

### 容器概述
序列容器：
- vector: 动态数组
- deque: 双端队列
- list: 双向链表
- forward_list: 单向链表(C++11)
- array: 固定大小数组(C++11)

关联容器：
- set: 唯一键集合
- multiset: 键集合
- map: 键值对
- multimap: 键可重复的map

无序关联容器(C++11):
- unordered_set
- unordered_multiset
- unordered_map
- unordered_multimap

### 迭代器概念与分类
迭代器类别：
- 输入迭代器
- 输出迭代器
- 前向迭代器
- 双向迭代器
- 随机访问迭代器

```cpp
vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### 算法概述
STL提供约100种算法，如排序、搜索、修改等。

```cpp
vector<int> v = {5, 3, 1, 4, 2};
sort(v.begin(), v.end());  // 排序
auto it = find(v.begin(), v.end(), 3);  // 查找
reverse(v.begin(), v.end());  // 反转
```

### 函数对象(functor)
重载了operator()的类对象。

```cpp
struct Square {
    int operator()(int x) const { return x * x; }
};

vector<int> v = {1, 2, 3};
transform(v.begin(), v.end(), v.begin(), Square());
// v变为{1, 4, 9}
```

### 适配器
容器适配器提供特殊接口。

```cpp
stack<int> s;  // 后进先出
s.push(1);
s.push(2);
cout << s.top();  // 2

queue<int> q;  // 先进先出
q.push(1);
q.push(2);
cout << q.front();  // 1

priority_queue<int> pq;  // 优先级队列
pq.push(3);
pq.push(1);
pq.push(4);
cout << pq.top();  // 4
```

以上内容详细介绍了C++的高级特性，包括面向对象高级特性、运算符重载、模板与泛型编程、异常处理和标准模板库(STL)等核心概念，每个部分都配有详细的示例代码和解释。