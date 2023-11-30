#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process {
    public:
        int pid;
        vector<int> alloc, need;
        
        Process(int p): pid(p) {}

        bool can_execute(vector<int>& available) {
            for (int i = 0; i < alloc.size(); i++) {
                if (available[i] < need[i]) {
                    return false;
                }
            }
            return true;
        }

        void execute(vector<int>& available) {
            for (int i = 0; i < alloc.size(); i++) {
                available[i] += alloc[i];
                alloc[i] = 0;
            }
        }
};

int main() {
    int p, r;
    cout << "Enter processes: ";
    cin >> p;
    cout << "Enter resources: ";
    cin >> r;

    queue<Process*> q;
    vector<int> avail;
    Process* front;
    int temp;
    for (int i = 0; i < p; i++) {
        front = new Process(i);
        cout << "Enter alloc for process " << i << " =>";
        for (int j = 0; j < r; j++) {
            cin >> temp;
            front->alloc.push_back(temp);
        }
        cout << "Enter need for process " << i << " =>";
        for (int j = 0; j < r; j++) {
            cin >> temp;
            front->need.push_back(temp);
        }
        q.push(front);
    }

    cout << "Enter available =>";
    for (int i = 0; i < r; i++) {
        cin >> temp;
        avail.push_back(temp);
    }

    bool executed;
    Process* start;
    while (!q.empty()) {
        front = q.front();
        if (front->can_execute(avail)) {
            executed = true;
            front->execute(avail);
            start = nullptr;
            cout << "Executed process " << front->pid << endl;
            cout << "Available: " << endl;
            for (auto i: avail) {
                cout << i << ' ';
            }
            cout << endl;
            q.pop();
        } else {
            if (start == front) {
                break;
            }
            if (!start) {
                start = front;
                executed = false;
            }
            q.pop();
            q.push(front);
        }
    }
    if (q.empty()) {
        cout << "safe" << endl;
    } else {
        cout << "unsafe" << endl;
    }
}