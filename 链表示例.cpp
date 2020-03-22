//链表方便数据的插入和删除，节约空间
//链表访问数据时要逐个next，相比一般数组不太方便
//可以根据需要自定义链表结构，不一定是线性链表

#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	//链表的节点
	int data;//数据
	int num;//节点编号
	struct node *next;//指向下一个节点
};

int main()
{
	struct node *head/*头节点*/, *p, *q; //定义指向结构的指针
	head = NULL;
	p = NULL;
	q = new node;
	q->next = NULL;
	q->num = 1;
	int a = -1;
	cout << "请输入第1个数字:";
	cin >> a;
	q->data = a;
	head = q;
	while (a != 0)
	{
		p = q;  //p用于指向上一个已有节点，q用于开辟新节点
		q = new node;
		q->next = NULL;
		p->next = q;
		q->num = p->num + 1;
		cout << "请输入第" << q->num << "个数字:";
		cin >> a;
		q->data = a;
	}

	//前面都是输入,这以下都是输出

	q = head;
	p = NULL;
	while (q->data != 0)
	{
		printf("%d %d\n", q->num, q->data);
		q = q->next;
	}

	//释放内存

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

