

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

//“圆”的结构类型申明
//该结构中将包含一个指针数组'p'
struct Yuan
{
	float s;
	float l;
	float *p = NULL;
};

//函数申明，将“圆”结构变量作为返回值
//对已申明的结构，可直接将其结构名作为变量
//调用结构变量时可省略"struct"关键字
Yuan name(float r);

//定义Books结构
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
	void print_t(int a)
	{
		if (a == 1)
			cout << "可借" << endl;
		else if (a == 0)
			cout << "不可借" << endl;
		else
			cout << "状态不明" << endl;
	}
};

//以下函数将 struct Books 类型变量作为形参
void printBook(Books *book, int a=1);

int main()
{
	Books Book1;        // 定义结构体类型 Books 的变量 Book1
	Books Book2;        // 定义结构体类型 Books 的变量 Book2

	 // Book1 详述，调用cstring函数赋值
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "前端技术");
	Book2.book_id = 12346;

	// 通过传 Book1 的地址来输出 Book1 信息
	printBook(&Book1, 0);
	cout << endl;
	// 通过传 Book2 的地址来输出 Book2 信息
	printBook(&Book2);
	cout << endl;

	struct Yuan y1;
	y1 = name(1.5);
	cout << "圆：s=" << y1.s << " , l=" << y1.l << endl;
	if (y1.p != NULL)
	{
		cout << "圆：p=" << y1.p << " , " << *(y1.p + 0) << endl;
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
		cout << "圆：p=" << y1.p << " , " << *(y1.p) << endl;
	}
	delete[]y1.p;
	y1.p = NULL;

	return 0;
}

// 该函数以结构指针作为参数
// 单个结构变量也可看成大小只有'1'的数组
void printBook(Books *book, int a)
{
	cout << "书标题  : " << book[0].title << endl;
	cout << "书作者 : " << book->author << endl;
	cout << "书类目 : " << book[0].subject << endl;
	cout << "书 ID : " << book->book_id << endl;
	book->print_t(a);
}

//定义一个返回结构的函数
Yuan name(float r)
{
	float pi(3.1415926);
    Yuan yuan1;
	yuan1.l = 2 * pi*r;
	yuan1.s = pi * r*r;
	yuan1.p = new float[100];
	return yuan1;

}
