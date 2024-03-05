# hexdump
Hexdump-like function in C

Includes an example main function.

    gcc -DHEX_MAIN -o hex hex.c
    ./hex
    00000000: 00010203 04050607 08090a0b 0c0d0e0f |................|
    00000010: 10111213 14151617 18191a1b 1c1d1e1f |................|
    00000020: 20212223 24252627 28292a2b 2c2d2e2f | !"#$%&'()*+,-./|
    00000030: 30313233 34353637 38393a3b 3c3d3e3f |0123456789:;<=>?|
    00000040: 40414243 44454647 48494a4b 4c4d4e4f |@ABCDEFGHIJKLMNO|
    00000050: 50515253 54555657 58595a5b 5c5d5e5f |PQRSTUVWXYZ[\]^_|
    00000060: 60616263 64656667 68696a6b 6c6d6e6f |`abcdefghijklmno|
    00000070: 70717273 74757677 78797a7b 7c7d7e7f |pqrstuvwxyz{|}~.|
    00000080: 80                                  |.               |
    
