#include <iostream>
#include <thread>

using namespace std;

void func(int num,int num2)
{
    cout <<"子线程传入参数:    "<< num+ num2;
    cout <<"子线程线程id:    "<<this_thread::get_id()<<endl;
}

void func1(int &num)
{
    num++;
}

int main()
{
    cout <<"主线程id:  "<< this_thread::get_id() << endl;
    thread th(func, 1,2);
    cout << "子线程id: " << th.get_id()<<endl;
    th.join();

//    int num = 10;
//    thread th(func1, std::ref(num));
//    cout << "num: " << num;
//    th.join();

    return 0;
}
