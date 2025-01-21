#pragma once

#include <iostream>
#include <vector>

using namespace std;
/*
	�������  ������
	ǰ�����  ������
	�������  ������
	�������
*/

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
};
class Travel {
public:
	// 1.����
	vector<int> ReMidTravel(struct TreeNode* head);
	vector<int> MidTravel(struct TreeNode* head);


	// 2.ǰ��  ǰ�����  ������
	vector<int> RePreTravel(struct TreeNode* head);
	vector<int> PreTravel(struct TreeNode* head);


	// 3.��������� ������
	vector<int> ReSufTravel(struct TreeNode* root);
	vector<int> SufTravel(struct TreeNode* root);
};
