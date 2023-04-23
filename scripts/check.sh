#! /bin/bash
for file in $(find outputs -type f -name "*.z78")
do
	decompressed_file="${file%.*}.txt"
	file_name=$(basename $file)
	file_name="${file_name%.*}"
	original_file=$(find inputs -name "$file_name*")
	./lz78 -x $file -o $decompressed_file
	diff $original_file $decompressed_file
done
