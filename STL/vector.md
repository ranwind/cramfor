# Vector

# 一、 Vector 基础阶段
## 1. Vector 基础概念

### 1.1 什么是 vector？
`vector` 是 C++ 标准模板库(STL)中的序列容器，可以看作是一个动态数组。它能够自动管理内存，在运行时根据需要动态调整大小。

### 1.2 vector 与普通数组的区别

| 特性            | 普通数组                     | vector                     |
|----------------|----------------------------|---------------------------|
| 大小            | 固定大小，编译时确定             | 动态大小，运行时可变           |
| 内存管理         | 手动管理                      | 自动管理                    |
| 边界检查         | 无(可能越界)                  | 可通过`at()`进行边界检查       |
| 功能            | 基本功能                      | 提供丰富成员函数(排序、插入等)   |

### 1.3 头文件与模板声明
使用 vector 需要包含头文件：
```cpp
#include <vector>
```

vector 的模板声明形式为：
```cpp
template <class T, class Allocator = allocator<T>> 
class vector;
```
其中 `T` 是存储元素的类型，`Allocator` 是内存分配器(通常使用默认值)。

## 2. Vector 基本操作

### 2.1 创建与初始化

```cpp
// 1. 创建空vector
vector<int> v1;

// 2. 创建指定大小的vector，元素默认初始化
vector<int> v2(5);  // 5个0

// 3. 创建指定大小和初始值的vector
vector<int> v3(5, 10);  // 5个10

// 4. 通过初始化列表创建
vector<int> v4 = {1, 2, 3, 4, 5};

// 5. 通过数组创建
int arr[] = {1, 2, 3};
vector<int> v5(arr, arr + 3);

// 6. 通过另一个vector创建(拷贝构造)
vector<int> v6(v4);
```

### 2.2 访问元素

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// 1. 使用[]运算符访问(不检查边界)
cout << v[2];  // 输出30

// 2. 使用at()成员函数访问(会检查边界)
cout << v.at(2);  // 输出30
// v.at(10);  // 抛出std::out_of_range异常

// 3. 访问第一个元素
cout << v.front();  // 输出10

// 4. 访问最后一个元素
cout << v.back();   // 输出50

