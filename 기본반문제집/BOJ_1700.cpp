#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, cnt(101, 0);
vector<bool> plug(101, 0);

int getSize() {
    int size = 0;

    for(int i = 0; i < plug.size(); i++) {
        if(plug[i]) {
            size++;
            cout << i << " ";
        }
    }
    cout << " size : " << size << "\n";
    return size;
}

int main() {
    int n, k, input, size = 0, answer = 0;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> input;
        arr.push_back(input);
        cnt[input]++;
    }

    for(int i = 0; i < arr.size(); i++) {
        size = getSize();

        if(!plug[arr[i]]) {

            /*플러그에 비어 있는 자리 있는 경우*/
            if(size < n) {
                plug[arr[i]] = 1;
                cnt[arr[i]]--;
            } else {
                bool type = true;
                int index = -1;

                for(int j = 1; j < plug.size(); j++) {
                    if(plug[j] == 1 && cnt[j] == 0) {
                        type = false;
                        plug[j] = 0;
                        answer++;
                        plug[arr[i]] = 1;
                        cnt[arr[i]]--;
                        break;
                    }

                    if(plug[j] == 1 && cnt[j] != 0 && index < j) {
                        index = j;
                    }

                    // for(int k = i + 1; k < arr.size(); k++) {
                    //     if(plug[j] == 1 && j == arr[k]) {
                    //         if(index < k)   index = k;
                    //         break;
                    //     }
                    // }
                }

                if(type) {
                    // plug[arr[index]] = 0;
                    plug[index] = 0;
                    answer++;
                    plug[arr[i]] = 1;
                    cnt[arr[i]]--;
                }

            }
        } else {
            cnt[arr[i]]--;
        }
    }

    cout << answer;


}