#!/bin/bash

helpFunction()
{
   echo ""
   echo "Usage: $0 -c ./main.cpp -n 2 -s 4"
   echo -e "\t-c Файл cpp-программы "
   echo -e "\t-n Количество процессов"
   echo -e "\t-s Размер N массивов"
   exit 1 # Exit script after printing help
}

while getopts "c:n:s:" opt
do
   case "$opt" in
      c ) parameterC="$OPTARG" ;;
      n ) parameterN="$OPTARG" ;;
      s ) parameterSIZE="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Print helpFunction in case parameters are empty
if [ -z "$parameterC" ] || [ -z "$parameterN" ] || [ -z "$parameterSIZE" ]
then
   echo "В запуске отсуствуют параметры!";
   helpFunction
fi

# Begin script in case all parameters are correct
# echo "--- Компиляция main.cpp ---"
# mpicxx $parameterC -o $parameterC.bin
# echo ""
# echo "--- Запуск main.cpp с аргументом n=$parameterSIZE ---"
# echo ""
# echo "--- Вывод программы ---"
mpirun -n $parameterN $parameterC.bin $parameterSIZE