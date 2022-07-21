#include<iostream>
#include<vector>
using namespace std;

inline int index(int i){
    return i - 1;
}

void adjustHeap(vector<int> &nums, int root, int size){
    while(root<size){
        int left = root * 2;
        int right = root * 2 + 1;
        int select = root;
        if(right<=size){
            if(nums[index(right)]>nums[index(left)]){
                select = right;
            }
            else select = left;
        }
        else if(left<=size){
            select = left;
        }
        else break;
        if(nums[index(select)]>nums[index(root)]){
            swap(nums[index(root)], nums[index(select)]);
            root = select;
        }
        else break;
    }
}

void heapSort(vector<int> &nums) {
    int n = nums.size();

    for(int i=n/2;i>=1;i--){
        adjustHeap(nums, i, n);
    }
    for(int i=n;i>=1;i--){
        swap(nums[index(i)], nums[index(1)]);
        adjustHeap(nums, 1, i-1);
    }
}

int main(){
    vector<int> nums = {1,3,5,7,9,2,4,6,8,5,3,1,6,4};
    for(const auto &i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
    heapSort(nums);
    for(const auto &i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}