// 5. 使用迭代器访问
for(auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### 2.3 获取大小信息

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 1. 获取当前元素数量
cout << v.size();  // 输出5

// 2. 获取当前分配的存储空间能容纳的元素数
cout << v.capacity();  // 输出可能大于等于5的值

// 3. 检查是否为空
cout << boolalpha << v.empty();  // 输出false

// 4. 获取最大可能的大小
cout << v.max_size();  // 输出一个很大的数

// 示例：遍历vector
for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}
```

### 2.4 注意事项
1. `size()` 返回的是当前存储的元素数量，而 `capacity()` 返回的是已分配的内存能容纳的元素数量
2. `[]` 运算符不进行边界检查，访问越界会导致未定义行为
3. `at()` 会进行边界检查，越界时抛出 `std::out_of_range` 异常
4. `front()` 和 `back()` 在空vector上调用是未定义行为


## **3. 增删改查操作详解**

接下来我们详细讲解 `vector` 的 **增删改查** 操作，并提供代码示例。

---

###  **3.1 添加元素**
#### **(1) `push_back()`**
在 `vector` 末尾添加一个元素：
```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);  // v = {1, 2, 3, 4}
```

#### **(2) `emplace_back()`**
比 `push_back()` 更高效，直接在容器内构造元素（避免拷贝）：
```cpp
vector<string> names;
names.emplace_back("Alice");  // 直接构造，不拷贝
names.emplace_back("Bob");    // names = {"Alice", "Bob"}
```

#### **(3) `insert()`**
在指定位置插入元素：
```cpp
vector<int> v = {1, 2, 4};
v.insert(v.begin() + 2, 3);  // v = {1, 2, 3, 4}
```

**插入多个元素：**
```cpp
v.insert(v.begin() + 1, 3, 5);  // 在位置1插入3个5
```

**插入另一个 `vector` 的元素：**
```cpp
vector<int> v2 = {10, 20};
v.insert(v.end(), v2.begin(), v2.end());  // 在末尾插入v2
```

---

### **3.2 删除元素**
#### **(1) `pop_back()`**
删除最后一个元素：
```cpp
vector<int> v = {1, 2, 3};
v.pop_back();  // v = {1, 2}
```

#### **(2) `erase()`**
删除指定位置的元素：
```cpp
vector<int> v = {1, 2, 3, 4};
v.erase(v.begin() + 1);  // 删除第2个元素，v = {1, 3, 4}
```

**删除一个范围：**
```cpp
v.erase(v.begin() + 1, v.begin() + 3);  // 删除第2~3个元素
```

#### **(3) `clear()`**
清空整个 `vector`：
```cpp
vector<int> v = {1, 2, 3};
v.clear();  // v = {}
```

---

### **3.3 修改元素**
#### **(1) `assign()`**
重新赋值 `vector`：
```cpp
vector<int> v;
v.assign(5, 10);  // v = {10, 10, 10, 10, 10}
```

**用另一个 `vector` 赋值：**
```cpp
vector<int> v2 = {1, 2, 3};
v.assign(v2.begin(), v2.end());  // v = {1, 2, 3}
```

#### **(2) `resize()`**
调整 `vector` 的大小：
```cpp
vector<int> v = {1, 2, 3};
v.resize(5);  // v = {1, 2, 3, 0, 0}（默认填充0）
v.resize(2);  // v = {1, 2}（截断）
```

**指定填充值：**
```cpp
v.resize(5, 99);  // v = {1, 2, 99, 99, 99}
```

---

### **3.4 查找元素**
#### **(1) 使用 `find()`（需 `<algorithm>`）**
```cpp
vector<int> v = {1, 2, 3, 4, 5};
auto it = find(v.begin(), v.end(), 3);  // 查找3
if (it != v.end()) {
    cout << "Found at position: " << it - v.begin();  // 输出2
} else {
    cout << "Not found";
}
```

#### **(2) 使用 `count()`（统计出现次数）**
```cpp
vector<int> v = {1, 2, 2, 3, 2};
int cnt = count(v.begin(), v.end(), 2);  // cnt = 3
```

---

### **总结**
| **操作** | **方法** | **示例** |
|----------|----------|----------|
| **添加** | `push_back()` | `v.push_back(10);` |
|          | `emplace_back()` | `v.emplace_back("Alice");` |
|          | `insert()` | `v.insert(v.begin(), 5);` |
| **删除** | `pop_back()` | `v.pop_back();` |
|          | `erase()` | `v.erase(v.begin());` |
|          | `clear()` | `v.clear();` |
| **修改** | `assign()` | `v.assign(3, 100);` |
|          | `resize()` | `v.resize(5);` |
| **查找** | `find()` | `find(v.begin(), v.end(), 3);` |

这些操作是 `vector` 的核心功能，掌握它们可以高效管理动态数组！ 🚀



# 二、 C++ Vector 进阶指南

## 1. 内存管理与性能优化

### `reserve()` 与 `shrink_to_fit()`

**`reserve(size_type n)`**:
- 预分配内存空间，避免多次扩容
- 不影响 `size()`，只影响 `capacity()`

```cpp
vector<int> v;
v.reserve(1000);  // 预分配1000个元素的空间
cout << v.capacity();  // 输出1000
cout << v.size();      // 输出0
```

**`shrink_to_fit()`**:
- 请求移除未使用的容量，使 `capacity()` 接近 `size()`
- 实现可能忽略此请求（非强制）

```cpp
vector<int> v(100);
v.resize(10);
v.shrink_to_fit();  // 可能减少capacity到接近10
```

### 1.1 迭代器失效问题

**导致失效的操作**:
- `push_back()`/`emplace_back()` (可能导致重新分配)
- `insert()`/`erase()`
- `resize()`/`clear()`

**安全示例**:
```cpp
vector<int> v = {1,2,3};
auto it = v.begin() + 1;
v.insert(it, 4);  // it失效！不能再使用

