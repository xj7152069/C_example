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

//��Ԫ������������ĳ�Ա����Ҫ���ⶨ��ģ��
//һ��ģ���пɰ������typename
    template <typename U, typename V>
	friend A<double> operator+(A<U> obj1, A<V> obj2);
    template <typename U, typename V>
	friend A<double> operator+(A<U> obj, V b);
    template <typename U, typename V>
	friend A<double> operator+(V b, A<U> obj);
	void display();
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
A<double> operator+(A<U> obj1, A<V> obj2)//����+�����ڶ������ 
{
	A<double> obj3;
	obj3.a = double(obj1.a) + double(obj2.a);
	return obj3;
}

template <typename U, typename V>
A<double> operator+(A<U> obj, V b)//����+�����ڶ����������
{
	A<double> obj3;
	obj3.a = double(obj.a) + double(b);
	return obj3;  
}

template <typename U, typename V>
A<double> operator+(V b, A<U> obj) //ע����Ԫ�����Ķ����ʽ
{
	A<double> obj3;
	obj3.a = double(obj.a) + double(b);
	return obj3;  
}

template <typename _TT>
void A<_TT>::display()
{
	cout << a << endl;
}

int main()
{
	A<int> a1(1);
	A<int> a2(2);
	A<double> a3, a4, a5; 
//�����������ع����κν��и�ֵ������'A'���󣬶�Ӧ����Ϊdouble��
//��������û�н���'='�����أ�������޷�ʵ������ת��
//'='�����غ���������Ϊ�����Ԫ������ֻ����Ϊ��Ա����
//Ҫ��'='�������ƺ��ϸ��ӣ���δʵ�֡�
	a1.display();
	a2.display();
	a3 = a1 + a2;
	a3.display();

	float m = 3.1415926;
	a4 = a1 + m;
	a4.display();
	a5 = m + a1;
	a5.display();

	return 0;
}


