#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cin >> n;

    for(int i = 1; i < n; i++) {
        int sum = 0;
        sum = sum + i;
        string num = to_string(i);

        for(int j = 0; j < num.size(); j++) {
            sum = sum + num[j] - '0';
        }

        if(sum == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}

/*전에 푼 코드가 더 빠름 ㅡㅡ*/
/*
#include <cstdio>
using namespace std;

int main()
{
	int input;
	int sum;

	scanf("%d",&input);

	for(int i = 1; i <= 1000000; i++)
	{
		int x = i;
		int y = x;
		sum = i;

		while(y)
		{
			x = y%10;
			y = y/10;
			sum = sum + x;
		}

		if(sum == input)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
}
*/