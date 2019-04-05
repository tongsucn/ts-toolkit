export ZSH="/home/iamtongsu/.oh-my-zsh"

# My own setting, attach to the end of .zshrc under home folder
# ZSH theme
ZSH_THEME="bullet-train"

# Plugins
plugins=(
  git
)

source $ZSH/oh-my-zsh.sh

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
alias gitd="git diff"
alias gitp="git push"
alias gitr="git reset HEAD"
alias gits="git status"

# SVN alias
function svna () {
    svn add $*
    svn status
}
alias svnc="svn commit -m"
alias svnd="svn diff"
alias svnu="svn update"
alias svns="svn status"

# Source alias
alias sa="source activate"
alias sd="source deactivate"

# Vim alias
alias vim="nvim"
alias vimdiff="vim -d"

# Environment setting
# Local USR
export LOCAL_USR=$HOME/.local
export LOCAL_BIN=$LOCAL_USR/bin
export LOCAL_INCLUDE=$LOCAL_USR/include
export LOCAL_LIB=$LOCAL_USR/lib
export LOCAL_LIB64=$LOCAL_USR/lib64
export LOCAL_SHARE=$LOCAL_USR/share

# Software-related variables
export CONDA_HOME=$LOCAL_USR/miniconda3
export CONDA_BIN=$CONDA_HOME/bin

# Bin, include and LD path
export PATH=$CONDA_BIN:$LOCAL_BIN:$PATH
export CPATH=$CPATH:$LOCAL_INCLUDE
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LOCAL_LIB:$LOCAL_LIB64

# Docker configuration (WSL).
export DOCKER_HOST=localhost:2375

# Make Home and End button be available via SSH
bindkey "\033[1~" beginning-of-line
bindkey "\033[4~" end-of-line
