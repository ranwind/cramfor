#include<iostream>

using namespace std;

// 解决问题的方法Solution
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1; // n=1的情况
        if(n == 2) return 2;  // n=2情况

        int prev = 1; // dp[1]
        int curr = 2; // dp[2]

        for (int i = 3; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};


int main(void){
    Solution climbStair;
    int n;
    cin >> n;
    cout << climbStairs.climbStairs(n) << endl;

    return 0;
}