// HackTheBox challenge
// Crypto - Nuclear Sale
// ch3ng
// 31 Jul 2022

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// encrypted message from email stream
// all length = 72
string msg1 = "6b65813f4fe991efe2042f79988a3b2f2559d358e55f2fa373e53b1965b5bb2b175cf039";
string msg2 = "fd034c32294bfa6ab44a28892e75c4f24d8e71b41cfb9a81a634b90e6238443a813a3d34";
string msg3 = "de328f76159108f7653a5883decb8dec06b0fd9bc8d0dd7dade1f04836b8a07da20bfe70";

// hex char to int
int char_to_int(char c)
{
    if (c >= '0' and c <= '9') return (int)(c - '0');
    if (c >= 'a' and c <= 'f') return (int)((c - 'a') + 10);

    // should never happen
    cout << "Invalid ciphertext byte detected!" << endl;
    return -1;
}

// driver function
int main()
{
    // turn ciphertext string into a byte array
    uint8_t cipher1[36];
    uint8_t cipher2[36];
    uint8_t cipher3[36];

    for (int i=0; i<36; i++)
    {
        cipher1[i] = ((char_to_int(msg1[2*i])<<4) + char_to_int(msg1[2*i+1]));
        cipher2[i] = ((char_to_int(msg2[2*i])<<4) + char_to_int(msg2[2*i+1]));
        cipher3[i] = ((char_to_int(msg3[2*i])<<4) + char_to_int(msg3[2*i+1]));
    }

    // P = plaintext, S = sales key, M = management key
    // cipher1 = P ^ S
    // cipher2 = cipher1 ^ M
    // cipher3 = cipher2 ^ S

    // Therefore,
    // cipher3 ^ cipher2 = cipher2 ^ cipher2 ^ S = S
    // Then P = cipher1 ^ S

    // find S
    uint8_t sales_key[36];
    for (int i=0; i<36; i++) sales_key[i] = cipher2[i] ^ cipher3[i];

    // find P
    uint8_t plaintext[36];
    for (int i=0; i<36; i++) plaintext[i] = cipher1[i] ^ sales_key[i];

    // print out plaintext
    cout << "Original message: ";
    for (int i=0; i<36; i++) cout << (char)plaintext[i];
    cout << endl;
    
    return 0;
}