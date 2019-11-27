#include "stdafx.h"
#include <memory>
#include <string>
#include <list>

#include "ptr.h"

using namespace std;

typedef unsigned char cv_pixel_format;

/// ͼ���ʽ����
typedef struct cv_image_t {
	unsigned char *data;            ///< ͼ������ָ��
	cv_pixel_format pixel_format;   ///< ���ظ�ʽ
	int width;                      ///< ���(������Ϊ��λ)
	int height;                     ///< �߶�(������Ϊ��λ)
	int stride;                     ///< ���, ��ÿ����ռ���ֽ���
} cv_image_t;

void cv_image_release(cv_image_t* image) {
	if (image == nullptr) {
		return;
	}
	delete[] image->data;
	delete image;
	return;
}

int unique_demo() {
	/*����ָ��Ĵ���*/  
	unique_ptr<int> u_i; //����������ָ��
	u_i.reset(new int(3)); //"�󶨡���̬����  
	unique_ptr<int> u_i2(new int(4));//����ʱָ����̬����
	//unique_ptr<T, D> u(d);	//������unique_ptr,ִ������ΪT�Ķ���������ΪD�Ķ���d�����Ĭ�ϵ�ɾ����delete

	/*����Ȩ�ı仯*/
	//std::unique_ptr<int>p2 = u_i2;// ��������
	int *p_i = u_i2.release(); //�ͷ�����Ȩ  
	unique_ptr<string> u_s(new string("abc"));
	unique_ptr<string> u_s2 = std::move(u_s); //����Ȩת��(ͨ���ƶ�����)��u_s����Ȩת�ƺ󣬱����Ч��ָ��
	unique_ptr<string> u_s3(new string("def"));
	unique_ptr<string> u_s4;
	u_s4.reset(u_s3.release());//����Ȩת��
	u_s4.reset(new string("ghi"));//�ͷ�ԭ������Ķ��󣬷���һ���µ�ָ��

	/*����*/
	u_s2.swap(u_s4);//��������

	/*�ͷ��ڴ�*/
	u_i.reset();// empty
	u_i2.reset();// empty
	u_s.reset();//��ת������Ȩ����Ч���ͷ�
	u_s2 = nullptr;//��ʽ������ָ����ͬʱ����ָ���Ϊ��ָ�롣�൱��u_i.reset();
	//u_s3�Ѿ�ת������Ȩ���������ͷ���
	u_s4 = nullptr;

	/**�Զ���ɾ����
	 * why:����Ķ����ܽ���ֻ������ delete ɾ��ʱ����ô�����Ҫ�����Զ����ɾ�����ˡ���������л�����������������
	 * how:��дһ��ɾ������ָ������Ĳ�����Ȼ��ʵ����Ӧ���ͷŲ������������ɾ�������� unique_ptr ��
	 */

	return E_OK;
}