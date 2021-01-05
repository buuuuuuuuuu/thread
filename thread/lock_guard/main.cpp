#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
static int num = 0;
void func()
{
    lock_guard<mutex> g1(m); //用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    //lock_guard<mutex> g1(m,adopt_lock); //adopt_lock标识时，表示构造函数中不再进行互斥量锁定，因此此时需要提前手动锁定。
    for (int i = 0; i < 10; i++) {
      cout << "func内a:  " << num++ << endl;
    }
}//此时不需要写m.unlock(),g1出了作用域被释放，自动调用析构函数，于是m被解锁

void func1()
{
    lock_guard<mutex> g2(m);
    for (int i = 0; i < 10; i++) {
      cout << "func1内a:  " << num++ << endl;
    }
}
int main()
{

    thread th(func);
    thread th1(func1);
    th.join();
    th1.join();
    return 0;
}
