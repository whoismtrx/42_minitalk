#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t, a, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> m;
		if (a < m)
			cout << "Mehdi" << endl;
		else if (a > m)
			cout << "Adam" << endl;
		else
			cout << "Tie" << endl;
	}
}