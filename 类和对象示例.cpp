

#include <iostream> 
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class student
{
//定义类中的公有成员，所有的外部程序都可访问公有成员
//通常的做法是将类中的数据设为私有，外部程序通过公有函数对数据做修改
public:
	char name[20];
	char sex[10];
	float *p = NULL;
	float math;
	float english;
	float cprogram;
//以下的函数均先在类内申明，在类语句块外定义
	void input_name();
	void input_sex();
	void input_math();
	void input_english();
	void input_cprogram();

//以传址或引用的方式向函数传递对象
	void input(student *stu);
	void show_student_massage(student &stu);

	//类的构造函数，常用于对象中变量的初始化
	student(float n = 0.0)
	{
		p = new float(n);
		cout << "you create a new class student!" << endl;
	}

	/*类的拷贝构造函数，用于定义新的对象时，
	  将已有对象的数据拷贝到新定义的对象中，
	  对其进行初始化。*/
	student(const student& s)
	{
		p = new float;
		*p = *(s.p);
	}

	/*类的析构函数，当该类的某个对象将被删除前（如离开其所在的语句块前），
	  最好调用该析构函数，以使对象中的指针等将内存释放以及防止内存泄漏*/
	~student()
	{
		delete[]p;
		p = NULL;
		cout << "the class student have been delete" << endl;
	}
};

//以下对类中申明的函数进行定义
void student::input_name()
{
	cout << "输入学生姓名： " << endl;
	cin.getline(name, sizeof(name));
	cout << "学生姓名 ： " << name << endl;
}

void student::input_sex()
{
	cout << "输入学生性别： " << endl;
	cin.getline(sex, sizeof(sex));
}

void student::input_math()
{
	cout << "输入学生数学： " << endl;
	cin >> math;
}

void student::input_english()
{
	cout << "输入学生英语： " << endl;
	cin >> english;
}

void student::input_cprogram()
{
	cout << "输入学生C语言： " << endl;
	cin >> cprogram;
}

//将"student"类的对象，以对象指针的形式传入函数
void student::show_student_massage(student &stu)
{
	cout << "学生姓名 ： " << stu.name << endl;
	cout << "学生性别 ： " << stu.sex << endl;
	cout << "学生数学 ： " << stu.math << endl;
	cout << "学生英语 ： " << stu.english << endl;
	cout << "学生C语言： " << stu.cprogram << endl;
}

void student::input(student *stu)
{
	stu->input_name();
	stu->input_sex();
	stu->input_math();
	stu->input_english();
	stu->input_cprogram();
}

int main()
{
	student xiaoming(1.2);
	student *xiaoming_point = &xiaoming;
	xiaoming.input(xiaoming_point);
	xiaoming.show_student_massage(*xiaoming_point);
	xiaoming.show_student_massage(xiaoming);
	student xj=xiaoming; //初始化则调用拷贝构造函数，指针指向不同地址
	//xj=xiaoming; //该用法不安全，需要对'='进行重载才能安全调用。
	*(xj.p) = 2.5;
	cout << "xm:" << xiaoming.p << "--" << *(xiaoming.p) << endl;
	cout << "xj:" << xj.p << "--" << *(xj.p) << endl;
	return 0;
}


