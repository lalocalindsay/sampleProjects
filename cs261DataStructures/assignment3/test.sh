#!/bin/sh

for i in LLDequeBag Timing; do
	for j in 1000 2000 4000 8000 16000 32000 64000 128000 256000; do
		$i/prog $j >> raw_timing
	done
done

sed 'N;s/\n/ /' raw_timing | sed -r 's/^[^[:digit:]]+//; s/[[:space:]]+Time.*elements: /	/' > temp

echo 'Linked List	' > llist_timing
head -n 9 temp >> llist_timing

echo 'Dynamic Array' > array_timing
tail -n 9 temp >> array_timing

paste llist_timing array_timing > timing

rm temp *_timing
