/*
生产者消费者问题
*/
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
using namespace std;

deque<int> q;
mutex m;
condition_variable cond;

void curDeque();
void producer()
{
    while (1) {//通过外层循环，能保证生产不停止
        if(q.size() < 3) {//限流
            unique_lock<mutex> locker(m);//锁
            q.push_back(q.size()+1);
            cout<< "生产者: ";
            curDeque();
            cond.notify_one();  // 通知取
        }
        usleep(500);
    }
}

void consumer()
{
    while (1) {
        unique_lock<mutex> locker(m);
        while(q.empty()){
            cond.wait(locker); //wait()阻塞前先会解锁,解锁后生产者才能获得锁来放产品到缓冲区；生产者notify后，将不再阻塞，且自动又获得了锁。
        }
        q.pop_back();//取的第二步
        cout<< "消费者: ";
        curDeque();
        sleep(1);
    }
}

void curDeque()
{
    cout << "当前队列:  ";
    for (int num : q) {
        cout<< num<<"   ";
    }
    cout<<endl;
}

int main() {
    thread t1(producer);
    thread t2(consumer);
    thread t3(producer);
    thread t4(producer);
    t1.join();
    t2.join();
    t3.join();
    t3.join();
    return 0;
}
