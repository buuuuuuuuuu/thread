#include<iostream>
#include<thread>
#include<mutex>
#include <unistd.h>
using namespace std;
mutex m;
static int num = 0;
void func()
{
    unique_lock<mutex> g1(m, defer_lock);//始化了一个没有加锁的mutex
    g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
    for (int i = 0 ; i < 5; i++) {
        cout << "手动加锁 num:   " << num++ << endl;
    }
    g1.unlock();//临时解锁
    cout << "临时解锁 num:   " << num++ << endl;
    g1.lock();
    cout << "临时上锁 num:   "<< num++ << endl;
}//自动解锁

void func1()
{
    unique_lock<mutex> g2(m,try_to_lock);//尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
    g2.owns_lock();
    if(g2){//锁成功
        cout << "加锁成功 num:    "<< num << endl;
    }else{//锁失败则执行这段语句
        cout <<"加锁失败: num:  "<<num<<endl;
    }
}//自动解锁

int main()
{
    thread th(func);
    thread th1(func1);
    th.join();
    th1.join();
    return 0;
}
