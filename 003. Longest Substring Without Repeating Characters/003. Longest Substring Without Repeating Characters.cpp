// 003. Longest Substring Without Repeating Characters.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size, i = 0, j, k, max = 0;
		size = s.size();
		for (j = 0; j < size; j++) {
			for (k = i; k < j; k++)
				if (s[k] == s[j]) {
					i = k + 1;
					break;
				}
			if (j - i + 1 > max)
				max = j - i + 1;
		}
		return max;
	}
};

int main()
{
	string test_string = "abcabcbb";
	Solution solution;
	int ret = solution.lengthOfLongestSubstring(test_string);
    std::cout << ret;
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
