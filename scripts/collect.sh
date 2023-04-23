#! /bin/bash
# Collects information about the compression
# for the files that were compressed correctly
# Saves the results in the `stats` folder, grouped by input set

for dir in $(find inputs -type d)
do
	output_dir="${dir/inputs/outputs}"
	mkdir -p $output_dir
done

for dir in $(find inputs -type d)
do
	dir_name=$(basename $dir)
	mkdir -p stats
	touch "stats/$dir_name.csv"
	echo "name,input_size,compressed_size" > "stats/$dir_name.csv"

	echo "Gathering stats for testset $dir_name"

	for file in $(find $dir -type f)
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
		diff $file $decompressed_file > /tmp/null &&
			echo "$(basename $file),$(stat --printf="%s" $file),$(stat --printf="%s" $compressed_file)" >> "stats/$dir_name.csv"
	done
done

