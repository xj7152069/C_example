

#include <iostream> 
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class student
{
//�������еĹ��г�Ա�����е��ⲿ���򶼿ɷ��ʹ��г�Ա
//ͨ���������ǽ����е�������Ϊ˽�У��ⲿ����ͨ�����к������������޸�
public:
	char name[20];
	char sex[10];
	float *p = NULL;
	float math;
	float english;
	float cprogram;
//���µĺ����������������������������ⶨ��
	void input_name();
	void input_sex();
	void input_math();
	void input_english();
	void input_cprogram();

//�Դ�ַ�����õķ�ʽ�������ݶ���
	void input(student *stu);
	void show_student_massage(student &stu);

	//��Ĺ��캯���������ڶ����б����ĳ�ʼ��
	student(float n = 0.0)
	{
		p = new float(n);
		cout << "you create a new class student!" << endl;
	}

	/*��Ŀ������캯�������ڶ����µĶ���ʱ��
	  �����ж�������ݿ������¶���Ķ����У�
	  ������г�ʼ����*/
	student(const student& s)
	{
		p = new float;
		*p = *(s.p);
	}

	/*��������������������ĳ�����󽫱�ɾ��ǰ�����뿪�����ڵ�����ǰ����
	  ��õ��ø�������������ʹ�����е�ָ��Ƚ��ڴ��ͷ��Լ���ֹ�ڴ�й©*/
	~student()
	{
		delete[]p;
		p = NULL;
		cout << "the class student have been delete" << endl;
	}
};

//���¶����������ĺ������ж���
void student::input_name()
{
	cout << "����ѧ�������� " << endl;
	cin.getline(name, sizeof(name));
	cout << "ѧ������ �� " << name << endl;
}

void student::input_sex()
{
	cout << "����ѧ���Ա� " << endl;
	cin.getline(sex, sizeof(sex));
}

void student::input_math()
{
	cout << "����ѧ����ѧ�� " << endl;
	cin >> math;
}

void student::input_english()
{
	cout << "����ѧ��Ӣ� " << endl;
	cin >> english;
}

void student::input_cprogram()
{
	cout << "����ѧ��C���ԣ� " << endl;
	cin >> cprogram;
}

//��"student"��Ķ����Զ���ָ�����ʽ���뺯��
void student::show_student_massage(student &stu)
{
	cout << "ѧ������ �� " << stu.name << endl;
	cout << "ѧ���Ա� �� " << stu.sex << endl;
	cout << "ѧ����ѧ �� " << stu.math << endl;
	cout << "ѧ��Ӣ�� �� " << stu.english << endl;
	cout << "ѧ��C���ԣ� " << stu.cprogram << endl;
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
	student xj=xiaoming; //��ʼ������ÿ������캯����ָ��ָ��ͬ��ַ
	//xj=xiaoming; //���÷�����ȫ����Ҫ��'='�������ز��ܰ�ȫ���á�
	*(xj.p) = 2.5;
	cout << "xm:" << xiaoming.p << "--" << *(xiaoming.p) << endl;
	cout << "xj:" << xj.p << "--" << *(xj.p) << endl;
	return 0;
}


