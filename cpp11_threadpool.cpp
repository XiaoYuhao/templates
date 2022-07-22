#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<functional>
#include<queue>
#include<condition_variable>
#include<chrono>
using namespace std;

typedef function<void(void)> Task;

class ThreadPool {
    vector<thread> workers;
    condition_variable cv;
    mutex mx;
    queue<Task> tasks;
    static void worker(void *arg);
    void run();
    bool stop;

public:
    ThreadPool(int workers_num = 10): stop(false){
        workers.reserve(10);
        for(int i=0;i<workers_num;i++){
            workers.emplace_back(ThreadPool::worker, this);
        }
    }
    ~ThreadPool(){
        stop = true;
        cv.notify_all();
        for(int i=0;i<workers.size();i++){
            workers[i].join();
        }
    }
    void append(Task &&t){
        lock_guard<mutex> lk(mx);
        tasks.push(t);
        cv.notify_one();
    }
    
};

void ThreadPool::worker(void *arg){
    ThreadPool *pool = (ThreadPool *) arg;
    pool->run();
}


void ThreadPool::run(){
    while(!stop){
        unique_lock<mutex> ul(mx);
        while(tasks.empty()){
            cv.wait(ul);
            if(stop) break;
        }
        if(tasks.empty()) break;
        Task task = tasks.front();
        tasks.pop();
        ul.unlock();
        task();
    }
}


void func(int id){
    cout<<id<<endl;
}

int main(){
    ThreadPool pool;
    for(int i=0;i<100;i++){
        pool.append(bind(func, i));
    }
    this_thread::sleep_for(chrono::milliseconds(5000));
    return 0;
}

