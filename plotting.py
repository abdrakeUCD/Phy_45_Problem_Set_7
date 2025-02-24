import numpy as np
import matplotlib.pyplot as plt
import os

data = np.loadtxt("MatrixOutputFile2")
output_dir = "fft_sines_added_plots" #"fft_single_sine_plots"

real_part = data[::2]  #even is real
imag_part = data[1::2]  #odd is im

n = len(real_part)
x = np.arange(n)

#rwal plot
plt.figure(figsize=(10, 5))
plt.plot(x, real_part, label="Real Part", color="blue")
plt.xlabel("Index")
plt.ylabel("Magnitude")
plt.title("Real Part of Fourier Transform")
plt.legend()
plt.grid()
plt.savefig(os.path.join(output_dir, "real_part.png"))
plt.close()

#im plot
plt.figure(figsize=(10, 5))
plt.plot(x, imag_part, label="Imaginary Part", color="red")
plt.xlabel("Index")
plt.ylabel("Magnitude")
plt.title("Imaginary Part of Fourier Transform")
plt.legend()
plt.grid()
plt.savefig(os.path.join(output_dir, "imag_part.png"))
plt.close()

print(f"Plots saved in {output_dir}")

