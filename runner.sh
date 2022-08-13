#!/bin/bash

g++ gen/test_generator.cc -o test_generator -std=c++17
g++ gen/solution.cc -o solution

./test_generator

for i in {1..2}
do
    input_file_name="input/sub1.$i.in"
    output_file_name="output/sub1.$i.out"
    ./solution $input_file_name $output_file_name
done

for i in {1..8}
do
    input_file_name="input/sub2.$i.in"
    output_file_name="output/sub2.$i.out"
    ./solution $input_file_name $output_file_name
done