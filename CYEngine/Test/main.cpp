#include<iostream>
#include<RenderEngine.h>
using namespace std;

struct AA{
	int a;
	int b;
	int c;
	int d;
};

struct  A
{
	float a;
	AA d;//16
	float c;//4
};//40

struct B
{
	float c;//4
	float a;//
	AA d;//16
};

int main()
{
	cout << "A size:" << sizeof(A) << ",B size:" << sizeof(B) << endl;
	
	RenderEngine* engine = new RenderEngine();
	if (engine->createWindow(800, 600, "Test")) {
		cout << "Engine Test Start." << endl;
		engine->start();
	}
	else
	{
		cout << "Engine Window Create Failed." << endl;
	}
	return 0;
};


//
//
//class A {
//public:
//	int i;
//	A():i(20) {};
//	
//	void operator = (A & a){
//		cout << "AA" << endl;
//	};
//
//	virtual void C() {
//		cout << "A::C" << endl;
//	};
//
//	~A() {
//		cout << "~A" << endl;
//	};
//};
//
//
//class B :A {
//public:
//	~B() {
//		cout << "~B" << endl;
//	};
//
//	 void C() {
//		cout << "B::C" << endl;
//	};
//};
//
//struct MyStruct
//{
//
//	int a;
//	int a1;
//	double v;
//};
//int main() {
//
////	A a;
//////	A b = a;
////	A c;
////	c = a;
//	int* b = (int *)new B();
//	cout<<*(b) << endl;
//	cout << *(b+1) << endl;
//	((A*)b)->C();
//	delete (A*)b;
//
//
//	MyStruct s{19,12,22.33};
//	cout << "sizeof struct:" << sizeof(s)<<",sizeof(int):" << sizeof(int)<<",sizeof(bool):" << sizeof(bool) <<",sizeof(double):" << sizeof(double) << endl;
//	int** ps = (int **)&s;
//	cout <<"ps:"<<(**ps) << endl;
//	int** ps1 = ps+1;
//	cout <<"ps1:"<<(**ps1) << endl;
//	double** ps2 =(double **)(ps + 2);
//	cout <<"ps2:"<< (**ps2) <<", offset:"<< (int*)*ps2 - *ps<< endl;
//	while (true)
//	{
//
//	}
//	return 0;
//}

/**
* uniform IncorrectUBOOrder {
  float f1_1; // 16
  vec4 v2; // 16  
  float f1_2; // 16
}; 
32+4=36  

48-36=12
16 32 48 64

 uniform CorrectUBOOrder {
  float f1_1; //16
  float f1_2; //16
  vec2 v2; // 16
}; /
32

*/
