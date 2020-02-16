num=1;
now=$(date '+%Y-%m-%d_%H:%M:%S');
file_name="${now}_-np_${num}"
echo $file_name
touch ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 1000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 2000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 3000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 4000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 5000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 6000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 7000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 8000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 9000  >> ./results/$file_name
./run.sh -c ./parallel.cpp -n $num -s 10000  >> ./results/$file_name