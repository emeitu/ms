#pragma once

#include <iostream>
#include <vector>

using namespace std;
/*
	中序遍历  左中右
	前序遍历  中左右
	后序遍历  左右中
	层序遍历
*/

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
};
class Travel {
public:
	// 1.中序
	vector<int> ReMidTravel(struct TreeNode* head);
	vector<int> MidTravel(struct TreeNode* head);


	// 2.前序  前序遍历  中左右
	vector<int> RePreTravel(struct TreeNode* head);
	vector<int> PreTravel(struct TreeNode* head);


	// 3.后序遍历， 左右中
	vector<int> ReSufTravel(struct TreeNode* root);
	vector<int> SufTravel(struct TreeNode* root);
};
