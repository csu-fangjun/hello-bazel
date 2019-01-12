
Source file

```.cpp
int ii;
int iii = 0;
int i = 10;
const int ci = 1;
static int si = 2;
static int sii;
static const int sci = 3;

extern int ei;
extern const int eci;
extern int ef(int);

int f(int k) { return k + 2; }
static int sf(int i) { return ef(0) + ei + eci; }
```

Compile it with `gcc -c -o nm.o nm.c` and then view the symbols

```
$ nm nm.o

0000000000000000 R ci
                 U eci
                 U ef
                 U ei
0000000000000000 T f
0000000000000000 D i
0000000000000004 C ii
0000000000000000 B iii
0000000000000004 r sci
000000000000000a t sf
0000000000000004 d si
0000000000000004 b sii
```

- `ci`: `R`, upper case, global, read only data section
- `eci`: `U`, upper case, global, undefined
- `ef`:  `U`, upper case, global, undefined
- `ei`:  `U`, upper case, global, undefined
- `f`:  `T`, upper case, global, text (code) section
- `i`:  `D`, upper case, global, initialized data section
- `ii`: `C`, upper case, global, (c)ommon symbols
- `iii`: `B`, upper case, global, uninitialized BSS section
- `sci`: `r`, lower case, local, read only data section
- `sf`:  `t`, lower case, local, text (code) section
- `si`:  `d`, lower case, local, initialized data section
- `sii`:  `b`, lower case, local, uninitialized BSS section

To show only exported, i.e., global symblos:

```
0000000000000000 R ci
                 U eci
                 U ef
                 U ei
0000000000000000 T f
0000000000000000 D i
0000000000000004 C ii
0000000000000000 B iii
```

To show only undefined symbols:

```
$ nm -u nm.o
U eci
U ef
U ei
```

Compile with debug information:

```
$ gcc -g -c -o nm.o nm.c
fangjun@ubuntu:/tmp/to-delete$ nm -l nm.o
0000000000000000 R ci   /tmp/to-delete/nm.c:4
                 U eci  /tmp/to-delete/nm.c:14
                 U ef   /tmp/to-delete/nm.c:14
                 U ei   /tmp/to-delete/nm.c:14
0000000000000000 T f    /tmp/to-delete/nm.c:13
0000000000000000 D i    /tmp/to-delete/nm.c:13
0000000000000004 C ii
0000000000000000 B iii  /tmp/to-delete/nm.c:13
0000000000000004 r sci  /tmp/to-delete/nm.c:13
000000000000000f t sf   /tmp/to-delete/nm.c:14
0000000000000004 d si   /tmp/to-delete/nm.c:13
0000000000000004 b sii  /tmp/to-delete/nm.c:13
```
Use the `sysv` format

```
$ nm --format sysv nm.o

Symbols from nm.o:

Name                  Value           Class        Type         Size             Line  Section

ci                  |0000000000000000|   R  |            OBJECT|0000000000000004|     |.rodata
eci                 |                |   U  |            NOTYPE|                |     |*UND*
ef                  |                |   U  |            NOTYPE|                |     |*UND*
ei                  |                |   U  |            NOTYPE|                |     |*UND*
f                   |0000000000000000|   T  |              FUNC|000000000000000f|     |.text
i                   |0000000000000000|   D  |            OBJECT|0000000000000004|     |.data
ii                  |0000000000000004|   C  |            OBJECT|0000000000000004|     |*COM*
iii                 |0000000000000000|   B  |            OBJECT|0000000000000004|     |.bss
sci                 |0000000000000004|   r  |            OBJECT|0000000000000004|     |.rodata
sf                  |000000000000000f|   t  |              FUNC|0000000000000029|     |.text
si                  |0000000000000004|   d  |            OBJECT|0000000000000004|     |.data
sii                 |0000000000000004|   b  |            OBJECT|0000000000000004|     |.bss
```

