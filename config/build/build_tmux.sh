#!/usr/bin/env sh

# Install libevent
cd libevent-2.0.22-stable/
./configure --prefix=$LOCAL_USR
make -j4
make install

# Install tmux
cd ../tmux/
./configure --prefix=$LOCAL_USR CFLAGS="-I$LOCAL_INCLUDE" LDFLAGS="-L$LOCAL_LIB"
make -j4
make install
