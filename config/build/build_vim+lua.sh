#!/usr/bin/env sh

# Install Lua
cd lua-5.3.3/
make linux
make install INSTALL_TOP=$LOCAL_USR

# Install LuaJit
cd ../../LuaJIT-2.0.4
make -j4
make install PREFIX=$LOCAL_USR

# Install Vim with +lua
cd ../vim
./configure --prefix=$LOCAL_USR - --with-features=huge --with-luajit \
    --enable-luainterp=yes --enable-fail-if-missing \
    --with-local-dir=$LOCAL_USR --with-lua-prefix=$LOCAL_USR
make -j4
make install

# Set .vim directory
cd $LCS
mkdir .vim
cd ~
ln -s $LCS/.vim .vim

# Install spf13
curl https://j.mp/spf13-vim3 -L > spf13-vim.sh && sh spf13-vim.sh
