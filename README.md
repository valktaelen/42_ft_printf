# But du projet

Coder un printf (fonction variadique) simplifié et créer une librairie le contenant.

## Fonctionnalités de ft_printf

Reproduire les conversions `cspdiuxX%` de printf.

# Compilation

## Création de la librairie

`dir_ft_printf` est le dossier du code de ft_printf.

```shell
make # compile lib (create libftprintf.a)
```
ou depuis un autre dossier
```shell
make -C dir_ft_printf
```

## Compilation avec la libftprintf

- Inclure le [header](code/ft_printf.h) de la libftprintf
```c
#include dir_ft_printf/libftprintf.h
```

- Compiler avec la libftprintf

```shell
gcc -Ldir_ft_printf -lftprintf my_srcs #include header
```

# Liens des testeurs

https://github.com/paulo-santana/ft_printf_tester

https://github.com/Tripouille/printfTester
