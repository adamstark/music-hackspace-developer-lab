import numpy as np
from pylab import *

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
# NOTE: Uncomment the sections below to run them

#===================================================================
# 1. Delaying a sine wave produces constructive and destructive interference, 
# which boosts some frequencies and cancels out others, creating a comb filter effect.
# sample_rate = 44100
# frame_size = 2048
# frequency = 100
# sine_wave = create_sine_wave(frequency, sample_rate, frame_size)

# delayed_sine_wave = np.zeros_like(sine_wave)

# # play with this delay in samples number below 
# delay_samples = 220 # half the cycle length, which is 220 samples for a 100 Hz sine wave at a 44100 Hz sample rate

# for i in range(delay_samples, len(sine_wave)):
#     delay_index = i - delay_samples
#     if delay_index >= 0:
#       delayed_sine_wave[i] = sine_wave[delay_index]
#     else:
#       delayed_sine_wave[i] = 0

# summed_wave = sine_wave + delayed_sine_wave

# fig, (ax1, ax2) = subplots(2, 1)
# ax1.set_title('Original and Delayed Sine Waves')
# ax1.plot(sine_wave)
# ax1.plot(delayed_sine_wave)
# ax2.set_title('Summed Sine Waves')
# ax2.plot(summed_wave)
# ax2.set_ylim(-2, 2)
# show()

#===================================================================
# 2. 1st order FIR low-pass filter

# def firstOrderFIRFilter(x, a0, a1):
#     y = np.zeros_like(x)
#     for i in range(0, len(x)):
#         y[i] = a0 * x[i] + a1 * x[i - 1]
#     return y

# x = np.zeros(16)
# x[0] = 1.0
# y = np.zeros_like(x)

# y = firstOrderFIRFilter(x, 0.5, 0.5)

# # Uncomment below to plot the impulse response of the filter
# #stem(y)
# #show()

# # plot the frequency response of the filter
# calculate_fft_and_plot(y, 44100)

#===================================================================
# 3. 1st order IIR low-pass filter
# x = np.zeros(16)
# x[0] = 1.0
# y = np.zeros_like(x)
# for i in range(0, len(x)):
#     y[i] = 0.5 * x[i] + 0.5 * y[i - 1]

# # Uncomment below to plot the impulse response of the filter
# # Play with the second coefficient (0.5 * y[i - 1]) to see how it affects the filter's response
# # What happens when it gets larger than 1? 
# suptitle('Impulse Response of 1st Order IIR Low-Pass Filter')
# stem(y)
# show()

# # plot the frequency response of the filter
# calculate_fft_and_plot(y, 44100)

#===================================================================
# 2nd order bi-quad low-pass filter
# bi-quad means that the filter has two poles and two zeros, which allows for a steeper roll-off and more control over the filter's characteristics compared to a first-order filter.

# def secondOrderIIRFilter(x, a0, a1, a2, b1, b2):
#     y = np.zeros_like(x)
#     for i in range(0, len(x)):
#         y[i] = a0 * x[i] + a1 * x[i - 1] + a2 * x[i - 2] - b1 * y[i - 1] - b2 * y[i - 2]
#     return y

# x = np.zeros(44100)
# x[0] = 1.0

# # simple example coefficients
# #y = secondOrderIIRFilter(x, 0.25, 0.5, 0.25, -0.5, 0.25)

# # JUCE-calculated coefficients for low-pass filter with cutoff frequency of 3000Hz 
# y = secondOrderIIRFilter(x, 0.034786, 0.0695721, 0.034786, -1.40751, 0.54665)

# # plot the frequency response of the filter
# calculate_fft_and_plot(y, 44100)