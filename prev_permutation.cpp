#include<iostream>
#include<vector>
using namespace std;


void display(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void reverse(vector<int> &vec, int left, int right){
    while(right>left){
        swap(vec[left], vec[right]);
        right--;
        left++;
    }
}

bool prev_permutation(vector<int> &vec){
    int n = vec.size();
    if(n<2) return false;
    int i = n-2;
    int j = n-1;
    while(i>=0&&vec[j]>=vec[i]){
        j--;
        i--;
    }
    if(i<0) return false;
    int k = n - 1;
    while(k>i&&vec[k]>=vec[i]) k--;
    swap(vec[i], vec[k]);
    reverse(vec, j, n-1);
    return true;
}

int main(){
    vector<int> vec = {5,4,3,2,1};
    display(vec);
    
    int count = 1;
    while(prev_permutation(vec)){
        count++;
        display(vec);
    }
    cout<<count<<endl;

    return 0;
}