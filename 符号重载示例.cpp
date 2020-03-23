//���ŵ����ؽ�Ϊ���ӣ�һ�½��Զ�Ԫ������������Ϊ������Ҫ�������ʽ
//���ŵ������迼��ԭ���ŵ����͡�����ԡ����ȼ�������ʽ��

#include<iostream>
using namespace std;

template <typename _TT>  //ʹ�� _TT ��������
class A
{
private:
	_TT a;
public:
	A();
	A(_TT n);
	~A()
	{cout<<"you delete a A-Object"<<endl;}

	_TT get_a()
	{
		return this->a;
	}
	
//��'='����ֻ����Ϊ��Ա������������Ϊ��Ԫ����
//��Ԫ�������Է�������ͬ������˽�г�Ա��
//����Ա����ֻ�ܷ����Լ������˽�г�Ա�����ܷ���ͬ�����������˽�г�Ա��
//��������ʵ���˲�ͬ�������͵Ķ�����ڸ�ֵʱ��ת����
//��Ա������ʹ�����ģ�壬�������µ�ģ��
	template <typename U>
	A<_TT>& operator=(A<U> & obj)
	{
		this->a=obj.get_a();
		return *this;
	}
	void display();

//��Ԫ������������ĳ�Ա����Ҫ���ⶨ��ģ��
//һ��ģ���пɰ������typename
//�����õķ�ʽ������󣬲����ں������д�����ʱ����
//���Դ�ֵ��ʽ�������ں����д�����ʱ�����뿪����ʱ��ɾ����ʱ���󲢵�������������
    template <typename U, typename V>
	friend A<double>& operator+(A<U>& obj1, A<V>& obj2);
    template <typename U, typename V>
	friend A<double>& operator+(A<U>& obj, V& b);
    template <typename U, typename V>
	friend A<double>& operator+(V& b, A<U>& obj);
};

template <typename _TT>
A<_TT>::A()
{
	a = 0;
}

template <typename _TT>
A<_TT>::A(_TT n)//���캯�� 
{
	a = n;
}

template <typename U, typename V>
A<double>& operator+(A<U>& obj1, A<V>& obj2)//����+�����ڶ����������� 
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj1.a) + double(obj2.a);
	return *obj3;
}

template <typename U, typename V>
A<double>& operator+(A<U>& obj, V& b)//����+�����ڶ����������
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj.a) + double(b);
	return *obj3;  
}

template <typename U, typename V>
A<double>& operator+(V& b, A<U>& obj) //ע����Ԫ�����Ķ����ʽ
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj.a) + double(b);
	return *obj3;  
}

template <typename _TT>
void A<_TT>::display() //��Ա�������ⶨ��ʱҪ��'::'
{
	cout << a << endl;
}

int main()
{
	A<int> a1(1);
	A<double> a2(2.5);
	A<float> a3, a4, a5; 

	a1.display();
	a2.display();
	a3 = a1 + a2;
	a3.display();
	a2.~A(); //��������������������

	double m = 3.1415926;
	a4 = a1 + m;
	a4.display();
	a5 = m + a1;
	a5.display();

	a3=a1;
	a3.display();

	return 0;
}


