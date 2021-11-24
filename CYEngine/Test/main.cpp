#include<iostream>
#include<RenderEngine.h>
using namespace std;
using namespace Cherry;
int main()
{
	
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