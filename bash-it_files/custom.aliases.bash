alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias ll='ls -alF'
alias lt='ls -t'
alias llt='ls -lt'
alias llh='ls -alFh'
alias lth='ls -lth'
alias lssort='ls --sort=size -lh'
alias la='ls -A'
alias l='ls -CF'
alias cheat='vi /home/bks6kor/coder/cmd_cheatsheet.txt'
alias ssid_print='sudo grep -r '^psk=' /etc/NetworkManager/system-connections/'
alias connected_ssid='iwgetid -r'
alias wifi_reboot='sudo systemctl restart network-manager.service'
alias connections='sudo nmap -sP --disable-arp-ping'
alias rsync='rsync -ah --info=progress2 --partial'
alias diskspace='du -h --max-depth=1'
alias find_file='find . -name'
alias ....='cd ../../..'
alias install='sudo apt-get install -y'
alias search='sudo apt-cache search'
alias remove='sudo apt-get remove'
alias update='sudo apt-get update'
alias build='sudo echo "Build" && time make -j8 && sudo make modules_install && sudo make install && echo "Done"'

