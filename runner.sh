#!/bin/bash

g++ gen/test_generator.cc -o test_generator -std=c++17
g++ gen/solution.cc -o solution

./test_generator

for i in {1..1}
do
    input_file_name="input/case1_0$i.in"
    output_file_name="output/case1_0$i.out"
    ./solution $input_file_name $output_file_name
done

for i in {1..2}
do
    input_file_name="input/case2_0$i.in"
    output_file_name="output/case2_0$i.out"
    ./solution $input_file_name $output_file_name
done

for i in {1..3}
do
    input_file_name="input/case3_0$i.in"
    output_file_name="output/case3_0$i.out"
    ./solution $input_file_name $output_file_name
done

for i in {1..4}
do
    input_file_name="input/case4_0$i.in"
    output_file_name="output/case4_0$i.out"
    ./solution $input_file_name $output_file_name
done
