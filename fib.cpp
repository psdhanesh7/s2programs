#include<iostream>
using namespace std;

int main()
{
	int first, second, next, n;

	first=0;
	second=1;

	cout << "Enter the number of terms:";
	cin >> n;

	cout << first << "\t" << second << "\t";
	for(int i = 3; i <= n; i++)
	{
		next = first + second;
		cout << next << "\t";

		first = second;
		second = next;
	}

	cout << endl;
	
	return 0;

}