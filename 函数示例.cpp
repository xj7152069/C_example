

#include <iostream>
using namespace std;

//函数申明
void fun1 (int N, float &input_a, float *inptu_b, float input_c , float &output_d, float **output_e);

int main()
{

	int i, j, k, N(3);
	float a, *b = NULL, **e=NULL, c(1.5), d;
	a = 3;

//用new定义数组，一维或二维
	b = new float [9];
	e = new float* [3];
	for (k = 0;k < 3;k++)
	{
		e[k] = new float[3];
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			b[i*N + j] = a;
		}
	}

	fun1(N, a, b, c, d, e);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout<<e[i][j]<<" | ";
		}
		cout << endl;
	}

//释放内存，并将指针置于NULL
	delete[]b;
	b = NULL;
	for (k = 0;k < 3;k++)
		delete[]e[k];
	delete[]e;
	e = NULL;

	std::cout << "Hello World!\n";
	return 0;
}

//////////////////////function define//////////////////////////
void fun1(int N, float &input_a, float *input_b, float input_c, float &output_d, float **output_e)
{
	int i, j;
	output_d = input_a + input_c;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			output_e[i][j] = input_b[i*N + j] + input_c;
		}
	}

}










