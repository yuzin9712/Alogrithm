#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

bool comp(tuple <int, int, string> a, tuple <int, int, string> b);

int main() {

    int n, age;
    string name;
    vector <tuple <int, int, string>> arr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> age >> name;

        arr.push_back(make_tuple(i, age, name));
    }

    sort(arr.begin(), arr.end(), comp);

    for(int j = 0; j < n; j++) {
        cout << get<1>(arr[j]) << " " << get<2>(arr[j]) << "\n";
    }

}

bool comp(tuple <int, int, string> a, tuple <int, int, string> b) {
    if(get<1>(a) != get<1>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}