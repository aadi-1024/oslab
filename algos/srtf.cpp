#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Process {
    public:
        int pid;
        int wai_t;
        int arr_t;
        int bur_t;
        int com_t;
        int tar_t;
        Process(int a, int b, int pid): arr_t(a), bur_t(b), pid(pid) {}
};

class Comparator {
    public:
        bool operator()(Process* first, Process* second) {
            return first->bur_t < second->bur_t;
        }
};

int main() {
    vector<Process*> v;
    queue<Process> que;
    Process* temp,*cur;
    int a,b;
    for (int i = 0; i < 5; i++) {
        cout << "-> ";
        cin >> a >> b;
        temp = new Process(a, b, i);
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