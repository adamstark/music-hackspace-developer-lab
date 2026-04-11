import soundfile as sf
from pylab import *

# ==============================================
# READING AUDIO FILES

#data, samplerate = sf.read("audio.wav")
#print(data.shape)
#print(samplerate)
#left_channel = data[:, 0]

# ==============================================
# PHASE SIGNAL (used later in waveform generation)
phase = np.arange(0, 10 * np.pi, 0.01)

# ==============================================
# SAWTOOTH WAVE

sawtooth = np.zeros_like(phase)

sawtooth = np.sin(phase)
sawtooth += np.sin(2 * phase) / 2
sawtooth += np.sin(3 * phase) / 3
sawtooth += np.sin(4 * phase) / 4
sawtooth += np.sin(5 * phase) / 5
sawtooth += np.sin(6 * phase) / 6
sawtooth += np.sin(7 * phase) / 7
sawtooth += np.sin(8 * phase) / 8
sawtooth += np.sin(9 * phase) / 9
#plot(sawtooth)
#show()


# ==============================================
# SQUARE WAVE

square = np.zeros_like(phase)

square = np.sin(phase)
square += np.sin(3 * phase) / 3
square += np.sin(5 * phase) / 5
square += np.sin(7 * phase) / 7
square += np.sin(9 * phase) / 9
square += np.sin(11 * phase) / 11
plot(square)
show()

# ==============================================
# "PERFECT" SQUARE WAVE (naive approach)

# sine = np.sin(phase)
# perfect_square = np.sign(sine)
# plot(perfect_square)
# show()


# ==============================================
## LINKS...

# ALIASING  

# Wheel Aliasing effect
# https://www.researchgate.net/figure/Aliasing-wheel-Example-of-an-aliasing-effect-in-the-clockwise-rotation-of-a-wheel-The_fig1_332756188

# Audio Aliasing
# https://blog.prosig.com/wp-content/uploads/2010/06/fig2-1024x440.jpg
