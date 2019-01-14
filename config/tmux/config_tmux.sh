#!/bin/bash

# Install tmux configuration.
git clone --recursive https://github.com/tony/tmux-config.git ~/.tmux
ln -s ~/.tmux/.tmux.conf ~/.tmux.conf
