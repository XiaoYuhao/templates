#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int start1, int end1, int start2, int end2){
    vector<int> vec;
    int start = start1;
    while(start1<=end1&&start2<=end2){
        if(nums[start1]<nums[start2]){
            vec.push_back(nums[start1]);
            start1++;
        }
        else{
            vec.push_back(nums[start2]);
            start2++;
        }
    }
    while(start1<=end1){
        vec.push_back(nums[start1]);
        start1++;
    }
    while(start2<=end2){
        vec.push_back(nums[start2]);
        start2++;
    }
    for(int i=0;i<vec.size();i++){
        nums[i+start] = vec[i];     // take care of this.
    }
}

void mergeSort(vector<int> &nums, int left, int right){
    if(left>=right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);
    merge(nums, left, mid, mid+1, right);
}

int main(){
    vector<int> nums = {1,3,5,7,9,2,4,6,8,5,3,2,6,8,4};
    for(const auto &i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
    mergeSort(nums, 0, nums.size()-1);
    for(const auto &i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}