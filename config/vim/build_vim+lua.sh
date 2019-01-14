#!/bin/bash

INSTALL_PREFIX=$HOME/.local
NAME_LUA=lua.tar.gz
VERSION_LUA=5.3.5
NAME_LUAJIT=luajit.tar.gz
VERSION_LUAJIT=2.0.5
NAME_VIM=vim.tar.gz
VERSION_VIM=8.1.0744

set -e

# Install Lua
wget https://www.lua.org/ftp/lua-$VERSION_LUA.tar.gz -O $NAME_LUA
tar -xf $NAME_LUA
cd lua-$VERSION_LUA
make linux
make install INSTALL_TOP=$INSTALL_PREFIX
cd -
rm -fr lua-$VERSION_LUA $NAME_LUA

# Install LuaJit
wget http://luajit.org/download/LuaJIT-$VERSION_LUAJIT.tar.gz -O $NAME_LUAJIT
tar -xf $NAME_LUAJIT
cd LuaJIT-$VERSION_LUAJIT
make -j4
make install PREFIX=$INSTALL_PREFIX
cd -
rm -fr LuaJIT-$VERSION_LUAJIT $NAME_LUAJIT

# Install Vim with +lua
wget https://github.com/vim/vim/archive/v$VERSION_VIM.tar.gz -O $NAME_VIM
tar -xf $NAME_VIM
cd vim-$VERSION_VIM
./configure --prefix=$INSTALL_PREFIX --with-features=huge --with-luajit \
    --enable-luainterp=yes --enable-fail-if-missing \
    --with-local-dir=$INSTALL_PREFIX --with-lua-prefix=$INSTALL_PREFIX
make -j4
make install
cd -
rm -fr vim-$VERSION_VIM $NAME_VIM

# Override vimrc
mkdir -p $HOME/.backup_vim
mv $HOME/.vim* $HOME/.backup_vim
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
cp ./.vimrc $HOME
vim -u "$HOME/.vimrc" \
    "+set nomore" \
    "+PluginInstall" \
    "+qall"
cp -r $HOME/.vim/bundle/vim-colors-solarized/colors $HOME/.vim
