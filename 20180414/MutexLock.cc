 ///
 /// @file    MutexLock.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-14 23:34:32
 ///
//对于一个类的设计一般比单纯的实现一个类要重要许多，很多时候要多思考类的设计，
//它可以让代码简化并且优化，而不是让代码产生大量的冗余
//没实现一个类成员函数：要知道为什么要设计它，会在什么情况用到，怎么用？使用非法时如何进行处理。
//一些临界条件的处理细节，
//而对于一个类的属性，必须知道为什么要有这个属性，使用了这个属性会带来什么好处，这个属性可以被其他的属性替代吗
//或者属性可以用其他的方式来达成同样的效果，而没必要每次怎天一个类所使用的空间及其复杂度
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
//使用命名空间时，尽量不要去使用using namespace xxx;因为这会带来编译的负担，并且会造成命名空间的污染
using std::cout;
using std::endl;

class MutexLock{
	public:
		MutexLock()
		{
			pthread_mutex_init(&mutex,NULL);
		};
		void lock(){
			pthread_mutex_lock(&mutex);	
		};
		void unlock(){
			pthread_mutex_unlock(&mutex);
		};
		pthread_mutex_t & getmutex(){
			return mutex;
		}
		~MutexLock(){
			pthread_mutex_destroy(&mutex);
		}
		//不允许调用赋值构造函数和赋值构造函数
		MutexLock(const MutexLock & mutex)=delete;
		MutexLock & operator=(const MutexLock & mutex)=delete;
	private:
		pthread_mutex_t mutex;
};
//防止线程加锁之后解锁之前崩溃，造成线程的批量死锁
//一般把该类的对象定义在局部区域，利用函数的退栈操作导致类对象的销毁，并自动调用析构函数的特性
//来避免死锁的发生
class MutexautoLock{
	public:
		MutexautoLock(MutexLock & mutex)
		:_mutex(mutex)
		{
			_mutex.lock();
		}
		~MutexautoLock(){
			_mutex.unlock();
		}
		//一旦涉及到系统资源的使用，一般要禁止复制构造函数和赋值函数的使用
		//包括对流对象的使用同样不允许复制的操作
		MutexautoLock(const MutexautoLock &MauL)=delete;
		MutexautoLock &operator=(const MutexautoLock &Maul)=delete;
	private:
		MutexLock & _mutex;
};
//注意不同对象之间的作用域的区别，作用域的不同直接导致类的实现之间的差异
class Condition{
	public:
		Condition(MutexLock & mutex)
		:_mutex(mutex)
		{
			pthread_cond_init(&cond,NULL);
		}
		void wait(){
			pthread_cond_wait(&cond,&_mutex.getmutex());
		};
		void notify(){
			pthread_cond_signal(&cond);
		};
		void notifyall(){
			pthread_cond_broadcast(&cond);
		};
		~Condition(){
			pthread_cond_destroy(&cond);
		}
		//不允许调用复制构造函数与赋值函数
		Condition(const Condition &con)=delete;
		Condition &operator=(const Condition &con)=delete;
	private:
		pthread_cond_t cond;
		//注意对象之间的关联性问题：当对象的作用范围不相同时，一般不允许把一个对象简单的作为一个类
		//的成员对象，故而一般选择把要使用的对象的指针或引用作为类的成员进行操作
		MutexLock &_mutex;
};

//测试----------------------------------------------
MutexLock m;
Condition con(m);
int count=0;
bool flag=true;
void *fun1(void * args){
	int num=10;
	while(num--){
		MutexautoLock mauto(m);
		if(!flag)
			con.wait();
		count++;
//		sleep(1);
		cout<<"id1:"<<pthread_self()<<"  "<<"count:"<<count<<endl;
		if(flag==true){
			flag=false;
			con.notify();
		}
	}
	return NULL;
};

void *fun2(void * args){
	int num=10;
	while(num--){
		MutexautoLock mauto(m);
		if(flag)
			con.wait();
		count++;
//		sleep(1);
		cout<<"id2:"<<pthread_self()<<"  "<<"count:"<<count<<endl;
		if(!flag){
			flag=true;
			con.notify();
		}
	}
	return NULL;
};

int main(){
	pthread_t pth1,pth2;
	
	pthread_create(&pth1,NULL,fun1,NULL);
	pthread_create(&pth2,NULL,fun2,NULL);
	
	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);

	return 0;
}
