# My own setting, attach to the end of .zshrc under home folder
# Alias
alias py="python"
alias py2="python2"
alias py3="python3"
alias py34="python3.4"
alias py35="python3.5"

# ZSH theme
ZSH_THEME="agnoster"

# Environment setting
export LOCAL_USR=$HOME/.local
export LOCAL_BIN=$LOCAL_USR/bin
export LOCAL_INCLUDE=$LOCAL_USR/include
export LOCAL_LIB=$LOCAL_USR/lib
export LOCAL_LIB64=$LOCAL_USR/lib64
export LOCAL_SHARE=$LOCAL_USR/share

# Bin, include and LD path
export PATH=$LOCAL_BIN:$PATH
export CPATH=$PATH:$LOCAL_INCLUDE
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LOCAL_LIB:$LOCAL_LIB64

# Software-related variables
export CONDA_ROOT=$LOCAL_USR/anaconda3
export CONDA_BIN=$CONDA_ROOT/bin
export CONDA_INCLUDE=$CONDA_ROOT/include
export CONDA_LIB=$CONDA_ROOT/lib

# Make Home and End button be available via SSH
bindkey "\033[1~" beginning-of-line
bindkey "\033[4~" end-of-line
