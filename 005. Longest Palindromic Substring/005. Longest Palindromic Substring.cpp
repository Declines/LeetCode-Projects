// 005. Longest Palindromic Substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length()<1) {
			return "";
		}

		string test_str;
		for (int i = 0; i < s.length(); i++) {
			test_str += "#";
			test_str += s[i];
		}
		test_str += "#";

		int test_str_len = test_str.length();
		int MaxRight = 0;				            // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
		int pos = 0;					            // MaxRight对应的回文串的对称轴所在的位置
		int MaxRL = 0;					            // 最大回文串的回文半径
        int MaxPos = 0;                             // MaxRL对应的回文串的对称轴所在的位置
		int* RL = new int[test_str_len];			// RL[i]表示以第i个字符为对称轴的回文串的回文半径

        memset(RL, 0, test_str_len* sizeof(int));
        for (int i = 0; i < test_str_len; i++) {
            if (i < MaxRight) {
                RL[i] = min(RL[2 * pos - i], MaxRight - i);
            } else {
                RL[i] = 1;
            }

			// 尝试扩展RL[i]，注意处理边界
            while (i - RL[i] >= 0                                             // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
                   && i + RL[i] < test_str_len                                // 同上,即回文串的结束位不能大于总长
                   && test_str[i - RL[i]] == test_str[i + RL[i]]              // 回文串特性，左右扩展，判断字符串是否相同
                   ) {
                RL[i] += 1;
            }

            if (RL[i] + i - 1 > MaxRight) {
                MaxRight = RL[i] + i - 1;
                pos = i;
            }

            if (MaxRL <= RL[i]) {
                MaxRL = RL[i];
                MaxPos = i;
            }
        }
        return s.substr((MaxPos - MaxRL + 1) / 2, MaxRL - 1);
	}
};


int main(int argc, char* argv[]) {
	string s = "asgsacasdsasacbcza";

	Solution solution;
	string n_ret = solution.longestPalindrome(s);
	std::cout << n_ret;
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
