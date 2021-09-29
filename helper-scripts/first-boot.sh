#!/bin/bash


wget https://raw.githubusercontent.com/<repo-name>/master/sidekick/cheatsheets/vimrc -O ~/.vimrc

# Pull Zsh
echo "--------------------------------------------------------------------"
echo "Pull sublime text ?"
echo "--------------------------------------------------------------------"
select yn in "Yes" "No"; do
        case $yn in
        Yes ) 		echo "Pulling Sublime text"
			cd ~/Downloads
			wget https://download.sublimetext.com/sublime_text_3_build_3176_x64.tar.bz2
			tar -xvjf sublime_text_3_build_3176_x64.tar.bz2
			mv sublime_text_3 sublime_text
			sudo mv sublime_text /opt
			cd /opt
			sudo chown -R b-ak:b-ak sublime_text/
			sudo ln -s /opt/sublime_text/sublime_text /usr/bin/sublime
			cp /opt/sublime_text/sublime_text.desktop ~/.local/share/applications/
			cp /opt/sublime_text/Icon/256x256/sublime-text.png ~/.local/share/applications/
			chmod +x ~/.local/share/applications/sublime_text.desktop
			break;;
		No  )	break;;
	esac
done

sudo apt install -y vim git meld gnome-tweak-tool nmap net-tools make gparted synaptic gcc libncurses5-dev libncurses5 libncurses5 minicom cscope

# Stop screen rotation in Budgie
echo "--------------------------------------------------------------------"
echo "Is this Ubuntu Budgie ?"
echo "--------------------------------------------------------------------"
select yn in "Yes" "No"; do
	case $yn in
		Yes ) gsettings set org.gnome.settings-daemon.peripherals.touchscreen orientation-lock true; break;;
		No  ) break;;
	esac
done

# Pull Raspberry Pi Sources
echo "--------------------------------------------------------------------"
echo "Pull Raspberry Pi Kernel and Tools ?"
echo "--------------------------------------------------------------------"
select yn in "Yes" "No"; do
	case $yn in
		Yes )	mkdir ~/Coder/raspberrypi;
			cd ~/Coder/raspberrypi;
			git clone https://github.com/raspberrypi/tools;
			git clone --depth=1 https://github.com/raspberrypi/linux;
			break;;
		No  ) break;;
	esac
done

# Pull Zsh
echo "--------------------------------------------------------------------"
echo "Pull zsh sources and dependancies ?"
echo "--------------------------------------------------------------------"
select yn in "Yes" "No"; do
        case $yn in
        Yes )   echo "Pulling oh-my-zsh";
			sudo apt -y install zsh
			sudo apt -y install fonts-powerline
			sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
			wget https://raw.githubusercontent.com/<repo-name>/sidekick/cheatsheets/zshrc -O ~/.zshrc
			wget https://raw.githubusercontent.com/<repo-name>/sidekick/cheatsheets/aliases.zsh -O ~/.oh-my-zsh/custom/aliases.zsh
			cd ~/.oh-my-zsh/custom/plugins
			git clone https://github.com/zsh-users/zsh-autosuggestions
			break;;
		No  )	break;;
	esac
done


# Pull Source-Code-Pro Fonts
echo "--------------------------------------------------------------------"
echo "Pull source-code-pro fonts ?"
echo "--------------------------------------------------------------------"
select yn in "Yes" "No"; do
        case $yn in
		Yes )	[ -d /usr/share/fonts/opentype ] || sudo mkdir /usr/share/fonts/opentype
			sudo git clone --depth 1 --branch release https://github.com/adobe-fonts/source-code-pro.git /usr/share/fonts/opentype/scp
			sudo fc-cache -f -v
			break;;
		No  )	break;;
	esac
done
