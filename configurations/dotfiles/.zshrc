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
export PATH

export VISUAL=/usr/local/bin/nvim
export EDITOR=/usr/bin/vi

cat<<'EOF'

          \_,     _ _     \.=
            \\   /,~,"\  //      _ __        !!!,,,        _ _
     ___     \\ /|o_o|( //      /.-. |      !!'''!!!     o'_"_'o
    ;---,\    :\)\'=/ /'/      ||o_o||     !!!a,a!!!     /|o_m||
    )a,a)|     \(-._.-\'       |,\= ||      !!.0.|!!    |  \='/|
   _| =/ \_    '\  Y  /       .--' '-.  (^( .-' '-. \~} / /'_/(-._
  ( J\ \/| )     | :  |      / .--Y-.\\  \\/ .-,-. \//  \|(  |/ '.\
   \\==== //    _/ :  (_    ( /\   -/ /   \_/\----|\/    ) \_'    \\
    \\==// \    \'.__.'/     \\|   \8"        \ , (          )     \;=
     || || /     |'-,-'|      9/    )          )---\         |____|\)
    /|/ /)|      \  | /       /_____/         /  |  )         \_||_/
    | | | |       | / )       ) / \ (        /   \  |         | )| )
    | | | |       |/\/        //   \|        |  / \  \        |/ |/
    |-| |-|       /|/|       |/    |\        |__|  \__|     _/ |/ |
   '-' '-'       [_[_/      /|     '='       /:(    ):\    (_,(__,]
                            '=               '-'    '-'
  "Sporty"      "Ginger"       "Posh"         "Scary"        "Baby"

EOF
