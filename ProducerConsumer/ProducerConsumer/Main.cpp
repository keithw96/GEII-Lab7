#include <iostream>
#include <thread>
#include <time.h>

int buf; int p = 1; int c = 1; int n = 500;

void producer()
{
	static int a = 0;

	std::cout << "Producer starting" << std::endl;

	while (p < n)
	{
		while (p != c)
		{
		//	std::cout << "Short order cook spinning" << std::endl;
		}

		a = (int)rand() * 100;
		std::cout << "Making a burger: " << p << std::endl;
		buf = a;
		p = p + 1;
	}
	std::cout << "Finished making burgers" << std::endl;
}

void consumer()
{
	static int b = 0;

	std::cout << "Consumer Starting" << std::endl;
	while (c < n)
	{
		while (p <= c)
		{
			//std::cout << "Starving waiting on a burger" + c << std::endl;
		}
		std::cout << "Eating Burger: " << c << std::endl;
		b = buf;
		c = c + 1;
	}
	std::cout << "Finished Eating Burgers" << std::endl;
}

int main()
{
	srand(time(NULL));

	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();

	return 0;
}