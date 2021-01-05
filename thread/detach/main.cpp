#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void func(int num)
{
    sleep(1);

    cout <<"我是子线程"<<endl;
}


int main()
{
    thread th(func, 1);
    th.detach();
    thread th1(func, 1);
    th.detach();
    thread th2(func, 1);
    th.detach();
    thread th3(func, 1);
    th.detach();
    cout << "我是主线程" <<endl;
   // sleep(2);
   bool ret = th.joinable();
   cout << ret;
    return 0;
}
