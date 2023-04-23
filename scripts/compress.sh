#! /bin/bash
# Compresses all the files from the `inputs` folder
# and saves the results in the `outputs` folder

for dir in $(find inputs -type d)
do
	output_dir="${dir/inputs/outputs}"
	mkdir -p $output_dir
done

for file in $(find inputs -type f)
do
	compressed_file="${file/inputs/outputs}"
	compressed_file="${compressed_file%.*}"
	compressed_file="${compressed_file}.z78"
	./lz78 -c $file -o $compressed_file
done
