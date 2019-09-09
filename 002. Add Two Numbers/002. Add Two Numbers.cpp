// 002. Add Two Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode* pResultNode = new ListNode(0);
        //ListNode* l3 = pResultNode;
        //bool temp = 0;
        //int sum = 0;

        //while(l1 != NULL || l2 != NULL) {
        //    sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + temp;
        //    if (sum >= 10) {
        //        sum %= 10;
        //        temp = 1;
        //    }
        //    else {
        //        temp = 0;
        //    }

        //    l1 = l1 ? l1->next : l1;
        //    l2 = l2 ? l2->next : l2;
        //    l3->next = new ListNode(sum);
        //    l3 = l3->next;
        //}
        //if (temp == 1) {
        //    l3->next = new ListNode(1);
        //}

        //return pResultNode->next;

        ListNode* ret = new ListNode(0);
        ListNode* p = ret;
        bool up = 0;
        int sum = 0;

        while(l1!=nullptr||l2!=nullptr||up!=0) {
            sum = l1 ? l1->val+up : up;
            sum += l2 ? l2->val : 0;
            //up = sum >= 10 ? (sum%=10)>=0 : 0;
            if(sum>=10) {
                sum %= 10;
                up = 1;
            }
            else {
                up = 0;
            }
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            p->next = new ListNode(sum);
            p = p->next;
        }
        return ret->next;
    }
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
                                       }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
                        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length()-2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while(getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if(node==nullptr) {
        return "[]";
    }

    string result;
    while(node) {
        result += to_string(node->val)+", ";
        node = node->next;
    }
    return "["+result.substr(0, result.length()-2)+"]";
}

int main() {
    string line;
    while(getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout<<out<<endl;
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
