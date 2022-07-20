#include<iostream>
#include<thread>
#include<mutex>
#include<functional>
#include<chrono>
#include<vector>


int count = 0;
std::mutex mx;

void increase(int time){
    for(int i=0;i<time;i++){
        mx.lock();      // 不加锁会触发竞争，出现bug
        count++;
        mx.unlock();
    }
}

void increase2(int time){
    for(int i=0;i<time;i++){
        std::lock_guard<std::mutex> lk(mx);  // 使用lock_gurad避免遗忘unlock 
        count++;
    }
}

int main(){
    std::vector<std::thread> pool;
    for(int i=0;i<10;i++){
        pool.emplace_back(std::bind(increase2, 1000000));
    }
    for(int i=0;i<pool.size();i++){
        pool[i].join();
    }
    std::cout<<"Count = "<<count<<std::endl;
    return 0;
}