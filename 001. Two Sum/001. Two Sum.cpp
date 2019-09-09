// 001. Two Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
	// 1.两数之和
	vector<int> twoSum(vector<int>& nums, int target) {

// 		//暴力法，直接遍历
// 		for (int i = 0; i < nums.size() - 1; i++) {
// 			for (int j = i + 1; j < nums.size(); j++) {
// 				if (target - nums.at(i) == nums.at(j)) {
// 					return{ i, j };
// 				}
// 			}
// 		}
// 		return {};
// 
// 		//两遍哈希
// 		map<int, int> m_Nums;
// 		for (int i = 0; i < nums.size(); i++)
// 			m_Nums.insert(map<int, int>::value_type(nums[i], i));
// 		for (int i = 0; i < nums.size(); i++) {
// 			int temp = target - nums.at(i);
// 			if ((m_Nums.find(temp) != m_Nums.end()) && (m_Nums.find(temp)->second != i)) {
// 				return{ i, m_Nums.find(target - nums.at(i))->second };
// 			}
// 		}
// 		return {};


		//一遍哈希
		map<int, int> m_Nums;
		for (int i = 0; i < nums.size(); i++) {
			int temp = target - nums[i];
			if (m_Nums.find(temp) != m_Nums.end())
				return{ m_Nums.find(temp)->second, i };
			m_Nums.insert(map<int, int>::value_type(m_Nums[nums[i]], i));
		}
		return{};
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main (int argc, char* argv[]) {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		vector<int> ret = Solution().twoSum(nums, target);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
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
