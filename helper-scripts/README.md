# Scripts and Stuff
[Link to all of my gists](https://gist.github.com/b-ak)

### What the scripts do

1. cscope-setup.sh
	Sets up cscope with vim. Navigate source code using shortcuts provided    
	in cscope_maps.vim.

	##### How-To
	 * Copy the script to your source code directory and execute it   
	 * Run `source ~/.bashrc`   
	 * Try browsing source code    

2. `kernel-cleanup.sh`    
	Remove old installed kernels on ubuntu    
	Usage: `./kernel-cleanup.sh <kernel-version-to-remove>`    

3. `rpi3-kernel-builder.sh`    
	Build and Flash Linux kernel onto a SD Card    
	Usage: `./rpi3-kernel-builder.sh </dev/{sdX | mmcblkX}> <Kernel-Root-Directory>`
