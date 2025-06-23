#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
    unordered_map<char, vector<int>> charToIndices;
    bool isPreprocessed = false;

public:
    // 预处理 t，只需执行一次
    void preprocess(string t) {
        for (int i = 0; i < t.size(); i++) {
            charToIndices[t[i]].push_back(i);
        }
        isPreprocessed = true;
    }

    // 查询 s 是否是 t 的子序列
    bool isSubsequence(string s, string t) {
        if (!isPreprocessed) {
            preprocess(t);
        }

        int prevPos = -1;
        for (char c : s) {
            auto it = charToIndices.find(c);
            if (it == charToIndices.end()) return false;  // t 中没有该字符
            
            const vector<int>& indices = it->second;
            // 使用二分查找找到第一个 > prevPos 的位置
            auto nextPos = upper_bound(indices.begin(), indices.end(), prevPos);
            if (nextPos == indices.end()) return false;  // 没有更靠后的匹配位置
            prevPos = *nextPos;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string t = "ahbgdc";

    // 预处理 t（只需一次）
    solution.preprocess(t);

    // 多次查询
    cout << solution.isSubsequence("abc", t) << endl;  // 1 (true)
    cout << solution.isSubsequence("ahc", t) << endl;  // 0 (false)
    cout << solution.isSubsequence("bgd", t) << endl;  // 1 (true)

    return 0;
}


// 精研-进行理解，能够独立编写出来