

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

//��Բ���Ľṹ��������
//�ýṹ�н�����һ��ָ������'p'
struct Yuan
{
	float s;
	float l;
	float *p = NULL;
};

//��������������Բ���ṹ������Ϊ����ֵ
//���������Ľṹ����ֱ�ӽ���ṹ����Ϊ����
//���ýṹ����ʱ��ʡ��"struct"�ؼ���
Yuan name(float r);

//����Books�ṹ
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
	void print_t(int a)
	{
		if (a == 1)
			cout << "�ɽ�" << endl;
		else if (a == 0)
			cout << "���ɽ�" << endl;
		else
			cout << "״̬����" << endl;
	}
};

//���º����� struct Books ���ͱ�����Ϊ�β�
void printBook(Books *book, int a=1);

int main()
{
	Books Book1;        // ����ṹ������ Books �ı��� Book1
	Books Book2;        // ����ṹ������ Books �ı��� Book2

	 // Book1 ����������cstring������ֵ
	strcpy(Book1.title, "C++ �̳�");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "�������");
	Book1.book_id = 12345;

	// Book2 ����
	strcpy(Book2.title, "CSS �̳�");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "ǰ�˼���");
	Book2.book_id = 12346;

	// ͨ���� Book1 �ĵ�ַ����� Book1 ��Ϣ
	printBook(&Book1, 0);
	cout << endl;
	// ͨ���� Book2 �ĵ�ַ����� Book2 ��Ϣ
	printBook(&Book2);
	cout << endl;

	struct Yuan y1;
	y1 = name(1.5);
	cout << "Բ��s=" << y1.s << " , l=" << y1.l << endl;
	if (y1.p != NULL)
	{
		cout << "Բ��p=" << y1.p << " , " << *(y1.p + 0) << endl;
	}
	int i, j;
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 20;j++)
		{
			*(y1.p + i * 20 + j) = i * 20 + j;
			cout << *(y1.p + i * 20 + j) << " ";
		}
		cout << endl;
	}

	if (y1.p != NULL)
	{
		cout << "Բ��p=" << y1.p << " , " << *(y1.p) << endl;
	}
	delete[]y1.p;
	y1.p = NULL;

	return 0;
}

// �ú����Խṹָ����Ϊ����
// �����ṹ����Ҳ�ɿ��ɴ�Сֻ��'1'������
void printBook(Books *book, int a)
{
	cout << "�����  : " << book[0].title << endl;
	cout << "������ : " << book->author << endl;
	cout << "����Ŀ : " << book[0].subject << endl;
	cout << "�� ID : " << book->book_id << endl;
	book->print_t(a);
}

//����һ�����ؽṹ�ĺ���
Yuan name(float r)
{
	float pi(3.1415926);
    Yuan yuan1;
	yuan1.l = 2 * pi*r;
	yuan1.s = pi * r*r;
	yuan1.p = new float[100];
	return yuan1;

}
