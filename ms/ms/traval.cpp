#include <iostream>
#include "traval.h"

#include <stack>
#include <queue>

using namespace std;

// 1.������ 
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
		// ��������
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
// 1.�ݹ� ������ 
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

// 2.ǰ��  ǰ�����  ������
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
// 3.��������  ���ң���
vector<int> Travel::ReSufTravel(TreeNode* root)
{
	vector<int> result;
	reSufTravel(root, result);

	return result;
}
// 3. ���
vector<int> Travel::SufTravel(TreeNode* root)
{
	vector<int> result;
	if (root == nullptr) {
		return result;
	}

	stack<TreeNode*> stk;
	TreeNode* cur_node = root;
	TreeNode* pre_node = nullptr;
	while (!stk.empty() || cur_node != nullptr) {
		while (cur_node != nullptr) {
			stk.push(cur_node);
			cur_node = cur_node->left;
		}

		cur_node = stk.top();
		stk.pop();

		if (cur_node->right == nullptr || cur_node->right == pre_node) {
			result.emplace_back(cur_node->val);
			pre_node = cur_node;
			cur_node = nullptr; 
		} else {
			stk.push(cur_node);
			cur_node = cur_node->right;
		}
	}

	return result;
}


// 层
vector<vector<int>>Travel::Travel(struct TreeNode* root) {
	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}
	queue<TreeNode*> q;
	q.emplace(root);
	int node_size = 0;
	while (!q.empty()) {
		node_size = q.size();
		vector<int> res;
		while (node_size-- > 0) {
			TreeNode* cur_node = q.front();
			q.pop();

			res.emplace_back(cur_node->val);
			if (cur_node->left != nullptr) {
				q.push(cur_node->left);
			}
			if (cur_node->right != nullptr) {
				q.push(cur_node->right);
			}
		}
		result.emplace_back(res);
	}

	return result;
}
