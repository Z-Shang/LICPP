CC=cl.exe
CFLAGS=/Od /std:c++14

tests:
	$(CC) $(CFLAGS) tests.cpp /Fetests.exe

clear:
	rm *.exe
	rm *.obj
