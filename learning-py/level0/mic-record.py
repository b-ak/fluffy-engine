"""
Record Microphone using pulse audio and save to mp3
"""
import subprocess
import sys
import os
import re

save_path = os.environ["HOME"]
save_path = save_path + "/Music"
print (save_path)

mp3file = "rec.mp3"
mp3file = save_path + "/" + mp3file
# Update the file save path
print ("File saved at: %s" % mp3file)
print ("Saving file to " + mp3file)

# Form the command to record from the speakers
# Find Pulse Audio's monitor stream
cmd_find_dev = "pacmd list-sources | grep -e 'alsa_input' | awk '{print $2}' | sed 's/[<>]//g'"
p = subprocess.Popen(cmd_find_dev, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
(output, err) = p.communicate(timeout=6000) #timeout parameter is introduced in python 3
encoding = 'utf-8'
output = str(output,encoding)
alsa_stream = output.strip('\n')
print ("Alsa Monitor stream found at %s" % alsa_stream)
# Escape any special characters
# mp3file = re.escape(mp3file)
# print ("Escaping special characters %s" % mp3file)
cmd_rec = "parec -d "
# try sox sox -t raw -r 44k -sLb 16 -c 2 - wavefilename
cmd_lame = " | lame -r -q 3 --lowpass 17 --abr 192  - " + mp3file
cmd_rec = cmd_rec + alsa_stream + cmd_lame
print ("Recording...\n %s" % cmd_rec)
# Start recording
os.system(cmd_rec)

print ("Stop")
print("Recording Stopped")
subprocess.call(["pkill", "parec"])

