#! /bin/bash
for dir in $(find inputs -type d)
do
	output_dir="${dir/inputs/outputs}"
	mkdir -p $output_dir
done

for file in $(find inputs -type f)
do
	output_path="${file/inputs/outputs}"
	output_path="${output_path%.*}"
	output_path="${output_path}.z78"
	./lz78 -c $file -o $output_path
done
