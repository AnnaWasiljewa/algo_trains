#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    string s;
	cin >> a >> b;
	cin >> s;
	if (s == "freeze")
	    cout << min(a, b) << endl;
	else if (s == "heat")
	    cout << max(a, b);
	else if (s == "auto")
	    cout << b;
	else if (s == "fan")
	    cout << a;
	else
	    cout << "error";
	return 0;
}
