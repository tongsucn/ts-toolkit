#!/bin/bash

INSTALL_PREFIX=$HOME/.local
NAME_LUA=lua.tar.gz
VERSION_LUA=5.3.5
NAME_LUAJIT=luajit.tar.gz
VERSION_LUAJIT=2.0.5

set -e

# Install Lua
wget https://www.lua.org/ftp/lua-$VERSION_LUA.tar.gz -O $NAME_LUA
tar -xf NAME_LUA
cd lua-$VERSION_LUA
make linux
make install INSTALL_TOP=$INSTALL_PREFIX
cd -
rm -fr lua-$VERSION_LUA $NAME_LUA

# Install LuaJit
wget http://luajit.org/download/LuaJIT-$VERSION_LUAJIT.tar.gz -O $NAME_LUAJIT
cd LuaJit-$VERSION_LUAJIT
make -j4
make install PREFIX=$INSTALL_PREFIX
cd -
rm -fr LuaJit-$VERSION_LUAJIT $NAME_LUAJIT

# Install Vim with +lua
git clone https://github.com/vim/vim.git
cd vim
./configure --prefix=$INSTALL_PREFIX --with-features=huge --with-luajit \
    --enable-luainterp=yes --enable-fail-if-missing \
    --with-local-dir=$INSTALL_PREFIX --with-lua-prefix=$INSTALL_PREFIX
make -j4
make install
cd -
rm -fr vim

# Override vimrc
mkdir $HOME/.backup_vim
mv $HOME/.vim* $HOME.backup_vim
cp ./.vimrc $HOME
vim -u "$HOME/.vimrc" \
    "+set nomore" \
    "+PluginInstall" \
    "+qall"
