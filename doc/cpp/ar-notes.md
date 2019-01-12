# Table of Contents

- [Create a Static Library](#create-a-static-library)
- [Object Files in a Static Library](#object-files-in-a-static-library)
- [Extract Object Files from a Static Library](#extract-object-files-from-a-static-library)
- [Delete a File from a Static Library](#delete-a-file-from-a-static-library)
- [Add a File to a Static Library](#add-a-file-to-a-static-library)
- [View help info](#view-help-info)
- [View Symbols](#view-symbols)

## Create a Static Library


```sh
gcc -c hello.c bye.c
# which generates two files: `hello.o` and `bye.o`

ar cr libhello.a bye.o hello.o

gcc main.c -L. -lhello
```

## Display Object Files in a Static Library

```sh
ar t libhello.a

# it outputs:
#  bye.o
#  hello.o
```

## Extract Object Files from a Static Library

```sh
ar x libhello.a
# it generates two files: `bye.o` and `hello.o`

ar x libhello.a hello.
# it generates only one file: `hello.o`
```

## Delete a File from a Static Library

```sh
ar d libhello.a hello.o
```

## Add a File to a Static Library

```sh
ar r libhello.a hello.o
```

## View Help Info

```sh
ar -h

man ar
```

## View Symbols

```
nm libhello.a
```

