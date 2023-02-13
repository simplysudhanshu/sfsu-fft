'''
PYTHON DENOISER SCRIPT

"Denoises" the FFT input, also performs some rudementary visualization.

$ python ./denoiser.py r_limit
    r_limit = threshold of noise filtering in terms of % of max distance from 
              center to a point in computational domain (0-1)

! Currently this code takes hardcoded input, will be replaced with SENSEI Endpoint
# Contributions:
Sudhanshu Kulkarni, E. Wes Bethel
2022
'''

import struct
import sys
import time

import numpy as np
import matplotlib.pyplot as plt

r_limit = 0.1
N0 = 12
N1 = 12

''' TESTING PURE DATA '''

file_name = "data/pure_12x12_10-50n_5r.dat"

if len(sys.argv)>1:
    N0 = sys.argv[1]
    N1 = sys.argv[2]
    r_limit = sys.argv[3]
    file_name = sys.argv[4]


# reading from file, replace with SENSEI endpoints:
input_data = []
f = open(file_name, "rb")

# parse 'double' data written by C++ into an array
i = 0
while True:
    double = f.read(8)  
    i += 1
    if not double:
        break
    input_data.append(struct.unpack("d", double)[0])

f.close()

input_data = np.asarray(input_data).reshape(N0, N1)
# print(input_data, input_data.size, input_data.shape)

# display the content
plt.figure()
plt.imshow(input_data, cmap='OrRd', origin='lower', alpha=1, aspect='auto')
plt.colorbar()
plt.title("PURE")
plt.savefig(f"{file_name[:-3]}png")


''' TESTING NOISY DATA '''

file_name = "data/noisy_12x12_10-50n_5r.dat"

if len(sys.argv)>1:
    N0 = sys.argv[1]
    N1 = sys.argv[2]
    r_limit = sys.argv[3]
    file_name = sys.argv[4]


# reading from file, replace with SENSEI endpoints:
input_data = []
f = open(file_name, "rb")

# parse 'double' data written by C++ into an array
i = 0
while True:
    double = f.read(8)  
    i += 1
    if not double:
        break
    input_data.append(struct.unpack("d", double)[0])

f.close()

input_data = np.asarray(input_data).reshape(N0, N1)
# print(input_data, input_data.size, input_data.shape)

# display the content
plt.figure()
plt.imshow(input_data, cmap='OrRd', origin='lower', alpha=1, aspect='auto')
plt.colorbar()
plt.title("NOISY")
plt.savefig(f"{file_name[:-3]}png")


file_name = "data/fft_12x12_0-3r.dat"

if len(sys.argv)>1:
    N0 = sys.argv[1]
    N1 = sys.argv[2]
    r_limit = sys.argv[3]
    file_name = sys.argv[4]


# reading from file, replace with SENSEI endpoints:
input_data = []
f = open(file_name, "rb")

# parse 'double' data written by C++ into an array
i = 0
while True:
    double = f.read(8)  
    i += 1
    if not double:
        break
    input_data.append(struct.unpack("d", double)[0])

f.close()

input_data = np.asarray(input_data).reshape(N0, N1)
# print(input_data, input_data.size, input_data.shape)

# display the content
plt.figure()
plt.imshow(input_data, cmap='OrRd', origin='lower', alpha=1, aspect='auto')
plt.colorbar()
plt.title("FFT NOISY")
plt.savefig(f"{file_name[:-3]}png")

# denoising
print(f"Denoising from: [{int(N0*r_limit)},{int(N0*(1-r_limit))}] and [{int(N1*r_limit)},{int(N1*(1-r_limit))}]")

start_time = time.perf_counter_ns()
for row_index, row in enumerate(input_data):
    for column_index, column in enumerate(row):        
        if r_limit*N0 < row_index < (1-r_limit)*N0 or r_limit*N1 < column_index < (1-r_limit)*N1:
            input_data[row_index][column_index] = 0

print(f" ____ TIMING RESULTS ____\nElapsed Denoising Time: {(time.perf_counter_ns() - start_time)/1000000} (ms)")

# display the content
plt.figure()
plt.imshow(input_data, cmap='OrRd', origin='lower', alpha=1, aspect='auto')
plt.colorbar()
plt.title("FFT DENOISED")
plt.savefig(f"{file_name[:-4]}_denoised.png")


