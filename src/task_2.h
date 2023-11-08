/*
 * Author: Malika Xasanboyeva
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cars(N);
    for (int i = 0; i < N; i++) {
        cin >> cars[i];
    }

    stack<int> track1;
    stack<int> deadEnd;
    stack<int> track2;

    int nextCar = 1;
    for (int i = 0; i < N; i++) {
        track1.push(cars[i]);
        while (!track1.empty() && track1.top() == nextCar) {
            deadEnd.push(track1.top());
            track1.pop();
            nextCar++;
        }
    }

    while (!deadEnd.empty()) {
        if (deadEnd.top() == nextCar) {
            track2.push(deadEnd.top());
            deadEnd.pop();
            nextCar++;
        } else {
            break;
        }
    }

    if (nextCar == N + 1) {
        while (!track2.empty()) {
            cout << "2 " << track2.top() << endl;
            track2.pop();
        }
        while (!deadEnd.empty()) {
            cout << "1 " << deadEnd.top() << endl;
            deadEnd.pop();
        }
    } else {
        cout << "0" << endl;
    }

    return 0;
}
