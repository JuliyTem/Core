#pragma once
#include <iostream>
class task
{
	int ID;
	int time;
	int Stime;
public:
	task(int _ID = 0, int _time = 1)
	{
		if (_time < 0) throw - 1;
		ID = _ID;
		time = _time;
		Stime = time;
	}
	task& operator=(task &b)
	{
		//if (&b == this) return *this;

		ID = b.ID;
		time = b.time;
		Stime = b.Stime;

		return *this;
	}
	int GetID()
	{
		return ID;
	}
	int GetTime()
	{
		return time;
	}
	void Minus()
	{
		time--;
	}
	int Get_Stime()
	{
		return Stime;
	}
	void Show()
	{
		std::cout << "---- ID " << ID << " | ---- time " << " | " << time << " ----\n";
	}
};
class task_queue
{
	int size, top, end;
	task *mem;
public:
	task_queue(int _size = 10) : size(_size), top(0), end(size - 1) 
	{
		mem = new task[size];
	}
	task_queue(const task_queue &b) : size(b.size), top(b.top), end(b.end)
	{
		mem = new task[size];
		int i = top;
		while (i != end + 1)
		{
			mem[i] = b.mem[i];
			i = (i + 1) % size;
		}
	}
	bool Is_Empty()
	{
		return ((end + 1) % size == top);
	}
	bool Is_Full()
	{
		return ((end + 2) % size == top);
	}
	void Push(task val)
	{
		if (Is_Full()) throw - 1;
		end = (end + 1) % size;
		mem[end] = val;
	}
	task Pop()
	{
		if (Is_Empty()) throw - 1;
		int k = top;
		top = (top + 1) % size;
		return (mem[k]);
	}
	void Show()
	{
		for (int i = top; i < end + 1; i++)
		{
			std::cout << mem[i].GetID() << " | " << mem[i].GetTime() << "\n";
		}
	}
};
