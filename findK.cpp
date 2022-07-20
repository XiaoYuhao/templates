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

int findK(vector<int> &nums, int left, int right, int k){
    if(left>=right) return nums[left];
    int pos = partition(nums, left, right);
    int count = pos - left + 1;
    if(count>=k){
        return findK(nums, left, pos, k);
    }
    else{
        return findK(nums, pos+1, right, k-count);
    }
}

int main(){
    vector<int> nums = {1,3,5,7,9,2,4,6,8};
    cout<<findK(nums, 0, nums.size()-1, 5)<<endl;
    return 0;
}