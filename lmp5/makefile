compile:
	cc -c q_sort.c -ggdb
	cc -c insort.c -ggdb
	cc -o main insort.o q_sort.o test.c -DMAX_ELEM_2_PRINT=5 -ggdb
	rm -rf insort.o q_sort.o
