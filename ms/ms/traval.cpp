#include <iostream>
#include "traval.h"

#include <stack>

using namespace std;

// 1.左中右 
vector<int> Travel::MidTravel(TreeNode* head)
{
	vector<int> result;
	if (head == nullptr) {
		return result;
	}

	TreeNode* pre_node = head;
	stack<TreeNode*> stk;
	while (!stk.empty() || pre_node != nullptr) {
		while (pre_node != nullptr) {
			stk.push(pre_node);
			pre_node = pre_node->left;
		}
		pre_node = stk.top();
		stk.pop();
		result.emplace_back(pre_node->val);
		// 必须这样
#if 0
		pre_node = pre_node->right;
#else
		if (pre_node->right == nullptr) {
			pre_node = nullptr;
		}
		else {
			pre_node = pre_node->right;
		}
#endif		
	}

	return result;
}

void reMidTravel(TreeNode* head, vector<int>& result) {
	if (head == nullptr) {
		return;
	}

	reMidTravel(head->left, result);
	result.emplace_back(head->val);
	reMidTravel(head->right, result);
}
// 1.递归 左中右 
vector<int> Travel::ReMidTravel(TreeNode* head)
{
	vector<int> result;

	reMidTravel(head, result);
	return result;
}



void rePreTravel(TreeNode* head, vector<int>& result) {
	if (head == nullptr) {
		return;
	}
	result.emplace_back(head->val);
	rePreTravel(head->left, result);
	rePreTravel(head->right, result);
}

// 2.前序  前序遍历  中左右
vector<int> Travel::RePreTravel(TreeNode* head)
{
	vector<int> result;

	rePreTravel(head, result);

	return result;
}

vector<int> Travel::PreTravel(TreeNode* head)
{
	vector<int> result;
	if (head == nullptr) {
		return result;
	}

	stack<TreeNode*> stk;
	TreeNode* cur_node = head;
	while (!stk.empty() || cur_node != nullptr) {
		while (cur_node != nullptr) {
			stk.emplace(cur_node);
			cur_node = cur_node->left;
			result.emplace_back(cur_node->val);
		}

		cur_node = stk.top();
		stk.pop();

		cur_node = cur_node->right;
	}

	return result;
}


void reSufTravel(TreeNode* root, vector<int>&result)
{
	if (root == nullptr) {
		return;
	}

	reSufTravel(root->left, result);
	reSufTravel(root->right, result);
	result.emplace_back(root->val);
}
// 3.后续遍历  左，右，中
vector<int> Travel::ReSufTravel(TreeNode* root)
{
	vector<int> result;
	reSufTravel(root, result);

	return result;
}

vector<int> Travel::SufTravel(TreeNode* root)
{
	return vector<int>();
}

