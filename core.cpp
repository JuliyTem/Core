#include "Core.h" 
#include <time.h>

int main()
{
	try
	{
		srand(time(0));
		int num = 10;
		task_queue tasks(num);
		task a(1, 10);
		task b(2, 5);
		task c(3, 7);
		task d(4, 2);
		task e(5, 20);
		task f(6, 5);
		task g(7, 6);
		task h(8, 2);
		task i(9, 15);
		//task j(10, 4);

		tasks.Push(a);
		tasks.Push(b);
		tasks.Push(c);
		tasks.Push(d);
		tasks.Push(e);
		tasks.Push(f);
		tasks.Push(g);
		tasks.Push(h);
		tasks.Push(i);
		//tasks.Push(j);
		//tasks.Show();

		int size = 9;

		if (size > num) size = num - 1;

		task *p = new task[size];
		
		int k = 0;
		
		for (int i = 0; i < size; i++)
		{
			if (tasks.Is_Empty()) break;
			p[i] = tasks.Pop();
			//std::cout << "Core " << i << " | " << p[i].GetID() << " | " << p[i].GetTime() << "\n";
		}

		while (k != size)
		{
			for (int i = 0; i < size; i++)
			{
				if (p[i].GetTime() != 0)
				{
					p[i].Minus();
					//p[i].Show();

					if (p[i].GetTime() == 0)
					{
						std::cout << "| Core - " << i << " | ID - " << p[i].GetID() << " | Time - " << p[i].Get_Stime() << " \n";
						/*int r = rand() % 10;
						if ((r >= 5) && (r <= 8))
						{
							if (!tasks.Is_Full())
							{
								task a(p[i].GetID() + 1000, rand() % 2);
								tasks.Push(a);
							}
						}
						else if ((r >= 2) && (r <= 4)) 
						{
							for (int j = 0; j < 2; j++)
							{
								if (!tasks.Is_Full())
								{
									task a(p[i].GetID() + 1000, rand() % 2);
									tasks.Push(a);
								}
							}
						}
						else
						{
							for (int j = 0; j < 3; j++)
							{
								if (!tasks.Is_Full())
								{
									task a(p[i].GetID() + 1000, rand() % 2);
									tasks.Push(a);
								}
							}
						}*/
						if (tasks.Is_Empty())
						{
							k++;
						}
						else
						{
							p[i] = tasks.Pop();
						}
					}
				}
			}

		}
	}
	catch (int)
	{
		std::cout << "GG";
	}

	return 0;
}
