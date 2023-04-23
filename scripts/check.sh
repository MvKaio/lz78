#! /bin/bash
# Compresses and decompresses files and checks if the result 
# is the same as the original files

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

	# Compress
	./lz78 -c $file -o $compressed_file > /tmp/null

	decompressed_file="${compressed_file%.*}"
	decompressed_file="${decompressed_file}.txt"

	# Decompress
	./lz78 -x $compressed_file -o $decompressed_file > /tmp/null

	# Check
	diff $file $decompressed_file > /tmp/null ||
	echo "Error in the compression for $file"
done
