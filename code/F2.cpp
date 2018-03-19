#include"source.h";
#define P0 0
#define P1 (-1)
#define P2 (-2)
#define P3 (-3)
#define top_1(v) (v.back())
#define top_2(v) (*(v.end() - 2))
#define DEBUG

void print_stack(vector<int>& stack)
{
	for (vector<int>::iterator it = stack.begin();
		it != stack.end(); it++)
	{
		if (*it > 0)
			cout << *it << ' ';
		else
			cout << 'P' << abs(*it) << ' ';
	}
	cout << endl;
}
void call(vector<int>& stack, int& pc, int arg)
{
	stack.push_back(pc);
	stack.push_back(arg);
	pc = P0;
#ifdef DEBUG
	cout << "after call: ";
	print_stack(stack);
#endif
}
void ret(vector<int>& stack, int& pc, int rlt, int nvar)
{
	stack._Pop_back_n(nvar);
#ifdef DEBUG
	cout << "after ret1: ";
	print_stack(stack);
#endif
	pc = top_1(stack);
	stack.pop_back();
	stack.push_back(rlt);
#ifdef DEBUG
	cout << "after ret: ";
	print_stack(stack);
#endif 
}
#ifdef F2
int f(int x)
{
	vector<int> stack;
	int pc = P3;
	call(stack, pc, x);
	do {
		switch (pc)
		{
			case P0:
				if (top_1(stack) <= 2)
				{
					ret(stack, pc, 1, 1);
				}
				else
				{
					pc = P1;
					call(stack, pc, top_1(stack) - 1);
				}
				break;
			case P1:
				pc = P2;
				call(stack, pc, top_2(stack) - 2);
				break;
			case P2:
				ret(stack, pc, top_1(stack) + top_2(stack), 3);
				break;
			case P3:
				cout << "P3" << endl;
				break;
		}
	} while (stack.size() > 1);
	return stack[0];
}
#endif
