#pragma once
#ifndef _THREADLEARNING_H_
#define _THREADLEARNING_H_

/*�̺߳���*/
void print_hello();
void print(string str);
void func(int a, int b, int c);

/*���̵߳�һ��demo*/
void hello_world();

/*�߳��ƶ�ʾ��*/
void thread_move();

/*������ʾ��*/
int mutex_demo();
/*����ʱ�Ļ�����ʾ��*/
int timed_mutex_demo();
/*Thread���̱߳��ش洢��Thread Local Storage��*/
void thread_local_demo();

/*call_once��once_flag*/
int call_once_demo();

#endif // !_THREADLEARNING_H_
