#!/bin/bash

# Install tmux configuration.
git clone --recursive https://github.com/gpakosz/.tmux.git ~/.tmux
cp ~/.tmux/.tmux.conf.local ~/.tmux.conf.local
ln -s ~/.tmux/.tmux.conf ~/.tmux.conf
