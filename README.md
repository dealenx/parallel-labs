# parallel-labs

## Введение

Репозиторий для лабараторных работ по параллельному программированию на C++ и MPI

## Установка ПО

```
$ sudo apt-get update

$ sudo apt-get install gcc

$ sudo apt-get install libopenmpi-dev
$ udo apt-get install openmpi-bin
```

## Проверка запуска программ

Надеюсь, что данные комманды работают на всех Linux.
Лично я проверял только на Linux Mint 19.3

```
// Вы находитесь в корневой папке

$ cd test
$ mpicxx main.cpp -o main
$ mpirun -n 4 main

Hello MPI: processor 1 out of 4
Hello MPI: processor 2 out of 4
Hello MPI: processor 0 out of 4
Hello MPI: processor 3 out of 4
```
