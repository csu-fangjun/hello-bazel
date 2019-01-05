
# Table of Contents

- [Ubuntu](#ubuntu)
  * [Online glibc Source Code Browser](#online-glibc-source-code-browser)
  * [Online libstdc++ Source Code Browser](#online-libstdc-source-code-browser)

- [macOS](#macos)
- [Android](#android)
- [References](#references)

# Ubuntu

```
$ ldd qemu-aarch64
  linux-vdso.so.1 =>  (0x00007ffcab185000)
  libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f7d4d613000)
  libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f7d4d302000)
  librt.so.1 => /lib/x86_64-linux-gnu/librt.so.1 (0x00007f7d4d0fa000)
  libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f7d4cd78000)
  libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f7d4ca6f000)
  libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f7d4c859000)
  libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f7d4c63c000)
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f7d4c272000)
  libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f7d4c002000)
  /lib64/ld-linux-x86-64.so.2 (0x00007f7d4ff38000)

$ ls -l /lib/x86_64-linux-gnu/libc.so.6
lrwxrwxrwx 1 root root 12 Dec  8 10:37 /lib/x86_64-linux-gnu/libc.so.6 -> libc-2.23.so

$ ldd /lib/x86_64-linux-gnu/libc.so.6
  /lib64/ld-linux-x86-64.so.2 (0x00007f12e4fcf000)
  linux-vdso.so.1 =>  (0x00007fff741ef000)

$ ldd /lib64/ld-linux-x86-64.so.2
  statically linked

$ ls -l /lib/x86_64-linux-gnu/libm.so.6
lrwxrwxrwx 1 root root 12 Dec  8 10:37 /lib/x86_64-linux-gnu/libm.so.6 -> libm-2.23.so

$ ldd /lib/x86_64-linux-gnu/libm.so.6
  linux-vdso.so.1 =>  (0x00007ffd775d2000)
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f7c92624000)
  /lib64/ld-linux-x86-64.so.2 (0x00007f7c92cf7000)

$ ls -l /usr/lib/x86_64-linux-gnu/libstdc++.so.6
lrwxrwxrwx 1 root root 19 Dec  8 10:37 /usr/lib/x86_64-linux-gnu/libstdc++.so.6 -> libstdc++.so.6.0.21

$ ldd /usr/lib/x86_64-linux-gnu/libstdc++.so.6
  linux-vdso.so.1 =>  (0x00007ffd5cdf5000)
  libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f4fb4a05000)
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f4fb463b000)
  /lib64/ld-linux-x86-64.so.2 (0x00007f4fb5090000)
  libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f4fb4425000)
```

Note that `linux-vdso.so.1` does not exist in the disk.

`libc.so` is the GNU c standard library, whereas `libstdc++.so` is the GNU c++ standard library.

Both `libc` and `libstdc++` are provided by gcc. `libc` is also known as `glibc`.

## Online glibc Source Code Browser

Go to <https://code.woboq.org/userspace/glibc/> to view glibc source code online.

## Online libstdc++ Source Code Browser

Go to <https://code.woboq.org/gcc/libstdc++-v3/> to view libstdc++ source code.

C++11 can be found at <https://code.woboq.org/gcc/libstdc++-v3/src/c++11/>.

# macOS

```
$ otool -L qmake
qmake:
  /System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 1252.0.0)
  /System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices (compatibility version 1.0.0, current version 728.4.0)
  /System/Library/Frameworks/ApplicationServices.framework/Versions/A/ApplicationServices (compatibility version 1.0.0, current version 48.0.0)
  /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
  /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1225.1.1)
  /System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation (compatibility version 150.0.0, current version 1253.0.0)
  /usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)

$ otool -L /usr/lib/libc++.1.dylib
/usr/lib/libc++.1.dylib:
  /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
  /usr/lib/libc++abi.dylib (compatibility version 1.0.0, current version 125.0.0)
  /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1225.0.0)
```

`libSystem.B.dylib` is the c standard library on macOS, while `libc++.1.dylib`
is the c++ standard library.

Both `libSystem` and `libc++` are provided by llvm.

# Android

The c standard library on Android is `bionic`. The source code
can be found at <https://github.com/aosp-mirror/platform_bionic>

# References

- [What are the C and C++ Standard Libraries?][1]


[1]: https://www.internalpointers.com/post/c-c-standard-library

