#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process {
    public:
        int arr_t;
        int wai_t;
        int id;
        int bur_t;
        int bur_t_copy;
        int com_t;
        int tar_t;
        Process(int a, int b, int c): arr_t(a), bur_t(b), bur_t_copy(b), id(c) {}
};

int main() {
    queue<Process*> q;
    vector<Process*> v;
    int a, b;
    for (int i = 0; i < 4; i++) {
        cout << "-> ";
        cin >> a >> b;
        Process* p = new Process(a, b, i);
        q.push(p);
    }

    int quant, time = 0, n = 0;
    Process* front;
    cout << "Enter time quantum: ";
    cin >> quant;

    while (!q.empty()) {
        front = q.front();
        if (n == 5) {
            time++;
            n = 0;
            continue;
        }
        if (front->arr_t > time) {
            q.pop();
            q.push(front);
            n++;
            continue;
        }
        if (front->bur_t <= quant) {
            time += front->bur_t;
            cout << "Process with id " << front->id << " completed at " << time << endl;
            front->com_t = time;
            front->bur_t = 0;
            front->tar_t = front->com_t - front->arr_t; //arrival time assumed 0
            front->wai_t = front->tar_t - front->bur_t_copy;
            q.pop();
            v.push_back(front);
        } else {
            time += quant;
            front->bur_t -= quant;
            cout << "Process " << front->id << " burst time left: " << front->bur_t << endl;
            q.pop();
            q.push(front);
        }
    }

    int totalwait = 0;
    for (auto i:  v) {
        totalwait += i->wai_t;
    }
    cout << "Average waiting time " << float(totalwait) / v.size() << endl; 
}