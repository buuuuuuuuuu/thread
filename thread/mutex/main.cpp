#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
static int num = 0;
void func()
{
  //  m.lock();
    for (int i = 0; i < 10; i++) {
      cout << "func内a:  " << num++ << endl;
    }
   // m.unlock();
}

void func1()
{
    //m.lock();
    for (int i = 0; i < 10; i++) {
      cout << "func1内a:  " << num++ << endl;
    }
    //m.unlock();
}
int main()
{
    thread th(func);
    thread th1(func1);
    th.join();
    th1.join();
    return 0;
}
