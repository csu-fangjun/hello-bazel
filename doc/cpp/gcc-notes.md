# Table of Contents

- [Compilation Steps](#compilation-steps)
- [Include Path](#include-path)
- [Library Path](#library-path)
- [View Predefined Macro](#view-predefined-macro)
- [View Help Info](#view-help-info)
- [View Version Info](#view-version-info)
  * [macOS](#macos)
  * [Ubuntu](#ubuntu)
- [Optimization Levels](#optimization-levels)
- [References](#references)

## Compilation Steps

- Step 1: `cpp hello.c -o hello.i`, or use `gcc -E hello.c -o hello.i`
- Step 2: `gcc -S hello.i`, which generates `hello.s`
- Step 3: `as -o hello.o hello.s`, which generates `hello.o`. It generates `a.out` by default.
- Step 4: linking. `ld ......`

To save the intermediate results, use `gcc -c -save-temps hello.c`
or `gcc -save-temps hello.c`, which generates
`hello.i`, `hello.s` and `hello.o` in the current directory.

To view the verbose information, use `gcc -v hello.c`. The first part of the verbose output
is same with that of the command `cpp -v`.

From the verbose output, we can get:

- the include path (`-I`)
- the library path (`-L`)
- the linked libraries (`-l`)

## Include Path

Refer to [Environment Variables Affecting GCC](https://gcc.gnu.org/onlinedocs/gcc/Environment-Variables.html).

- Pass from the commandline option `-I/some/path`
- `CPATH`: for header files `#include<>` of both C and C++
- `C_INCLUDE_PATH`: only for C
- `CPLUS_INCLUDE_PATH`: only for C++

## Library Path

- Pass from the commandline option `-L/some/path`
- `LIBRARY_PATH`: note that it is NOT `LD_LIBRARY_PATH`

## View predefined macro

```
cpp -dM /dev/null
```

## View Help Info

- Option 1: `man gcc`
- Option 2: `man gcc | col -b > gcc.txt`
- Option 3: `gcc --help`

## View Version Info

### macOS

```
$ gcc -v
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 7.0.2 (clang-700.1.81)
Target: x86_64-apple-darwin15.3.0
Thread model: posix
#--------------------
$ gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 7.0.2 (clang-700.1.81)
Target: x86_64-apple-darwin15.3.0
Thread model: posix
```

### Ubuntu

```
$ gcc --version
gcc (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#--------------------
$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.10' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10)
```

## Optimization Levels

- `-O0`: optimization 0, default, useful for debugging
- `-O1` or just `-O`
- `-O2`: useful for release versions
- `-funroll-loops`
- `-Os`: to reduce the size of the executable

## References

- [Links and Selected Readings][1]
- a book [An Introduction to GCC][2] by Brian J. Gough, 2004
- [GNU C Compiler Internals (Wikibook),][3]
- a book [Debugging with GDB, The GNU Source Level Debugger][4], ninth edition, 2002
- a book [The definitive guide to gcc][5], 2nd edition, 2006


[5]: https://sensperiodit.files.wordpress.com/2011/04/hagen-the-definitive-guide-to-gcc-2e-apress-2006.pdf
[4]: http://mermaja.act.uji.es/docencia/is37/data/gdb.pdf
[3]: https://en.wikibooks.org/wiki/GNU_C_Compiler_Internals
[2]: https://tfetimes.com/wp-content/uploads/2015/09/An_Introduction_to_GCC-Brian_Gough.pdf
[1]: https://gcc.gnu.org/readings.html

