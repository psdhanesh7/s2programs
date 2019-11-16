#include <bits/stdc++>
using namespace std;

class Stack
{
	public :

		int top = -1, size;

	private:

		void Push()
		{
			if(top == size-1)
				cout<<"Stack overflow"<<endl;
			else{

				top++;

			}
		}
		


};
int main(int argc, char const *argv[])
{
	

	return 0;
}