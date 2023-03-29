#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main () {

    int r1 = 0, r2 = 0, r3 = 0;
    queue<int> A1, B1;
    queue<int> A2, B2;
    deque<int> A3, B3, C3;
    int A1_pop_count = 0, A2_pop_count = 0;

    size_t time_rec = 0;

    while (1) {

        int input;
        int output1 = -1;
        int output2 = -1;
        int output3 = -1;
        cin >> input;
        
        /*  Step 1 : 4-Sorter
            pair: <X_2i, X_2i+1>
            X_2i     ->    [ A ]
            X_2i+1   ->    [ B ]
        */

        int k = 1;
        if (r1 > k) {
            if (A1.empty()) {
                output1 = B1.front();
                B1.pop();
            } else if (B1.empty()) {
                output1 = A1.front();
                A1.pop();
                A1_pop_count += 1;
            } else if (A1.front() < B1.front() && A1_pop_count < k) {
                output1 = A1.front();
                A1.pop();
                A1_pop_count += 1;
            } else {
                output1 = B1.front();
                B1.pop();
            }
        }
        if (r1 % (2 * k) < k) {
            A1.push(input);
        } else {
            B1.push(input);
        }
        if (r1 - k > 0 && ((r1 - k) % (2 * k) == 0)) {
            A1_pop_count = 0;
        }

        r1 += 1;

        if (output1 >= 0) {
            k = 2;
            if (r2 > k) {
                if (A2.empty()) {
                    output2 = B2.front();
                    B2.pop();
                } else if (B2.empty()) {
                    output2 = A2.front();
                    A2.pop();
                    A2_pop_count += 1;
                } else if (A2.front() < B2.front() && A2_pop_count < k) {
                    output2 = A2.front();
                    A2.pop();
                    A2_pop_count += 1;
                } else {
                    output2 = B2.front();
                    B2.pop();
                }
            }
            if (r2 % (2 * k) < k) {
                A2.push(output1);
            } else {
                B2.push(output1);
            }
            if (r2 - k > 0 && ((r2 - k) % (2 * k) == 0)) {
                A2_pop_count = 0;
            }
            r2 += 1;
        }

        /*
            Step 2 : Top4-Merger 
                    [   A   ] -> store Top K of X_0 ~ X_(2n+1)k
                    [   B   ] -> store Top K of X_0 ~ X_(2n+2)k
            X_i   ->    [ C ] -> buffer input
            <X_ik, X_ik+1, X_ik+2, ... , X_(i+1)k-1> is sorted by Step 1
        */

        k = 4;
        if (output2 >= 0) {
            if (r3 > 0) {
                cout << "r3:" << r3 << endl;
                if ((r3 - 1) % (2 * k) < k) {
                    if (r3 - 1 < k) {
                        output3 = C3.front();
                        A3.push_back(output3);
                        C3.pop_front();
                    } else {
                        if (B3.front() < C3.front()) {
                            output3 = B3.front();
                            A3.push_back(output3);
                            B3.pop_front();
                        } else {
                            output3 = C3.front();
                            A3.push_back(output3);
                            C3.pop_front();
                            B3.pop_back();
                        }
                        if (r3 % k == 0) {
                            C3.clear();
                        }
                    }
                } else {
                    if (A3.front() < C3.front()) {
                        output3 = A3.front();
                        B3.push_back(output3);
                        A3.pop_front();
                    } else {
                        output3 = C3.front();
                        B3.push_back(output3);
                        C3.pop_front();
                        A3.pop_back();
                    }
                    if (r3 % k == 0) {
                        C3.clear();
                    } 
                }
            }

            C3.push_back(output2);
            r3 += 1;
            
        }

        if (output3 >= 0) {
            cout << "output: " << output3 << endl;
        } else {
            time_rec ++;
            cout << "Latency..." << time_rec << " ...Cycles" << endl;
        }

    }

}