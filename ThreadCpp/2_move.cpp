#include "stdafx.h"
#include "ThreadLearning.h"

/**
* ��Ҫ����һ���̣߳��������壩�ǲ����ܵģ���ֻ��move���ƶ����壩��
* Ч�����ƶ���,�̶߳���t���ڴ����κ��̡߳�t1��ʾԭ��tָ����̡߳�
*/
void thread_move()
{
	std::thread t(func, 2, 3, 4);

	std::thread t1(std::move(t));
	//t.join();//t��ָ���߳��ˣ����Բ��ܵ���
	t1.join();

	//���ڰ汾������=��Ч����ͬ��move�������Ѿ����Ƴ���
	//std::thread t2(func, 2, 3, 4);
	//std::thread t3;
	//t3 = t2;
}