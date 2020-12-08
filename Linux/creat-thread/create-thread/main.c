#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void *arg)
{
    pthread_t newThid;
    newThid = pthread_self();
    printf("this is a new thread,thread ID = %lu\n",newThid);

    return NULL;
}

int main()
{
    //typedef unsigned long int pthread_t   表示一个线程的标识符。
    pthread_t thid;
    printf("main thread,ID is %lu\n",pthread_self());
    /*extern int pthread_create __P ((pthread_t *__thread, __const pthread_attr_t *__attr,
                                        void *(*__start_routine) (void *)， void *__arg));
    第一个参数为指向线程标识符的指针，
    第二个参数用来设置线程属性，
    第三个参数是线程运行函数的起始地址，
    最后一个参数是运行函数的参数。
    当创建线程成功时，函数返回0,若不为0则说明创建线程失败。
    常见的错误返回代码为EAGAIN和EINVAL.前者表示系统限制创建新的线程
    例如线程数目过多了
    后者表示第二个参数代表的线程属性值非法。创建线程成功后，
    新创建的线程则运行参数三和参数四确定的函数，原来的线程则继续运行下一行代码。
    */

    int err = 0;
    err = pthread_create(&thid,NULL, thread,NULL);
    if(err != 0)
    {
        printf("thread creation failed: %s\n", strerror(err));
        return EXIT_FAILURE;
    }
    pthread_join(thid,NULL);
    return EXIT_SUCCESS;
}
