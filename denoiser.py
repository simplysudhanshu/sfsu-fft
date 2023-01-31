import struct

f = open("data/fft_12x12_1-3r.dat", "rb")
byte = f.read(4)
print(struct.unpack("f", byte)[0])

# for line in f.readlines():
    