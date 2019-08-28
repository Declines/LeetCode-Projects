// 4. Median of Two Sorted Arrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int n_size1 = nums1.size();
		const int n_size2 = nums2.size();

		if (n_size1 > n_size2)
			return findMedianSortedArrays(nums2, nums1);

		const int k = (n_size1 + n_size2 + 1) / 2;
		int left = 0;
		int right = n_size1;
		while (left < right) {
			const int m1 = left + (right - left) / 2;
			const int m2 = k - m1;
			if (nums1[m1] < nums2[m2 - 1])
				left = m1 + 1;
			else
				right = m1;
		}
		const int m1 = left;
		const int m2 = k - left;
		const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

		if ((n_size1 + n_size2) % 2 == 1)
			return c1;

		const int c2 = min(m1 >= n_size1 ? INT_MAX : nums1[m1], m2 >= n_size2 ? INT_MAX : nums2[m2]);
		return (c1 + c2) / 2;
	}
};
int main()
{
    std::cout << "Hello World!\n";
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
