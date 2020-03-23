//符号的重载较为复杂，一下仅以二元操作符的重载为例，简要介绍其格式
//符号的重载需考虑原符号的类型、结合性、优先级、语句格式等

#include<iostream>
using namespace std;

template <typename _TT>  //使用 _TT 代替类型
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
	
//对'='重载只能作为成员函数，不能作为友元函数
//友元函数可以访问所有同类对象的私有成员；
//而成员函数只能访问自己对象的私有成员，不能访问同类其他对象的私有成员；
//以下重载实现了不同数据类型的对象间在赋值时的转换；
//成员函数可使用类的模板，并定义新的模板
	template <typename U>
	A<_TT>& operator=(A<U> & obj)
	{
		this->a=obj.get_a();
		return *this;
	}
	void display();

//友元函数不属于类的成员，需要另外定义模板
//一个模板中可包括多个typename
//以引用的方式传入对象，不会在函数体中创建临时变量
//若以传值方式传入则在函数中创建临时对象，离开函数时将删除临时对象并调用析构函数。
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
A<_TT>::A(_TT n)//构造函数 
{
	a = n;
}

template <typename U, typename V>
A<double>& operator+(A<U>& obj1, A<V>& obj2)//重载+号用于对象与对象相加 
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj1.a) + double(obj2.a);
	return *obj3;
}

template <typename U, typename V>
A<double>& operator+(A<U>& obj, V& b)//重载+号用于对象与数相加
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj.a) + double(b);
	return *obj3;  
}

template <typename U, typename V>
A<double>& operator+(V& b, A<U>& obj) //注意友元函数的定义格式
{
	A<double> *obj3;
	obj3=new A<double>;
	obj3->a = double(obj.a) + double(b);
	return *obj3;  
}

template <typename _TT>
void A<_TT>::display() //成员函数类外定义时要加'::'
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
	a2.~A(); //可以主动调用析构函数

	double m = 3.1415926;
	a4 = a1 + m;
	a4.display();
	a5 = m + a1;
	a5.display();

	a3=a1;
	a3.display();

	return 0;
}


