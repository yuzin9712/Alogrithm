#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int input;
    int minnum = 1000000;
    int maxnum = -1000000;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;
        minnum = min(minnum,input);
        maxnum = max(maxnum, input);
    }

    cout << minnum << " " << maxnum;
    
}

/*얘가 더 빠름 !!! 왜지?*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	int input;
	int max = -1000000, min = 1000000;
	vector<int> v;

	cin >> num;

	v.reserve(num);

	for (int i = 0; i < num; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	for (int j = 0; j < num; j++)
	{
		if (max < v[j])
		{
			max = v[j];
		}
		if (min > v[j])
		{
			min = v[j];
		}
	}

	cout << min << " " << max;
}
*/