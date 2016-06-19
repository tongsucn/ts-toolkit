Installing the TensorFlow for Python 3.5.1 on the RWTH HPC cluster (linuxnvc01):

## Prerequests

### Official Dependencies

Some dependencies like CUDA, cuDNN and bazel are specified on the official
[document](https://www.tensorflow.org/versions/master/get_started/index.html).

To be noticed is that, on the cluster, I used the pre-built cuDNN library
(include the `.so`, `.a` and `.h` files), copied them to a suitable directory,
set the environment vairables.

### Other Dependencies

Firstly, load modules using commands `module load cuda python/3.5.1`. Then
execute `printenv | grep CUDA` and `where python3` to find the loaded CUDA path
and the loaded Python executable file respectively. To make sure that it
installed `numpy` and `pip` correctly, try importing them in the interactive
mode. To build the TensorFlow pip install package later, the wheel is necessary.
Run `python3 -m pip install --user wheel`.

## Something

When executing `./configure`, it is necessary that type in the path of required
library carefully. For example, I loaded the Python 3.5.1 rather the default
loaded Python 3.4.3.

The data of this cluster is stored on NFS, so some operations are quite limited.
For example, writing to the `/tmp` directory. In principle the temporary files
should be stored in the user's temporary folder under the `/tmp`, i.e. for me is
`/tmp/ts12345`. Storing data or creating directory directory `/tmp` is allowed,
but sometimes it is unstable. The build script
`tensorflow/contrib/session_bundle/example/BUILD` calls a Python script, which
uses `/tmp/blahblah` to store temporary data. The problem was, after generating
these data and before their using, they could be deleted, and the later steps
would not be executed. After modifying them into my home directory, everything
goes well.
