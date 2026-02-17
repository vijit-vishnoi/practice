#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> at(n), bt(n), rt(n), wt(n), tat(n);
    for (int i = 0; i < n; i++) cin >> at[i] >> bt[i];

    rt = bt;
    int complete = 0, t = 0, mn = INT_MAX, shortest = 0;
    bool check = false;

    while (complete != n) {
        mn = INT_MAX;
        check = false;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < mn) {
                mn = rt[i];
                shortest = i;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            int finish = t + 1;
            wt[shortest] = finish - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }

        t++;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    cout << "P\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i+1 << "\t" << at[i] << "\t" 
             << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
}
