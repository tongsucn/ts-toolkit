#!/bin/bash

# Set internal variables.
# NeoVim executable.
VER=v0.3.5
NVIM_URL=https://github.com/neovim/neovim/releases/download/$VER/nvim.appimage
INSTALL_TARGET=$LOCAL_BIN/nvim

# Installation-related directory.
DIR_CURR=$(dirname $0)
NVIM_CFG=$HOME/.config/nvim
NVIM_CACHE=$NVIM_CFG/cache
NVIM_BUNDLE=$NVIM_CFG/bundle
NVIM_COLORS=$NVIM_CFG/colors

# Install dependencies.
# Check OS version.
IS_UBUNTU=$(cat /etc/os-release | grep -i centos)
if [[ -z $IS_UBUNTU ]]; then
    sudo yum clean all && sudo yum update
    sudp yum install lua.x86_64 lua-devel luajit luajit-devel \
        python-devel python3 python3-devel ruby ruby-devel \
        python34-pip.noarch python-pip.noarch
else
    sudo apt update && sudo apt upgrade
    sudo apt install python-dev python3-dev python-pip python3-pip ruby-dev \
        lua5.1 liblua5.1-dev luajit git
fi

sudo pip2 install neovim && sudo pip3 install neovim

# Download NeoVim.
wget $NVIM_URL -O $INSTALL_TARGET
chmod +x $INSTALL_TARGET

# Setup directory and install configuration.
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
