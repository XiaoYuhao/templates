#include<cstdio>
#include<vector>

using namespace std;

int n, m;
vector<int> nums;
void init(){
    m =  1;
    while(m<n) m*=2;
    nums.resize(m*2+1,0);
}

 void update(int i, int x){
        i += m;
        nums[i] += x;
        i /= 2;
        while(i){
            nums[i] = nums[i*2] + nums[i*2+1];
            i /= 2;
        }
    }
int query(int i, int left, int right, int a, int b){
    if(a<=left&&b>=right) return nums[i];
    if(a>right||b<left) return 0;
    int mid = (left + right) / 2;
    return query(i*2, left, mid, a, b) + query(i*2+1, mid+1, right, a, b);
}

int main(){
    return 0;
}