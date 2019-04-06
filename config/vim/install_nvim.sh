#!/bin/bash

set -e

VER=v0.3.4
NVIM_URL=https://github.com/neovim/neovim/releases/download/$VER/nvim.appimage
INSTALL_TARGET=$LOCAL_BIN/nvim
DIR_CURR=`dirname $0`
NVIM_CFG=$HOME/.config/nvim
NVIM_CACHE=$NVIM_CFG/cache
NVIM_BUNDLE=$NVIM_CFG/bundle
NVIM_COLORS=$NVIM_CFG/colors

# Install dependencies.
sudo apt update && sudo apt upgrade
sudo apt install python-dev python3-dev ruby-dev lua5.1 liblua5.1-dev luajit git

# Download latest NeoVim.
wget $NVIM_URL -O $INSTALL_TARGET

# Install configuration.
mkdir -p $NVIM_CACHE/backup $NVIM_CACHE/swap $NVIM_CACHE/undo $NVIM_BUNDLE \
    $NVIM_CACHE/views
cp $DIR_CURR/init.vim $NVIM_CFG

# Install plugins and color theme.
git clone https://github.com/VundleVim/Vundle.vim.git $NVIM_BUNDLE/Vundle.vim
vim -u "$NVIM_CFG/init.vim" \
    "+set nomore" \
    "+PluginInstall" \
    "+qall"
cp -fr $NVIM_BUNDLE/vim-colors-solarized/colors $NVIM_COLORS

# Install YouCompleteMe
cd $NVIM_BUNDLE/YouCompleteMe
python install.py
cd -
