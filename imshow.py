''''
Simple script to imshow the file.

$ python imshow.py x y file_name
    x = N0
    y = N1
    file_name = file to be displayed.

The file is supposed to be written by a C/C++ program in "double" datatype
'''

import struct
import sys
import numpy as np
import matplotlib.pyplot as plt

N0 = int(sys.argv[1])
N1 = int(sys.argv[2])
file_name = sys.argv[3]

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
plt.title(file_name)
plt.savefig(f"{file_name[:-3]}png")