// 正确做法：重新获取迭代器
it = v.begin() + 1;
*it = 5;  // 安全
```

### 1.2 移动语义与 `emplace_back` 优化

**移动语义**:
```cpp
vector<string> v;
string s = "hello";
v.push_back(std::move(s));  // 移动而非拷贝
// s现在处于有效但未指定状态
```

**`emplace_back` 优势**:
- 直接在容器内构造对象，避免临时对象创建
- 比 `push_back` 更高效

```cpp
vector<pair<int, string>> v;
v.emplace_back(1, "test");  // 直接构造pair
// 比 v.push_back(make_pair(1, "test")) 更高效
```

## 2. 迭代器与范围操作

### 2.1 迭代器类型

| 迭代器类型 | 获取方法 | 遍历方向 |
|------------|----------|----------|
| 普通迭代器 | `begin()`/`end()` | 正向 |
| 反向迭代器 | `rbegin()`/`rend()` | 反向 |
| 常量迭代器 | `cbegin()`/`cend()` | 正向不可修改 |

**示例**:
```cpp
vector<int> v = {1,2,3,4};

// 正向遍历
for(auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// 反向遍历
for(auto rit = v.rbegin(); rit != v.rend(); ++rit) {
    cout << *rit << " ";
}
```

### 2.2 范围构造与赋值

**范围构造**:
```cpp
int arr[] = {1,2,3,4,5};
vector<int> v(arr, arr + 3);  // v = {1,2,3}
```

**范围赋值**:
```cpp
vector<int> v1 = {1,2,3};
vector<int> v2;
v2.assign(v1.begin(), v1.end());  // v2 = {1,2,3}
```

**移动语义**:
```cpp
vector<int> v1 = {1,2,3};
vector<int> v2(std::move(v1));  // v1现在为空
```

### 2.3 `std::algorithm` 结合使用

**排序**:
```cpp
vector<int> v = {3,1,4,2};
sort(v.begin(), v.end());  // v = {1,2,3,4}
```

**查找**:
```cpp
auto it = find(v.begin(), v.end(), 3);
if(it != v.end()) {
    cout << "Found at position: " << distance(v.begin(), it);
}
```

**拷贝**:
```cpp
vector<int> src = {1,2,3};
vector<int> dest(3);
copy(src.begin(), src.end(), dest.begin());
```

## 3. 特殊用法与技巧

### 3.1 二维 `vector`

**初始化**:
```cpp
vector<vector<int>> matrix(3, vector<int>(4));  // 3x4矩阵
vector<vector<int>> triangle = {{1}, {1,2}, {1,2,3}};
```

**访问元素**:
```cpp
matrix[1][2] = 5;  // 第2行第3列
```

**遍历**:
```cpp
for(const auto& row : matrix) {
    for(int val : row) {
        cout << val << " ";
    }
    cout << endl;
}
```

### 3.2 自定义分配器

**基本用法**:
```cpp
vector<int, MyAllocator<int>> v;
```

**示例分配器**:
```cpp
template<typename T>
class SimpleAllocator {
public:
    using value_type = T;
    
    T* allocate(size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(T* p, size_t) {
        ::operator delete(p);
    }
};

vector<int, SimpleAllocator<int>> v;
```

### 3.3 `vector<bool>` 的优化与陷阱

**优化**:
- 每个bool只占1bit，节省内存

**问题**:
- 不是标准容器，`operator[]` 返回代理对象
- 不能取元素地址
- 与其他容器行为不一致

**解决方案**:
```cpp
vector<char> flags(100);  // 替代方案
// 或
vector<int> flags(100);
// 或使用 bitset 如果大小固定
```

**`vector<bool>` 特殊操作**:
```cpp
vector<bool> v = {true, false, true};
v.flip();  // 翻转所有位
bool b = v[1];  // 返回代理对象
```

## 4. 性能优化技巧

1. **预分配内存**:
```cpp
vector<int> v;
v.reserve(1000);  // 避免多次扩容
```

2. **使用 `emplace_back` 替代 `push_back`**:
```cpp
v.emplace_back(args...);  // 更高效
```

3. **避免不必要的拷贝**:
```cpp
vector<string> v;
string s = "data";
v.push_back(std::move(s));  // 移动而非拷贝
```

4. **批量操作优于单元素操作**:
```cpp
// 差: 多次插入
for(int i = 0; i < 100; ++i) {
    v.push_back(i);
}

// 好: 批量插入
v.insert(v.end(), data.begin(), data.end());
```

5. **选择合适的容器**:
- 需要随机访问 → `vector`
- 频繁插入删除 → `list`/`deque`
- 键值对 → `unordered_map`



# 三、 C++ Vector 高级应用指南

## 1. 底层实现与源码分析

### 1.1 `vector` 的动态扩容机制

**扩容策略**：
- 大多数实现采用 **2倍扩容** 策略（VS 1.5倍）
- 扩容时分配新内存 → 拷贝元素 → 释放旧内存

**扩容示例**：
```cpp
vector<int> v;
for(int i=0; i<10; ++i) {
    v.push_back(i);
    cout << "Size: " << v.size() 
         << " Capacity: " << v.capacity() << endl;
}
/* 典型输出：
Size:1 Capacity:1
Size:2 Capacity:2
Size:3 Capacity:4
Size:5 Capacity:8
Size:9 Capacity:16 */
```

**源码关键部分**（简化）：
```cpp
// 伪代码展示扩容逻辑
void push_back(const T& value) {
    if (size == capacity) {
        new_cap = max(2 * capacity, 1);
        new_data = allocator.allocate(new_cap);
        move_elements(data, data+size, new_data);
        allocator.deallocate(data, capacity);
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = value;
}
```

### 1.2 容器对比

| 特性          | `vector`          | `array`       | `list`         | `deque`         |
|---------------|-------------------|---------------|----------------|-----------------|
| **内存布局**   | 连续内存           | 连续内存       | 非连续节点      | 分块连续内存      |
| **随机访问**   | O(1)              | O(1)          | O(n)           | O(1)            |
| **插入删除**   | 尾部O(1)，其他O(n) | 不支持         | O(1)           | 头尾O(1)，中间O(n)|
| **扩容方式**   | 动态扩容           | 固定大小       | 动态增长        | 动态分块增长      |
| **典型用途**   | 通用动态数组        | 固定大小数组   | 频繁插入删除    | 双端队列         |

### 1.3 自定义 `vector` 实现

**简化版 `vector` 核心实现**：
```cpp
template<typename T>
class SimpleVector {
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    void push_back(const T& value) {
        if(size >= capacity) {
            resize(capacity ? capacity*2 : 1);
        }
        data[size++] = value;
    }

    void resize(size_t new_cap) {
        T* new_data = new T[new_cap];
        for(size_t i=0; i<size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

    ~SimpleVector() { delete[] data; }
    // 其他必要方法...
};
```

## 2. 性能优化与最佳实践

### 2.1 预分配空间优化

**问题**：频繁扩容导致性能下降
```cpp
// 差：多次扩容
vector<int> v;
for(int i=0; i<1'000'000; ++i) {
    v.push_back(i);  // 多次重新分配内存
}
```

**优化方案**：
```cpp
// 好：预分配
vector<int> v;
v.reserve(1'000'000);  // 一次性分配
for(int i=0; i<1'000'000; ++i) {
    v.push_back(i);    // 无扩容开销
}
```

### 2.2 避免频繁 `erase()`

**问题**：中间删除导致元素移动
```cpp
vector<int> v = {1,2,3,4,5,6,7,8,9,10};

// 差：每次erase都移动元素
for(auto it=v.begin(); it!=v.end(); ) {
    if(*it % 2 == 0) {
        it = v.erase(it);  // 删除后返回下一个有效迭代器
    } else {
        ++it;
    }
}
```

**优化方案**：Erase-Remove惯用法
```cpp
v.erase(remove_if(v.begin(), v.end(), 
       [](int x){ return x%2==0; }), v.end());
```

### 2.3 移动语义优化

**拷贝 vs 移动**：
```cpp
vector<string> create_strings() {
    vector<string> v;
    // ...填充数据...
    return v;  // 编译器会优化为移动
}

vector<string> v;
string s = "large string";

// 差：拷贝
v.push_back(s);  

// 好：移动
v.push_back(std::move(s));  // s变为空
```

**`emplace_back` 优化**：
```cpp
vector<pair<int, string>> v;

// 差：构造临时对象
v.push_back(make_pair(1, "hello"));  

// 好：直接构造
v.emplace_back(1, "hello");  
```

## 3. 实际场景应用

### 3.1 游戏实体管理

**ECS架构示例**：
```cpp
struct Position { float x,y; };
struct Velocity { float dx,dy; };

vector<Entity> entities;
vector<Position> positions;
vector<Velocity> velocities;

// 添加实体
entities.push_back(Entity{});
positions.push_back(Position{0,0});
velocities.push_back(Velocity{1,1});

// 游戏循环
for(size_t i=0; i<entities.size(); ++i) {
    positions[i].x += velocities[i].dx;
    positions[i].y += velocities[i].dy;
}
```

### 3.2 算法竞赛技巧

**快速IO优化**：
```cpp
// 禁用同步，加速C++流
ios::sync_with_stdio(false);
cin.tie(nullptr);

vector<int> data;
int n;
cin >> n;
data.resize(n);  // 预分配

// 快速读取
for(int& x : data) cin >> x; 

// 快速排序
sort(data.begin(), data.end());
```

**邻接表表示图**：
```cpp
vector<vector<int>> graph(n);  // n个顶点

// 添加边
graph[u].push_back(v);
graph[v].push_back(u);  // 无向图

// 遍历邻接点
for(int neighbor : graph[u]) {
    // 处理邻居
}
```

### 3.3 多线程并发

**线程安全注意事项**：
```cpp
vector<int> shared_data;
mutex mtx;

// 线程1
{
    lock_guard<mutex> lock(mtx);
    shared_data.push_back(1);
}

// 线程2
{
    lock_guard<mutex> lock(mtx);
    if(!shared_data.empty()) {
        int val = shared_data.back();
    }
}
```

**并行算法**：
```cpp
#include <execution>

vector<int> v(1'000'000);
// 并行排序
sort(std::execution::par, v.begin(), v.end());

// 并行填充
int i = 0;
for_each(std::execution::par, v.begin(), v.end(), 
         [&](int& x){ x = i++; });
```

## 4. 高级技巧

### 4.1 内存池优化

**自定义分配器示例**：
```cpp
template<typename T>
class MemoryPoolAllocator {
    static vector<T*> blocks;
    static vector<T*> free_list;
    
public:
    T* allocate(size_t n) {
        if(n != 1) return static_cast<T*>(::operator new(n*sizeof(T)));
        if(free_list.empty()) {
            T* block = ::operator new(4096);
            blocks.push_back(block);
            for(size_t i=0; i<4096/sizeof(T); ++i) {
                free_list.push_back(block + i);
            }
        }
        T* p = free_list.back();
        free_list.pop_back();
        return p;
    }
    
    void deallocate(T* p, size_t n) {
        if(n != 1) ::operator delete(p);
        else free_list.push_back(p);
    }
};

vector<int, MemoryPoolAllocator<int>> v;
```

### 4.2 异常安全保证

**强异常安全示例**：
```cpp
void safe_insert(vector<string>& v, const string& s) {
    vector<string> temp = v;  // 拷贝
    temp.push_back(s);        // 修改副本
    swap(v, temp);            // 原子交换
}
```

### 4.3 类型擦除存储

**存储任意类型**：
```cpp
vector<any> heterogeneous;
heterogeneous.push_back(42);
heterogeneous.push_back(string("hello"));
heterogeneous.push_back(3.14);

try {
    int i = any_cast<int>(heterogeneous[0]);
    string s = any_cast<string>(heterogeneous[1]);
} catch(const bad_any_cast& e) {
    cerr << "类型错误: " << e.what();
}
```

这些高级技巧展示了 `vector` 在实际工程中的灵活应用，从底层优化到高级并发模式，`vector` 都是现代C++开发中不可或缺的核心组件。



# 四、 C++ Vector 实战训练指南

## 1. LeetCode 典型例题

### 1.1 数组类问题

#### 两数之和 (LeetCode 1)
**问题**：在数组中找到两个数使它们的和等于目标值

**最优解**：使用哈希表存储补数
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for(int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if(num_map.count(complement)) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}
```

#### 滑动窗口最大值 (LeetCode 239)
**问题**：在滑动窗口中找出最大值

**单调队列解法**：
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
        // 移除超出窗口的元素
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        
        // 维护单调递减队列
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        if(i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}
```

### 1.2 动态规划问题

#### 背包问题 (LeetCode 416)
**问题**：将数组分成两个和相等的子集

**DP解法**：
```cpp
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0) return false;
    
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for(int num : nums) {
        for(int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}
```

#### 最长递增子序列 (LeetCode 300)
**最优解**：二分查找+动态规划
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for(int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if(it == dp.end()) dp.push_back(num);
        else *it = num;
    }
    return dp.size();
}
```

### 1.3 模拟题

#### 螺旋矩阵 (LeetCode 54)
**问题**：按螺旋顺序返回矩阵元素

**分层模拟解法**：
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res;
    int up = 0, down = m - 1, left = 0, right = n - 1;
    
    while(true) {
        // 从左到右
        for(int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
        if(++up > down) break;
        
        // 从上到下
        for(int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
        if(--right < left) break;
        
        // 从右到左
        for(int j = right; j >= left; --j) res.push_back(matrix[down][j]);
        if(--down < up) break;
        
        // 从下到上
        for(int i = down; i >= up; --i) res.push_back(matrix[i][left]);
        if(++left > right) break;
    }
    return res;
}
```

## 2. 项目实战建议

### 2.1 实现简化版 `vector`

**核心功能实现**：
```cpp
template<typename T>
class SimpleVector {
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    
    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for(size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    
public:
    SimpleVector() = default;
    
    void push_back(const T& value) {
        if(size >= capacity) {
            reallocate(capacity ? capacity * 2 : 1);
        }
        data[size++] = value;
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    ~SimpleVector() { delete[] data; }
    
    // 添加迭代器支持
    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }
};
```

### 2.2 项目中的优化实践

#### 1. 预分配优化
```cpp
// 在日志处理系统中
vector<LogEntry> processLogs(const string& filename) {
    ifstream file(filename);
    vector<LogEntry> logs;
    
    // 预分配足够空间
    logs.reserve(estimateLogCount(filename));
    
    LogEntry entry;
    while(readLogEntry(file, entry)) {
        logs.push_back(std::move(entry));
    }
    
    // 去除多余容量
    logs.shrink_to_fit();
    return logs;
}
```

#### 2. 结构体优化
```cpp
// 游戏引擎中的实体组件
struct Transform {
    float x, y, z;
    float rotation;
    // 避免使用vector存储小对象
    // 改为:
    // float components[4];
};

vector<Transform> transforms;
transforms.reserve(MAX_ENTITIES);
```

### 2.3 性能对比测试

**测试框架示例**：
```cpp
#include <chrono>
#include <list>
#include <deque>

void testPerformance() {
    const int N = 1000000;
    
    // 测试插入性能
    auto testInsert = [](auto& container) {
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < N; ++i) {
            container.insert(container.begin() + container.size()/2, i);
        }
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    };
    
    // 测试随机访问
    auto testAccess = [](auto& container) {
        int sum = 0;
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < N; ++i) {
            sum += container[i];
        }
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    };
    
    vector<int> vec(N);
    list<int> lst(N);
    deque<int> dq(N);
    
    cout << "中间插入耗时(ms):\n";
    cout << "vector: " << testInsert(vec) << endl;
    cout << "list: " << testInsert(lst) << endl;
    cout << "deque: " << testInsert(dq) << endl;
    
    cout << "\n随机访问耗时(ms):\n";
    cout << "vector: " << testAccess(vec) << endl;
    // list不支持随机访问
    cout << "deque: " << testAccess(dq) << endl;
}
```

**典型测试结果分析**：
1. **插入性能**：
   - `vector`：中间插入最差(O(n))，尾部插入最优(O(1))
   - `list`：任何位置插入都很快(O(1))
   - `deque`：头尾插入快(O(1))，中间插入较慢(O(n))

2. **访问性能**：
   - `vector`：连续内存，缓存友好，访问最快
   - `deque`：分块连续，稍慢于vector
   - `list`：不支持随机访问，遍历很慢


## 实战技巧总结

### 1. 算法竞赛技巧
- **快速IO**：关闭同步，使用`'\n'`代替`endl`
- **预分配**：已知数据量时提前`reserve`
- **二维数组**：优先使用`vector<vector<int>>`，比原生数组更安全

### 2. 工程项目建议
- **内存管理**：监控`vector`的内存使用，避免过度扩容
- **异常安全**：使用swap技巧保证强异常安全
- **线程安全**：需要并发访问时加锁或使用`tbb::concurrent_vector`

### 3. 性能优化方向
- **减少拷贝**：使用移动语义和`emplace_back`
- **选择容器**：根据场景选择`vector`/`list`/`deque`
- **算法优化**：利用`<algorithm>`中的高效实现

通过这些问题和实战训练，可以全面掌握`vector`的各种应用场景和优化技巧，在实际编程中做出更合理的选择和优化。







# 五、 C++ Vector 扩展学习指南

## 1. C++20/23 新特性

### 1.1 `constexpr vector`（编译期动态数组）

**C++20 引入的编译期 `vector`**：
- 允许在编译期进行动态内存分配
- 需要编译器支持C++20的constexpr分配器

**示例**：
```cpp
constexpr auto create_vector() {
    std::vector<int> v;  // C++20起可在constexpr中使用
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    return v;
}

int main() {
    constexpr auto v = create_vector();
    static_assert(v.size() == 3);  // 编译期验证
    static_assert(v[0] == 1);
    return 0;
}
```

**限制**：
- 编译期vector不能泄漏到运行时
- 编译期操作不能抛出异常

### 1.2 `ranges` 库与 `vector` 的结合

**C++20 ranges 的优势**：
- 更简洁的管道式语法
- 惰性求值
- 组合操作

**示例**：
```cpp
#include <ranges>
#include <algorithm>

void process_data(std::vector<int>& data) {
    // 过滤偶数 -> 平方 -> 反转
    auto result = data 
        | std::views::filter([](int x){ return x % 2 == 0; })
        | std::views::transform([](int x){ return x * x; })
        | std::views::reverse;
    
    // 转换为新vector
    std::vector<int> processed(result.begin(), result.end());
    
    // 或者原地修改
    std::ranges::sort(data);  // ranges版本的sort
}
```

**常用 ranges 操作**：
```cpp
// 创建视图
auto even = std::views::filter([](int x){ return x % 2 == 0; });
auto square = std::views::transform([](int x){ return x * x; });

// 组合使用
for(int x : data | even | square | std::views::take(5)) {
    std::cout << x << " ";
}
```

## 2. 相关容器对比

### 2.1 `std::array`（固定大小数组）

**特点**：
- 编译期固定大小
- 栈上分配内存
- 无动态扩容

**示例**：
```cpp
#include <array>

std::array<int, 5> arr = {1, 2, 3, 4, 5};

// 编译期大小检查
static_assert(arr.size() == 5);

// 类似原生数组的访问
for(size_t i = 0; i < arr.size(); ++i) {
    arr[i] *= 2;
}

// 但比原生数组更安全
// arr[10] = 1;  // 运行时错误，原生数组可能不会检查
```

**适用场景**：
- 已知大小的配置数据
- 替代C风格数组
- 需要容器接口的固定大小集合

### 2.2 `std::deque`（双端队列）

**特点**：
- 分块连续存储
- 头尾插入删除O(1)
- 中间插入O(n)

**示例**：
```cpp
#include <deque>

std::deque<int> dq = {2, 3, 4};

// 高效头尾操作
dq.push_front(1);  // 头部插入
dq.push_back(5);   // 尾部插入
dq.pop_front();    // 头部删除

// 随机访问
std::cout << dq[1];  // 输出2
```

**与vector对比**：
```cpp
vector<int> v(1000);
deque<int> dq(1000);

// 测试头部插入
auto start = std::chrono::steady_clock::now();
v.insert(v.begin(), 1);  // 慢，需要移动所有元素
auto end = std::chrono::steady_clock::now();

start = std::chrono::steady_clock::now();
dq.push_front(1);  // 快，常数时间
end = std::chrono::steady_clock::now();
```

### 2.3 `std::list`（双向链表）

**特点**：
- 非连续存储
- 任意位置插入删除O(1)
- 不支持随机访问

**示例**：
```cpp
#include <list>

std::list<int> lst = {1, 2, 4};

// 任意位置高效插入
auto it = std::find(lst.begin(), lst.end(), 2);
lst.insert(it, 3);  // 在2前插入3 → {1,3,2,4}

// 高效删除
lst.remove_if([](int x){ return x % 2 == 0; });  // 删除偶数 → {1,3}

// 不支持随机访问
// lst[1] = 5;  // 错误！
```

**特殊操作**：
```cpp
// 链表拼接
std::list<int> lst1 = {1, 2, 3};
std::list<int> lst2 = {4, 5, 6};
lst1.splice(lst1.end(), lst2);  // lst1变为{1,2,3,4,5,6}, lst2为空

// 排序（比vector慢，但保持迭代器有效）
lst1.sort();  // 链表专用sort
```

## 3. 推荐书籍与资源

### 3.1 经典书籍

1. **《Effective STL》**（Scott Meyers）
   - 条款5：区间成员函数优先于单元素操作
   - 条款13：尽量使用vector和string代替动态分配数组
   - 条款16：了解如何把vector和string数据传给旧的API

2. **《STL源码剖析》**（侯捷）
   - 深入分析vector内存管理
   - 迭代器设计模式
   - 空间配置器实现

3. **《C++标准库》**（Nicolai M. Josuttis）
   - 第7章：STL容器详解
   - 第9章：STL算法

### 3.2 在线资源

1. **[CppReference](https://en.cppreference.com/)**
   - 最权威的STL文档
   - 包含所有容器的接口说明和示例

2. **Compiler Explorer**
   - 查看不同编译器下的vector实现
   - 分析生成的汇编代码

3. **开源项目**
   - [LLVM libc++](https://github.com/llvm/llvm-project/tree/main/libcxx)：LLVM的STL实现
   - [GNU libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/)：GCC的STL实现
   - [Microsoft STL](https://github.com/microsoft/STL)：MSVC的STL实现

### 3.3 源码分析示例

**vector核心实现片段**（GCC libstdc++）：
```cpp
// 容量检查伪代码
void push_back(const value_type& __x) {
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage) {
        // 有空间，直接构造
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, __x);
        ++this->_M_impl._M_finish;
    } else {
        // 需要重新分配
        _M_realloc_insert(end(), __x);
    }
}

void _M_realloc_insert(iterator __position, const _Tp& __x) {
    const size_type __len = _M_check_len(size_type(1));
    pointer __new_start = _M_allocate(__len);
    pointer __new_finish = __new_start;
    // 移动元素到新内存...
}
```

## 4. 综合应用示例

### 4.1 现代C++20数据处理管道

```cpp
#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 创建编译期向量
    constexpr auto compile_time_vec = []() constexpr {
        std::vector<int> v;
        for(int i = 0; i < 5; ++i) v.push_back(i);
        return v;
    }();
    
    // 数据处理管道
    auto result = data
        | std::views::filter([](int x){ return x % 2 == 0; })  // 取偶数
        | std::views::transform([](int x){ return x * x; })    // 平方
        | std::views::take(3);                                 // 取前3个
    
    // 输出结果
    for(int x : result) std::cout << x << " ";  // 输出: 4 16 36
    
    // 比较容器性能
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> dq(arr.begin(), arr.end());
    std::list<int> lst(arr.begin(), arr.end());
    
    // 测试中间插入
    auto mid = arr.size()/2;
    arr[mid] = 100;  // 数组直接修改
    dq.insert(dq.begin() + mid, 100);  // deque中间插入
    auto lit = lst.begin();
    std::advance(lit, mid);
    lst.insert(lit, 100);  // list中间插入
    
    return 0;
}
```

## 4.2 学习路径建议

1. **基础阶段**：
   - 掌握vector的基本接口
   - 理解迭代器概念
   - 练习常用算法

2. **进阶阶段**：
   - 研究内存管理策略
   - 分析不同操作的复杂度
   - 比较不同容器的性能

3. **高级阶段**：
   - 阅读STL源码实现
   - 学习C++20新特性
   - 参与开源项目贡献

4. **专家阶段**：
   - 实现自定义容器
   - 优化特定场景下的性能
   - 设计新的数据结构和算法

通过系统学习这些内容，你将全面掌握C++ vector及其相关技术栈，能够在实际项目中做出合理的设计选择和性能优化。














# Vector学习目录

---  
**学习建议**：  
- 先掌握基础操作，再深入底层机制  
- 结合算法题练习，强化实际应用能力  
- 阅读优秀开源代码，学习高效使用模式