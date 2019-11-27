#include "stdafx.h"

static std::mutex g_lock;

/*
����lockһ�� std::mutex ����֮����������unlock����
������Ѿ�����������㲻���ٴ�lock��
*/
void lock_unlock()
{
	//����
	g_lock.lock();
	cout << "in id: " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "out id: " << this_thread::get_id() << endl;
	//����
	g_lock.unlock();
}

void f_lock_guard()
{
	//lock_guard�ڹ���ʱ���Զ�����������,�����˳���������������ʱ�ͻ��Զ�����.
	lock_guard<std::mutex> lock(g_lock);
	cout << "in id: " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "out id: " << this_thread::get_id() << endl;
}

/*
���߳�ִ��˳����һ���ģ�ͨ���������Ա�֤ͬһʱ��ֻ��һ���߳���ʹ��
ע�����������̱߳Ƚ��٣�ִ��ʱ��̣����Բ�����������Ҳ��ͬ��˳��
*/
int mutex_demo()
{
	std::thread t1(lock_unlock);
	std::thread t2(lock_unlock);
	std::thread t3(lock_unlock);

	t1.join();
	t2.join();
	t3.join();

	std::thread t4(f_lock_guard);
	std::thread t5(f_lock_guard);
	std::thread t6(f_lock_guard);

	t4.join();
	t5.join();
	t6.join();

	return 0;
}