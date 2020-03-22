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

//友元函数不属于类的成员，需要另外定义模板
//一个模板中可包括多个typename
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
A<_TT>::A(_TT n)//构造函数 
{
	a = n;
}

template <typename U, typename V>
A<double> operator+(A<U> obj1, A<V> obj2)//重载+号用于对象相加 
{
	A<double> obj3;
	obj3.a = double(obj1.a) + double(obj2.a);
	return obj3;
}

template <typename U, typename V>
A<double> operator+(A<U> obj, V b)//重载+号用于对象与数相加
{
	A<double> obj3;
	obj3.a = double(obj.a) + double(b);
	return obj3;  
}

template <typename U, typename V>
A<double> operator+(V b, A<U> obj) //注意友元函数的定义格式
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
//根据以上重载规则，任何进行赋值操作的'A'对象，都应定义为double型
//这是由于没有进行'='的重载，对象间无法实现类型转化
//'='的重载函数不能作为类的友元函数，只能作为成员函数
//要对'='做重载似乎较复杂，尚未实现。
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


