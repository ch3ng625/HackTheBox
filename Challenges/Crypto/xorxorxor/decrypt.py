#  13 4a f6 e1 29 7b c4 a9 6f 6a 87 fe 04 66 84 e8 04 70 84 ee 04 6d 84 c5 28 2d d7 ef 29 2d c9
#  H  T  B  {                                                                                 }
#  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2

encrypted = [0x13, 0x4a, 0xf6, 0xe1, 0x29, 0x7b, 0xc4, 0xa9, 0x6f, 0x6a, 0x87, 0xfe, 0x04, 0x66, 0x84, 0xe8, 0x04, 0x70, 0x84, 0xee, 0x04, 0x6d, 0x84, 0xc5, 0x28, 0x2d, 0xd7, 0xef, 0x29, 0x2d, 0xc9]

key = [0, 0, 0, 0]
key[0] = encrypted[0] ^ ord('H')
key[1] = encrypted[1] ^ ord('T')
key[2] = encrypted[2] ^ ord('B')
key[3] = encrypted[3] ^ ord('{')

for i in range(len(encrypted)):
    o = key[i%4] ^ encrypted[i]
    print(chr(o), end='')