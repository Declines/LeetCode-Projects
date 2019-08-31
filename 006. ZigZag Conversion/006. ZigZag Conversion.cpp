// 006. ZigZag Conversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length ( ) <= numRows || numRows == 1)
            return s;

        string str_ret;
        int n_step = numRows * 2 - 2;
        int n_index = 0;
        int n_add = 0;

        for (int i = 0; i < numRows; i++) {
            n_index = i;
            n_add = i * 2;
            while (n_index<s.length()) {
                str_ret += s[n_index];
                n_add = n_step - n_add;
                n_index += (i == 0 || i == numRows - 1) ? n_step : n_add;
            }
        }
        return str_ret;
    }
};

int main(int argc, char* argv[]) {
    string test_str = "LEETCODEISHIRING";

    Solution solution;
    string ret = solution.convert(test_str, 5);
    cout << ret;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
