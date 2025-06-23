/*
使用最小花费爬楼梯：
数组中的每一个下标作为一个阶梯，第i个阶梯对应着一个非负数的体力花费值cost[i]（下表标从0开始）。
每当爬上一个阶梯都要花费对应的体力值，一旦支付了相对应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
请找出达到楼层顶部的最小花费。在开始时，你可以选择下表为0或1的元素作为初始阶段。

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MinCostClimbingStairs {
public:
    int minCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        
        int a = cost[0], b = cost[1];
        for (int i = 2; i < n; ++i) {
            int current = min(a, b) + cost[i];
            a = b;
            b = current;
        }
        
        return min(a, b);
    }
};

int main() {
    MinCostClimbingStairs solution;
    
    // 示例 1
    vector<int> cost1 = {10, 15, 20};
    cout << "示例 1 输出: " << solution.minCost(cost1) << endl; // 输出 15
    
    // 示例 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "示例 2 输出: " << solution.minCost(cost2) << endl; // 输出 6
    
    return 0;
}