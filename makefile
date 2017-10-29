PSCP = pscp -pw pergikezoo
DEST = mf747@kill.cs.rutgers.edu:cs/


#send sorter.c sorter.h mergesort.c to ilab:cs/

csort:
	$(PSCP) sorter.c $(DEST)

hsort:
	$(PSCP) sorter.h $(DEST)

cmerge:
	$(PSCP) mergesort.c $(DEST)

make:
	$(PSCP) makefile $(DEST)

test:
	$(PSCP) test.c $(DEST)

tartest:
	tar -cvf barang.tar ./barang

sendtar:
	$(PSCP) barang.tar $(DEST)

untar:
	tar -xvf barang.tar
	
putty:
	rm -f sorter && gcc -o sorter sorter.c mergesort.c