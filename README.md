# 🔐 XOR Stream Cipher

A lightweight, high-performance file encryption tool written in C. 

This utility implements a **Stream Cipher** using XOR operations paired with a Pseudo-Random Number Generator (PRNG). It transforms a user-provided password into a deterministic seed, creating a unique key stream that can encrypt and decrypt files of any format (Images, Videos, PDFs, etc.).

## 🚀 Features

* **Symmetric Encryption:** Uses the XOR bitwise operation ($A \oplus B = C$), allowing the same function to both encrypt and decrypt.
* **PRNG Key Stream:** Instead of a repeating key (like Vigenère), it uses `srand()` seeded by the password to generate a non-repeating byte stream.
* **Binary Support:** Handles files in binary mode (`rb`/`wb`), ensuring safe processing of non-text files like `.jpg` or `.exe`.
* **Large File Support:** Processes data byte-by-byte, keeping memory usage low regardless of file size.
* **Progress Tracking:** Includes a visual progress bar for large file operations.
* **Path Handling:** Supports absolute and relative file paths with spaces.

## 🛠️ Installation & Compilation

You need a C compiler (GCC or Clang).

```
# Clone the repository
git clone [https://github.com/YOUR_USERNAME/xor-stream-cipher.git](https://github.com/YOUR_USERNAME/xor-stream-cipher.git)

# Navigate to the directory
cd xor-stream-cipher

# Compile the code
gcc cipher.c -o cipher
```
