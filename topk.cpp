#include <iostream>
#include <queue>
#include <deque>

using namespace std;

// K = 2^M
#define M 2
#define K (1 << M)

int main () {

    // Step 1
    int r[M] = {0};
    queue<int> A[M], B[M];
    int A_pop_count[M] = {0};
    // Step 2
    int sort_r = 0;
    deque<int> sort_A, sort_B, sort_C;

    size_t time_rec = 0;

    while (1) {

        int input;
        int output[M];
        int res = -1;
        cin >> input;
        
        /*  Step 1 : (2^m)-Sorter Series
            pair: <X_2i, X_2i+1>
            X_2i     ->    [ A ]
            X_2i+1   ->    [ B ]
        */

        for (int m = 0; m < M; m++) {
            output[m] = -1;
            if (m == 0 || output[m-1] >= 0) {
                int k = (1 << m);
                if (r[m] > k) {
                    if (A[m].empty()) {
                        output[m] = B[m].front();
                        B[m].pop();
                    } else if (B[m].empty()) {
                        output[m] = A[m].front();
                        A[m].pop();
                        A_pop_count[m] += 1;
                    } else if (A[m].front() < B[m].front() && A_pop_count[m] < k) {
                        output[m] = A[m].front();
                        A[m].pop();
                        A_pop_count[m] += 1;
                    } else {
                        output[m] = B[m].front();
                        B[m].pop();
                    }
                }                                       
                if (r[m] % (2 * k) < k) {
                    if (m == 0) {
                        A[m].push(input);
                    } else {
                        A[m].push(output[m-1]);
                    }
                } else {
                    if (m == 0) {
                        B[m].push(input);
                    } else {
                        B[m].push(output[m-1]);
                    }
                }
                if (r[m] - k > 0 && ((r[m] - k) % (2 * k) == 0)) {
                    A_pop_count[m] = 0;
                }

                r[m] += 1;
            }
        }

        /*
            Step 2 : TopK-Merger 
                    [   A   ] -> store Top K of X_0 ~ X_(2n+1)k
                    [   B   ] -> store Top K of X_0 ~ X_(2n+2)k
            X_i   ->    [ C ] -> buffer input
            <X_ik, X_ik+1, X_ik+2, ... , X_(i+1)k-1> is sorted by Step 1
        */

        int k = K;
        if (output[M-1] >= 0) {
            if (sort_r > 0) {
                if ((sort_r - 1) % (2 * k) < k) {
                    if (sort_r - 1 < k) {
                        res = sort_C.front();
                        sort_A.push_back(res);
                        sort_C.pop_front();
                    } else {
                        if (sort_B.front() < sort_C.front()) {
                            res = sort_B.front();
                            sort_A.push_back(res);
                            sort_B.pop_front();
                        } else {
                            res = sort_C.front();
                            sort_A.push_back(res);
                            sort_C.pop_front();
                            sort_B.pop_back();
                        }
                        if (sort_r % k == 0) {
                            sort_C.clear();
                        }
                    }
                } else {
                    if (sort_A.front() < sort_C.front()) {
                        res = sort_A.front();
                        sort_B.push_back(res);
                        sort_A.pop_front();
                    } else {
                        res = sort_C.front();
                        sort_B.push_back(res);
                        sort_C.pop_front();
                        sort_A.pop_back();
                    }
                    if (sort_r % k == 0) {
                        sort_C.clear();
                    } 
                }
            }

            sort_C.push_back(output[M-1]);
            sort_r += 1;
            
        }

        if (res >= 0) {
            cout << "output: " << res << endl;
        } else {
            time_rec ++;
            cout << "Latency..." << time_rec << " ...Cycles" << endl;
        }

    }

}