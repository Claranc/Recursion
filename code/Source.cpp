#include"source.h";

void main()
{
	int n;
	cin >> n;
	//cout << f(n) << endl; // P3

	/*vector<int> buff(n + 1, 0);
	buff[1] = buff[2] = 1;
	cout << f(n, buff) << endl;*/

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		f(rand() % 100 + 1);
}
