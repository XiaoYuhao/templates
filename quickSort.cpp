#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums, int left, int right){
    int mid = nums[left];
    left--;
    right++;
    while(left<right){
        while(nums[++left]<mid);
        while(nums[--right]>mid);
        if(left>=right) break;
        swap(nums[left], nums[right]);
    }
    return right;
}

void QuickSort(vector<int> &nums, int left, int right){
    if(left>=right) return;
    int pos = partition(nums, left, right);
    QuickSort(nums, left, pos);
    QuickSort(nums, pos+1, right);
}

int main(){
    vector<int> nums = {1,3,5,7,9,2,4,6,8};
    for(auto i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
    QuickSort(nums, 0, nums.size()-1);
    for(auto i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}