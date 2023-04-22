## Introduction of TopK-sorter & K-merger/2

#### TopK-sorter

* A pipelined top4-sorter example which may be used in streaming transmission.

* Based on this simple example, A pipelined topK-sorter is implemented.

* Latency of $K=2^{M}$:
  * a single $2^m$-merger: $2^{m-1}+1$ cycles;
  * merger series: $\sum_{m=1\sim M} 2^{m-1}+1=2^M-1+M$ cycles;
  * topK-merger: $1$ cycle;
  
  So the latency of A pipelined topK-sorter is $K+\log_2 K$ cycles.
  
* In vitis hls, C++ STL is somehow limited due to the usage of pointer, so a topk-sorter based on array-implemented-deque is implemented.

#### K-merger/2

* Identifier : $m = \log_2 k$
* Cycles started from cycle 0
* The first output produced after $2^{m+1}-1+(m+1) = 2^{m+1}+m$ cycle
* So the first input comes in $2^m+m-1$ cycle
* The total length including bubbles : $N+2^{m+1}+m$ cycles
* So no input happends on $N+2^{m}+m-1$ cycle

## Introduction of TopK Heap

*TODO*

## Reference

[Naoyuki Matsumoto, Koji Nakano, and Yasuaki Ito. Optimal parallel hardware k-sorter and top k-sorter, with fpga implementations. In *2015 14th International Symposium on Parallel and Distributed Computing*, 2015.](https://ieeexplore.ieee.org/document/7165140)

