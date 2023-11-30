#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Process {
    public:
        int pid;
        int wai_t;
        int arr_t;
        int bur_t;
        int bur_t_copy;
        int com_t;
        int tar_t;
        int priority;
        Process(int a, int b, int p, int c): arr_t(a), bur_t(b), bur_t_copy(b), priority(p), pid(c) {}
};

class Comparator {
    public:
        bool operator()(Process* f, Process* s) {
            return f->priority > s->priority;
        }
};

int main() {
    vector<Process*> v;

    int n, a, b, p;
    Process* temp, *cur;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "-> ";
        cin >> a >> b >> p;
        temp = new Process(a, b, p, i);
        v.push_back(temp);
    }
    int time = 0;
    int index;
    while (!v.empty()) {
        sort(v.begin(), v.end(), Comparator());
        temp = v[0];
        index = 0;
        if (temp->arr_t > time) {
            int i = 1;
            do {
                index = i;
                temp = v[i++];
            } while (i != v.size() && temp->arr_t > time);
        }
        if (temp->arr_t > time) {
            time++;
        } else {
            temp->bur_t--;
            time++;
            cout << "Process " << temp->pid << " time left: " << temp->bur_t << " at time = " << time << endl;
            if (temp->bur_t == 0) {
                cout << "Process " << temp->pid << " executed" << endl;
                cur = v[v.size()-1];
                v[v.size()-1] = temp;
                v[index] = cur;
                v.pop_back();
            }
        }
    }
}