#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

class Comparator {
    public:
        bool operator()(Process* first, Process* second) {
            return first->bur_t < second->bur_t;
        }
};

int main() {
    vector<Process*> v;
    Process* temp, *cur;
    int a, b;
    for (int i = 0; i < 5; i++) {
        cout << "-> ";
        cin >> a >> b;
        temp = new Process(a,b,i);
        v.push_back(temp);
    }
    int time = 0, index;
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
            time += temp->bur_t;
            temp->bur_t = 0;
            cout << "Process " << temp->id << " executed at time " << time << endl;
            cur = v[v.size()-1];
            v[v.size()-1] = temp;
            v[index] = cur;
            v.pop_back();
        }
    }
}