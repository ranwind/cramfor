# **广度优先搜索（BFS）详解：从原理到C++实践**

## **1. BFS 核心思想**
广度优先搜索（Breadth-First Search, BFS）是一种**逐层遍历**的算法，适用于解决**无权图的最短路径问题**或**状态空间搜索问题**。其核心特点是：
- **按层级扩展**：先访问离起点最近的节点，再逐步向外扩展。
- **队列实现**：使用队列（FIFO）存储待访问的节点。
- **避免重复访问**：通过标记已访问的节点防止循环。

---

## **2. BFS 算法流程**
### **步骤说明**
1. **初始化**：
   - 将起点加入队列，并标记为已访问。
2. **循环处理队列**：
   - 取出队首节点，遍历其所有邻居。
   - 若邻居未被访问，则加入队列并标记。
3. **终止条件**：
   - 队列为空（遍历完成）或找到目标节点。

### **伪代码**
```plaintext
BFS(start, target):
    queue = [start]
    visited = {start}
    steps = 0  // 记录步数（层数）
    
    while queue is not empty:
        size = queue.size()
        for i in range(size):
            node = queue.pop_front()
            if node == target:
                return steps
            for neighbor in node.neighbors:
                if neighbor not in visited:
                    queue.push_back(neighbor)
                    visited.add(neighbor)
        steps += 1
    return -1  // 未找到目标
```

---

## **3. BFS 的C++实现**
### **场景1：图的遍历**
假设图的邻接表表示如下：
```cpp
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // 处理当前节点
        
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}
```

### **场景2：最短路径（单词接龙问题）**
以LeetCode [127. 单词接龙](https://leetcode.com/problems/word-ladder/)为例：
```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    
    queue<string> q;
    q.push(beginWord);
    int steps = 1;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string word = q.front();
            q.pop();
            if (word == endWord) return steps;
            
            for (int j = 0; j < word.size(); j++) {
                char original = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[j] = c;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push(word);
                        wordSet.erase(word);  // 避免重复访问
                    }
                }
                word[j] = original;
            }
        }
        steps++;
    }
    return 0;
}
```

---

## **4. BFS 的时间复杂度分析**
- **时间复杂度**：`O(V + E)`  
  - `V` 是节点数（Vertices），`E` 是边数（Edges）。
  - 每个节点和边均被访问一次。
- **空间复杂度**：`O(V)`  
  - 队列和访问集合最多存储所有节点。

---

## **5. BFS 的常见应用场景**
1. **无权图的最短路径**（如迷宫、单词接龙）。
2. **状态空间搜索**（如八数码问题）。
3. **层级遍历**（如二叉树的层序遍历）。
4. **连通性检测**（判断图中两点是否连通）。

---

## **6. BFS 的优化技巧**
### **(1) 双向BFS**
- **适用场景**：已知起点和终点的最短路径问题。
- **原理**：同时从起点和终点出发，相遇时路径最短。
- **C++ 示例**：
  ```cpp
  int bidirectionalBFS(vector<vector<int>>& graph, int start, int target) {
      unordered_set<int> beginSet, endSet, visited;
      beginSet.insert(start);
      endSet.insert(target);
      int steps = 0;
      
      while (!beginSet.empty() && !endSet.empty()) {
          if (beginSet.size() > endSet.size()) {
              swap(beginSet, endSet);  // 选择较小的集合扩展
          }
          
          unordered_set<int> temp;
          for (int node : beginSet) {
              if (endSet.find(node) != endSet.end()) {
                  return steps + 1;
              }
              visited.insert(node);
              for (int neighbor : graph[node]) {
                  if (visited.find(neighbor) == visited.end()) {
                      temp.insert(neighbor);
                  }
              }
          }
          beginSet = temp;
          steps++;
      }
      return -1;
  }
  ```

### **(2) 优先级队列（Dijkstra的变种）**
- **适用场景**：带权图的最短路径（需改用优先队列）。

---

## **7. BFS 与 DFS 的对比**
| **特性**         | **BFS**                          | **DFS**                          |
|------------------|----------------------------------|----------------------------------|
| **数据结构**      | 队列（FIFO）                     | 栈（LIFO）                       |
| **空间复杂度**    | `O(V)`（层级扩展）               | `O(h)`（递归深度）               |
| **适用场景**      | 最短路径、层级遍历               | 拓扑排序、回溯问题               |
| **找到的解**      | 最短路径（无权图）               | 可能非最短                       |

---

## **8. 总结**
- **BFS 核心**：队列 + 层级遍历 + 避免重复访问。
- **C++ 关键点**：
  - 使用 `queue` 和 `unordered_set` 实现。
  - 注意处理邻居节点的边界条件。
- **经典问题**：
  - 单词接龙（LeetCode 127）
  - 二叉树层序遍历（LeetCode 102）
  - 迷宫最短路径（LeetCode 490）

通过BFS，你可以高效解决许多最短路径和状态搜索问题！ 🚀