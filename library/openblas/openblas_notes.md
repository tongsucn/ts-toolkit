Notes for OpenBLAS

## Installation

Environment: RWTH HPC cluster (linuxnvc01), Intel(R) Xeon(R) CPU E2-2650,
CentOS 7.2.1511, gcc/5.3

Because of the version problem of the ICC on the cluster, some of the GCC
instructions cannot be recognized. To solve it, use `make CC=gcc`. After
compiling, related shared library and static library will be generated. Their
names start with `libopenblas`, just using `cp libopenblas* [DEST]` will finish
installing.

