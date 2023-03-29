#include <iostream>
#include <queue>

using namespace std;

int K = 4;

int main () {

    int r1 = 0, r2 = 0, r3 = 0;
    queue<int> A1, B1;
    queue<int> A2, B2;
    int A1_pop_count = 0, A2_pop_count = 0;

    size_t time_rec = 0;

    while (1) {

        int input;
        int output1 = -1;
        int output2 = -1;
        cin >> input;
        
        /*  Step 1 : Merge
            pair: <X_2i, X_2i+1>
            X_2i     ->    [ A ]
            X_2i+1   ->    [ B ]
        */

        // 1-merger
        int k = 1;
        if (r1 > k) {
            if (A1.empty()) {
                // cout << 1 << endl;
                output1 = B1.front();
                B1.pop();
            } else if (B1.empty()) {
                // cout << 2 << endl;
                output1 = A1.front();
                A1.pop();
                A1_pop_count += 1;
            } else if (A1.front() < B1.front() && A1_pop_count < k) {
                // cout << 3 << endl;
                output1 = A1.front();
                A1.pop();
                A1_pop_count += 1;
            } else {
                // cout << 4 << endl;
                output1 = B1.front();
                B1.pop();
            }
        }
        if (r1 % (2 * k) < k) {
            A1.push(input);
            // cout << "Push into A\n";
        } else {
            B1.push(input);
            // cout << "Push into B\n";
        }
        if (r1 - k > 0 && ((r1 - k) % (2 * k) == 0)) {
            A1_pop_count = 0;
        }

        r1 += 1;

        if (output1 > 0) {
            int k = 2;
            if (r2 > k) {
                if (A2.empty()) {
                    // cout << 1 << endl;
                    output2 = B2.front();
                    B2.pop();
                } else if (B2.empty()) {
                    // cout << 2 << endl;
                    output2 = A2.front();
                    A2.pop();
                    A2_pop_count += 1;
                } else if (A2.front() < B2.front() && A2_pop_count < k) {
                    // cout << 3 << endl;
                    output2 = A2.front();
                    A2.pop();
                    A2_pop_count += 1;
                } else {
                    // cout << 4 << endl;
                    output2 = B2.front();
                    B2.pop();
                }
            }
            if (r2 % (2 * k) < k) {
                A2.push(output1);
                // cout << "Push into A\n";
            } else {
                B2.push(output1);
                // cout << "Push into B\n";
            }
            if (r2 - k > 0 && ((r2 - k) % (2 * k) == 0)) {
                A2_pop_count = 0;
            }

            r2 += 1;
        }

        if (output2 > 0) {
            cout << "output:" << output2 << endl;
        } else {
            time_rec ++;
            cout << "output: Latency..." << time_rec << " ...Cycles" << endl;
        }
    }

}