PS1='%F{#8fb573}%~ ➤%f '

alias ll='ls -al --color'
alias ldir='ls -al | egrep -v " \.$| \..$| \.DS_Store$| \.Trash$"'
alias o='open .'
alias gd='cd ~/p/macOS-install/configurations/dotfiles'
alias ez='nvim ~/p/macOS-install/configurations/dotfiles/.zshrc'
alias el='nvim ~/p/macOS-install/configurations/dotfiles/.config/nvim/init.lua'
alias eg='nvim ~/p/macOS-install/configurations/dotfiles/.gitconfig'

path+=('/Users/pel/bin')
export PATH
