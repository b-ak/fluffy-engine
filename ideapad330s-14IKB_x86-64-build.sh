#!/bin/bash

# Source - Teaches a deb package install too, checkout sometime
# https://wiki.ubuntu.com/KernelTeam/GitKernelBuild

# FIXME: Very hard coded at the moment. Make it generic

cd ~/coder/vanilla-linux
git tag
git checkout tags/v4.19
cp /boot/config-`uname -r` .config
make oldconfig
yes '' | make oldconfig
make clean
time make -j16 LOCALVERSION=-batman
sudo make modules_install
sudo make install
cd ~/Public
sudo sbsign --key MOK.priv --cert MOK.pem /boot/vmlinuz-4.19.0-batman --output /boot/vmlinuz-4.19.0-batman.signed
sudo mv /boot/vmlinuz-4.19.0-batman.signed /boot/vmlinuz-4.19.0-batman
sudo update-grub

