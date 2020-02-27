#!/bin/bash
# time ./eval.sh ./edu#81/E/ E 1 6
path=$1
filename=$2
start_idx=$3
end_idx=$4
ext='.cpp'

echo Number of arguments: $#
echo path: $path
echo filename: $filename
echo ext: $ext
echo nr_tests: $nr_tests

echo ----------------------------------------------
g++ -std=c++14 $path$filename$ext -o $path$filename
ok_cnt=0
for ((i=$start_idx; i<=$end_idx; ++i)); do
    $path$filename $path$filename$i

    out=`cat $path$filename$i'.out'`
    out_correct=`cat $path$filename$i'_correct.out'`

    if [ "$out" == "$out_correct" ]; then
        status='OK'
        ((++ok_cnt))
    else
        status='WRONG'
    fi

    echo Test $i':' $status
done
echo ----------------------------------------------
echo Summary
echo ----------------------------------------------
echo 'Count(OK):' $ok_cnt
echo 'Count(WRONG):' $((end_idx - start_idx + 1 - ok_cnt))
echo ----------------------------------------------

