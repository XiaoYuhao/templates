#include<iostream>
#include<thread>
#include<vector>
#include<functional>
using namespace std;

vector<thread> pool;
vector<int> results;

void func(int i, int x){
    results[i] = x;
}

void print(vector<int> &result){
    for(const auto &item : result){
        cout<<item<<" ";
    }
    cout<<endl;
}

int main(){
    results.resize(100);
    for(int i=0;i<results.size();i++){
        pool.emplace_back(std::bind(func, i, 100-i));
    }
    for(int i=0;i<pool.size();i++){
        pool[i].join();
    }
    print(results);
    return 0;
}