from scipy.fftpack import fft
from pylab import *
import soundfile as sf

#===================================================================
def create_sine_wave(freq, sample_rate,  frame_size):
    t = np.linspace(0, frame_size / sample_rate, frame_size, endpoint=False)
    sine_wave = np.sin(2 * np.pi * freq * t)
    return sine_wave

#===================================================================
def plot_magnitude_and_phase(magnitude, phase, sample_rate):
  
    x = np.fft.fftfreq(len(magnitude), d=1/sample_rate)[:len(magnitude)//2]
    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(x, magnitude[:magnitude.size//2])
    ax1.set_title('Magnitude Spectrum')
    ax1.set_xlabel('Frequency (Hz)')
    ax1.set_ylabel('Magnitude')
    ax1.set_ylim(0, np.max(magnitude[:magnitude.size//2]) * 1.1)
    ax2.plot(x, phase[:phase.size//2])
    ax2.set_title('Phase Spectrum')
    ax2.set_xlabel('Frequency (Hz)')
    ax2.set_ylabel('Phase')
    ax2.set_ylim(-np.pi, np.pi)
    plt.tight_layout()
    plt.show()



#===================================================================
def calculate_fft_and_plot(signal, sample_rate):
    windowed_signal = signal * np.hanning(len(signal))
    fft_result = fft(signal)    
    magnitude_spectrum = np.abs(fft_result)
    phase_spectrum = np.angle(fft_result)
    plot_magnitude_and_phase(magnitude_spectrum, phase_spectrum, sample_rate)

#===================================================================
# setup... uncomment the sections below to run them
sample_rate = 44100
frame_size = 4096
frequency = 1000
sine_wave = create_sine_wave(frequency, sample_rate, frame_size)

#===================================================================
# 1. Plot the sine wave

#plot(sine_wave)
#show()

#===================================================================
# 2. Calculate and plot the FFT of the sine wave
#calculate_fft_and_plot(sine_wave, sample_rate)

#===================================================================
# 3. Calculate and plot the FFT of noise
#noise = np.random.normal(0, 0.5, frame_size)
#calculate_fft_and_plot(noise, sample_rate)

#===================================================================
# 4. Calculate and plot the FFT of an audio file (e.g., "audio.wav")

# data, samplerate = sf.read("audio.wav")
# left_channel = data[:, 0]

# for i in range(0, len(left_channel), frame_size):
#     frame = left_channel[i:i+frame_size]
#     if len(frame) < frame_size:
#         break
#     calculate_fft_and_plot(frame, samplerate)

#===================================================================
# 5. Calculate and plot the FFT of an impulse

# impulse = np.zeros(frame_size)
# impulse[0] = 1

# calculate_fft_and_plot(impulse, sample_rate)