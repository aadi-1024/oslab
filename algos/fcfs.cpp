#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Process {
    public:
        int wai_t;
        int arr_t;
        int bur_t;
        int com_t;
        int tar_t;
        Process(int a, int b): arr_t(a), bur_t(b) {}
};

class Comparator {
    public:
    bool operator()(Process first, Process second) {
        return first.arr_t < second.arr_t;
    }
};

int main() {
    vector<Process> vec;
    for (int i = 5; i > 0; i--) {
        vec.push_back(Process(i, 2*i));
    }
    sort(vec.begin(), vec.end(), Comparator());

    int time = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (time < vec[i].arr_t) time = vec[i].arr_t;
        time += vec[i].bur_t;
        cout << "Process with arrival time " << vec[i].arr_t << " completed at " << time << endl;
        vec[i].com_t = time;
        vec[i].tar_t = vec[i].com_t - vec[i].arr_t;
        vec[i].wai_t = vec[i].com_t - vec[i].bur_t;
    }
    int totalwait = 0;
    for (auto i: vec) {
        totalwait += i.wai_t;
    }
    cout << "Average waiting time is " << float(totalwait)/vec.size() << endl;
}