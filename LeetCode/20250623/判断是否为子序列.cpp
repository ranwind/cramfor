// 判断是否为子序列
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    } // 在这里面，使用的是双重指针，两个指针分别从头检测，这样能极大的提高检索的效率。{一旦检测到所有的字符，就会退出，返回检测结果}
};

int main() {
    string s = "hello";
    string t = "ho";
    Solution solution;
    bool res = solution.isSubsequence(s, t);
    cout << "The result is: " << res << endl;
    
    return 0;
}
// 这样写时间复杂度更低，仅为 O(n)