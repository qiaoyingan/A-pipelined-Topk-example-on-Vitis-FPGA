#include <iostream>

using namespace std;

// K = 2^M - 1
#define M                   3
#define K                   (1 << M) - 1

int main() {

    int round = 20;

    int heap[K];
    for (int i = 0; i < K; i++) {
        heap[i] = 0;
    }

    while (round--) {
        
        int input;
        
        cin >> input;

        int top_value = heap[0];
        if (top_value < input) {
            heap[0] = input;
            int index = 0;
            int index_val = input;
            for (int i = 0; i < M - 1; i++) {
                int min_index = index;
                int left = index * 2 + 1;
                int right = index * 2 + 2;

                int left_val = heap[left];
                int right_val = heap[right];
                // cout << "index" << index << " : " << index_val << endl;
                // cout << "left"  << left  << " : " << left_val << endl;
                // cout << "right" << right << " : " << right_val << endl;

                if (left_val < index_val && left_val <= right_val) { 
                    // cout << "change left child" << endl;
                    min_index = left;
                }
                else if (right_val < index_val && right_val <= left_val) {
                    // cout << "change right child" << endl;
                    min_index = right;
                }
                if (min_index == left) {
                    heap[left] = index_val;
                    heap[index] = left_val;
                    index = left;
                } else if (min_index == right) {
                    heap[right] = index_val;
                    heap[index] = right_val;
                    index = right;
                } else {
                    break;
                }
            }
        }

    }

    for (int i = 0; i < K; i++) {
        cout << heap[i] << " ";
    }
}