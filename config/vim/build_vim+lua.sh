#!/bin/bash

INSTALL_PREFIX=$HOME/.local
NAME_VIM=vim.tar.gz
VERSION_VIM=8.1.0744
CONFIG_PYTHON_2=/usr/lib/python2.7/config-x86_64-linux-gnu
CONFIG_PYTHON_3=/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu

set -e

# Install dependencies.
sudo apt install build-essential cmake libncurses5-dev python-dev python3-dev \
    ruby-dev lua5.1 liblua5.1-dev luajit libluajit-5.1-dev libperl-dev git

# Install Vim with Python and Lua
wget https://github.com/vim/vim/archive/v$VERSION_VIM.tar.gz -O $NAME_VIM
tar -xf $NAME_VIM
cd vim-$VERSION_VIM
./configure --prefix=$INSTALL_PREFIX \
    --enable-multibyte \
    --enable-rubyinterp=yes \
    --enable-pythoninterp=yes \
    --with-python-config-dir=$CONFIG_PYTHON_2 \
    --enable-python3interp=yes \
    --with-python3-config-dir=$CONFIG_PYTHON_3 \
    --enable-perlinterp=yes \
    --enable-luainterp=yes \
    --enable-cscope \
    --with-luajit \
    --enable-fail-if-missing
make -j4
make install
cd -
rm -fr vim-$VERSION_VIM $NAME_VIM

# Override vimrc
mkdir -p $HOME/.backup_vim
mv $HOME/.vim* $HOME/.backup_vim
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
cp ./.vimrc $HOME

# Install plugins and color theme.
vim -u "$HOME/.vimrc" \
    "+set nomore" \
    "+PluginInstall" \
    "+qall"
cp -r $HOME/.vim/bundle/vim-colors-solarized/colors $HOME/.vim

# Install YouCompleteMe
cd $HOME/.vim/bundle/YouCompleteMe
python install.py
cd -
