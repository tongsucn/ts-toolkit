#!/usr/bin/env sh

# Install Python 3
cd Python-3.5.2/
./configure --prefix=$LOCAL_USR --exec_prefix=$LOCAL_USR
make -j4
make install
cd ~

python3 -m pip install --upgrade pip
python3 -m pip install numpy pandas scikit-image scikit-learn ipython jupyter
