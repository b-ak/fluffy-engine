#!/bin/bash

function usage(){
	echo "Example Usage: $0 abcd"
	exit 1
}

if [ -z "$1" ]; then
	echo "Mention NTID or If no NTID type 0"
	usage
	exit 1
fi

SUBLIME=sublime_text_3_build_3211_x64.tar.bz2
cd ~/Downloads

if [ ! -f "$SUBLIME" ]; then
	echo "--------------------------------------------------------------------"
	echo "Getting sublime text"
	echo "--------------------------------------------------------------------"
	wget https://download.sublimetext.com/$SUBLIME
else
	echo "Found Sublime text Build Version: $SUBLIME"
fi

DIR="sublime_text_3"
if [ ! -d "$DIR" ]; then
	tar -xvjf $SUBLIME 
fi

if [ ! -d "/opt/sublime_text" ]; then
	echo "Pushing it to /opt"
	mv sublime_text_3 sublime_text
	sudo mv sublime_text /opt
	cd /opt
else
	echo "Already moved to /opt/sublime_text"
fi

if [ "$1" == "0" ]; then
	echo "Fixing permissions on a Local host"
	sudo chown -R $'whoami':$'whoami' sublime_text/
else
	echo "Fixing LDAP permissions"
	sudo chown -R $1:users sublime_text/
fi

FILE=/usr/bin/sublime
OSTR="Icon=sublime-text"
NSTR="Icon=/opt/sublime_text/Icon/256x256/sublime-text.png"
if [ -f "$FILE" ]; then
	echo "Removing Old Links"
	sudo rm /usr/bin/sublime
	rm ~/.local/share/applications/sublime_text.desktop
else
	echo "Pushing new files to .local directories" 
	sudo ln -s /opt/sublime_text/sublime_text /usr/bin/sublime
	cp /opt/sublime_text/sublime_text.desktop ~/.local/share/applications/
	sed -i "s~$OSTR~$NSTR~" ~/.local/share/applications/sublime_text.desktop
	chmod +x ~/.local/share/applications/sublime_text.desktop
fi


