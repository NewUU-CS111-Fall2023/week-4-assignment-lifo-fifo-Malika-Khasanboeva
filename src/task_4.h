#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<stack<int>> stacks(N);
    vector<int> containerTypes;

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
            containerTypes.push_back(type);
        }
    }

    vector<stack<int>> resultStacks(N);

    for (int type : containerTypes) {
        int sourceStack = -1;
        for (int i = 0; i < N; i++) {
            if (!stacks[i].empty() && stacks[i].top() == type) {
                sourceStack = i;
                break;
            }
        }
        if (sourceStack == -1) {
            cout << "0" << endl;
            return 0;
        }

        cout << sourceStack + 1 << " ";

        for (int i = 0; i < N; i++) {
            if (resultStacks[i].empty() || resultStacks[i].top() > type) {
                resultStacks[i].push(stacks[sourceStack].top());
                stacks[sourceStack].pop();
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
