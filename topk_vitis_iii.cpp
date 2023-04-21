#include <iostream>

using namespace std;

// K = 2^M
#define M 3
#define K (1 << M)



int main() {

    int round = 20;
    int heap[K] = {0};

    while (round--) {
        
        int input;
        
        cin >> input;

        int index = 0;

        if (heap[index] < input) {
            heap[index] = input;
            for (int i = 0; i < M - 1; i++) {
                int min_index = index;
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                if (heap[left] < heap[index]) { 
                    min_index = left;
                }
                if (heap[right] < heap[index]) {
                    min_index = right;
                }
                if (index != min_index) {
                    int tmp = heap[index];
                    heap[index] = heap[min_index];
                    heap[min_index] = tmp;
                    index = min_index;
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