//���������ݵĲ����ɾ������Լ�ռ�
//�����������ʱҪ���next�����һ�����鲻̫����
//���Ը�����Ҫ�Զ�������ṹ����һ������������

#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	//����Ľڵ�
	int data;//����
	int num;//�ڵ���
	struct node *next;//ָ����һ���ڵ�
};

int main()
{
	struct node *head/*ͷ�ڵ�*/, *p, *q; //����ָ��ṹ��ָ��
	head = NULL;
	p = NULL;
	q = new node;
	q->next = NULL;
	q->num = 1;
	int a = -1;
	cout << "�������1������:";
	cin >> a;
	q->data = a;
	head = q;
	while (a != 0)
	{
		p = q;  //p����ָ����һ�����нڵ㣬q���ڿ����½ڵ�
		q = new node;
		q->next = NULL;
		p->next = q;
		q->num = p->num + 1;
		cout << "�������" << q->num << "������:";
		cin >> a;
		q->data = a;
	}

	//ǰ�涼������,�����¶������

	q = head;
	p = NULL;
	while (q->data != 0)
	{
		printf("%d %d\n", q->num, q->data);
		q = q->next;
	}

	//�ͷ��ڴ�

	q = head;
	p = q;
	while (q->next != NULL)
	{
		p = q->next;
		delete[]q;
		q = p;
	}
	return 0;
}

