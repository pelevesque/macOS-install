PS1='%F{#8fb573}%~ ➤%f '

alias n="nvim"

export NVM_DIR="$HOME/.nvm"
  [ -s "/usr/local/opt/nvm/nvm.sh" ] && \. "/usr/local/opt/nvm/nvm.sh"  # This loads nvm
  [ -s "/usr/local/opt/nvm/etc/bash_completion.d/nvm" ] && \. "/usr/local/opt/nvm/etc/bash_completion.d/nvm"  # This loads nvm bash_completion
source /Users/pel/.docker/init-zsh.sh || true # Added by Docker Desktop

path+=('/usr/local/Cellar/rakudo/2022.12/share/perl6/site/bin');
export PATH