# My own setting, attach to the end of .zshrc under home folder
# Alias
# Python alias
alias py="python"
alias py2="python2"
alias py3="python3"

# Git alias
function gita () {
    git add $*
    git status
}
alias gitas="git add -A; git status"
alias gitc="git commit -m"
alias gitp="git push"
alias gitr="git reset HEAD"
alias gits="git status"

# ZSH theme
ZSH_THEME="agnoster"

# Environment setting
# Local USR
export LOCAL_USR=$HOME/.local
export LOCAL_BIN=$LOCAL_USR/bin
export LOCAL_INCLUDE=$LOCAL_USR/include
export LOCAL_LIB=$LOCAL_USR/lib
export LOCAL_LIB64=$LOCAL_USR/lib64
export LOCAL_SHARE=$LOCAL_USR/share

# Software-related variables
export CONDA_ROOT=$LOCAL_USR/anaconda3
export CONDA_BIN=$CONDA_ROOT/bin
export CONDA_INCLUDE=$CONDA_ROOT/include
export CONDA_LIB=$CONDA_ROOT/lib

# Bin, include and LD path
export PATH=$CONDA_BIN:$LOCAL_BIN:$PATH
export CPATH=$CPATH:$LOCAL_INCLUDE
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LOCAL_LIB:$LOCAL_LIB64

# Make Home and End button be available via SSH
bindkey "\033[1~" beginning-of-line
bindkey "\033[4~" end-of-line
