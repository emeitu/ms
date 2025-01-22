#include <iostream>
#include "traval.h"

#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


#include <algorithm>


void quickSort(int start, int end, vector<int>& nums) {
    if (start >= end) {
        return;
    }

    int left = start;
    int right = end;
    int special_num = nums[left];
    while (left < right) {
        while (left<right) {
            if (nums[right] < special_num) {
                break;
            }
            --right;
        }

        while(left<right) {
            if (nums[left] > special_num) {
                break;
            }
            ++left;
        }

        if (left<right) {
            std::swap(nums[left], nums[right]);
        }
    }

    quickSort(start, left-1, nums);
    quickSort(left+1, end, nums);
}

    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size()-1, nums);
        return nums;
    }





