"""
Read a wav file of multiple channels and plot it against another wav file
"""


import wave
import numpy as np
import matplotlib.pyplot as plt

chNames = ["ch-1", "ch-2", "ch-3", "ch-4", "ch-5", "ch-6", "ch-7", "ch-8", "ch-9", "ch-10"]

f = wave.open('./new-files/cap_8ch_v2.wav')
sampleRate = f.getframerate()
totalFrames = f.getnframes()
channels = f.getnchannels()

print("SR %s" %sampleRate)
print("Total Frames %s" %totalFrames)
print("Channels %s" %channels)

fig, axs = plt.subplots(channels, 1)
# make a little extra space between the subplots
fig.subplots_adjust(hspace=0.6)
fig.suptitle('Generated vs Captured Data')

data = f.readframes(-1) # -1 is read all frames, can also use totalFrames
# print(data)  # Data in Hex
print("Data is 8bits - raw data > %s" %len(data))

dataInt = np.frombuffer(data, np.int16)
print("All Samples in 16bits/sample -> {}".format(dataInt))
print("DataInt is converted to 16 bits/sample > %s" %len(dataInt))

dataNorm = dataInt / (2**15)
print("DataNorm > %s" %len(dataNorm))


dataNorm.shape = -1, channels
print("L and R Normalised in {} columns \n {}" .format(channels, dataNorm))

dataNorm = dataNorm.T
print("L and R in {} separate rows \n {}" .format(channels, dataNorm))

np.set_printoptions(threshold=np.inf)
# print(dataNorm[1])

print("total duration of file -> {}" .format(totalFrames/float(sampleRate)))
duration = 1/float(sampleRate)
print(duration)

# timeSeq = np.arange(0, totalFrames/float(sampleRate), duration)
timeSeq = np.arange(0, (totalFrames/channels))/sampleRate

print("Time Seq %s" %len(timeSeq))
print("DataNorm[0] %s" %len(dataNorm[0]))

# Get the generated wave file
g = wave.open('gen.wav')
gSR = g.getframerate()
gFrames = g.getnframes()
gChannels = g.getnchannels()

gData = g.readframes(-1)
gDataInt = np.frombuffer(gData, np.int16)
gDataNorm = gDataInt / (2**15)
gDataNorm.shape = -1, gChannels
gDataNorm = gDataNorm.T

if (len(timeSeq) != len(gDataNorm[0])):
    gDataLeft = gDataNorm[0][:len(timeSeq)]

if (len(timeSeq) != len(gDataNorm[1])):
    gDataRight = gDataNorm[1][:len(timeSeq)]

for i in range(channels):
    if (len(timeSeq) != len(dataNorm[i])):
        dataNorm[i] = dataNorm[i][:len(timeSeq)]

    if (len(timeSeq) != len(gDataNorm[i%2])):
        if (i%2 == 0):
            l1, l2 = axs[i].plot(timeSeq, dataNorm[i], timeSeq, gDataLeft)
        else:
            l1, l2 = axs[i].plot(timeSeq, dataNorm[i], timeSeq, gDataRight)
    else:
        l1, l2 = axs[i].plot(timeSeq, dataNorm[i], timeSeq, gDataNorm[i%2])

    #axs[i].plot(timeSeq, dataNorm[i], 'o-')
    axs[i].set_ylabel(chNames[i])
    # axs[i].set_xlim([0.2, 0.3])
    # axs[i].set_ylim([-0.8, 0.8])


fig.legend((l1, l2), ("Captured", 'Generated'), loc='upper right', shadow=True)


axs[channels-1].set_xlabel('Time (s)')
# plt.legend(loc='lower right')
# plt.axis([0.2, 0.4, -1, 1])

plt.show()
)
