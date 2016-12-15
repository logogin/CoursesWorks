gcc pv.c -c
gcc sem.c pv.o -o sem
gcc nosem.c pv.o -o nosem
