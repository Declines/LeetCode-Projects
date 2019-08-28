﻿// 001. Two Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//for (int i = 0; i < nums.size() - 1; i++) {
		//	for (int j = i + 1; j < nums.size(); j++) {
		//		if (target - nums.at(i) == nums.at(j)) {
		//			return{i, j};
		//		}
		//	}
		//}
		//return {};

		//map<int, int> m_Nums;
		//for (int i = 0; i < nums.size(); i++)
		//	m_Nums.insert(map<int, int>::value_type(nums[i], i));
		//for (int i = 0; i < nums.size(); i++) {
		//	int temp = target - nums.at(i);
		//	if ((m_Nums.find(temp) != m_Nums.end()) && (m_Nums.find(temp)->second != i)) {
		//		return{i, m_Nums.find(target - nums.at(i))->second};
		//	}
		//}
		//return {};

		map<int, int> m_Nums;
		for (int i = 0; i < nums.size(); i++) {
			int temp = target - nums[i];
			if (m_Nums.find(temp) != m_Nums.end())
				return{m_Nums.find(temp)->second, i};
			m_Nums.insert(map<int, int>::value_type(m_Nums[nums[i]], i));
		}
		return{};
	}
};

int main(int argc, char* argv[])
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	Solution solution;
	vector<int> ret = solution.twoSum(nums, target);
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
