# My own setting, attach to the end of .zshrc under home folder
# Alias
alias py2="python2"
alias py3="python3"
alias py34="python3.4"
alias py35="python3.5"

# ZSH theme
ZSH_THEME="agnoster"

# Environment setting
export LOCAL_USR=$HOME/.local
export LOCAL_INCLUDE=$LOCAL_USR/include
export LOCAL_LIB=$LOCAL_USR/lib
export LOCAL_LIB64=$LOCAL_USR/lib64
export LOCAL_SHARE=$LOCAL_USR/share

# LD path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LOCAL_LIB:$LOCAL_LIB64

# Make Home and End button be available via SSH
bindkey "\033[1~" beginning-of-line
bindkey "\033[4~" end-of-line
