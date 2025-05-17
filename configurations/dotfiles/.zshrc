PS1='%F{#98c379}%~ ➤%f '

alias tinytim='telnet yay.tim.org 5440'
alias n='nvim'
alias ll='ls -al --color'
alias ldir='ls -al | egrep -v " \.$| \..$| \.DS_Store$| \.Trash$"'
alias o='open .'
alias gd='cd ~/p/macOS-install/configurations/dotfiles'
alias ez='nvim ~/p/macOS-install/configurations/dotfiles/.zshrc'
alias ev='nvim ~/p/macOS-install/configurations/dotfiles/.config/nvim/init.lua'
alias eg='nvim ~/p/macOS-install/configurations/dotfiles/.gitconfig'

path+=('/Users/pel/bin')
path+=('/Applications/Visual Studio Code.app/Contents/Resources/app/bin')
export PATH

export VISUAL=/usr/local/bin/nvim
export EDITOR=/usr/bin/vi

[ -f "/Users/pel/.ghcup/env" ] && . "/Users/pel/.ghcup/env" # ghcup-env
