## Introduction

* A pipelined top4-sorter example which may be used in streaming transmission.

* Based on this simple example, A pipelined topK-sorter is implemented.

* Latency for $K=2^{M}$:

  * a single $2^m$-merger: $2^{m-1}+1$ cycles;
  * merger series: $\sum^{M}_{m=1}2^{m-1}+1=2^M-1+M$ cycles;
  * topK-merger: $1$ cycles;

  So the latency of A pipelined topK-sorter is $K+logK$ cycles.

* ~~**todo** : implement top1024-sorter for my graduate program.~~

## Reference

[Naoyuki Matsumoto, Koji Nakano, and Yasuaki Ito. Optimal parallel hardware k-sorter and top k-sorter, with fpga implementations. In *2015 14th International Symposium on Parallel and Distributed Computing*, 2015.](https://ieeexplore.ieee.org/document/7165140)
