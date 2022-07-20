#include<cstdio>

const int MAXN = 100005;

int nums[MAXN];
int n;

/*
________
____
__  __
_ _ _ _  
12345678
*/


void add(int i, int x){
    while(i<=n){
        nums[i] += x;
        i += i&-i;
    }
}

int sum(int i){
    int res = 0;
    while(i){
        res += nums[i];
        i -= i&-i;
    }
    return res;
}

int main(){
    
    return 0;
}