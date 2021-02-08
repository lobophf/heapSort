CC := g++
BUILDDIR := ../build
SRCDIR := ../src
ROOTTARGET := ../bin
TARGET := $(ROOTTARGET)/demos_bin
SRCOBJ := $(BUILDDIR)/heapsort.o $(BUILDDIR)/heap.o

all: demo_sortIntegers.out demo_sortStrings.out

demo_sortIntegers.out: $(TARGET) demo_sortIntegers.o
	$(CC) -o $(TARGET)/demo_sortIntegers.out demo_sortIntegers.cpp $(BUILDDIR)/heapsort.o $(BUILDDIR)/heap.o

demo_sortIntegers.o: $(BUILDDIR) heapsort.o
	$(CC) -c -o $(BUILDDIR)/demo_sortIntegers.o demo_sortIntegers.cpp 

demo_sortStrings.out: $(TARGET) demo_sortStrings.o
	$(CC) -o $(TARGET)/demo_sortStrings.out demo_sortStrings.cpp $(BUILDDIR)/heapsort.o $(BUILDDIR)/heap.o

demo_sortStrings.o: $(BUILDDIR) heapsort.o
	$(CC) -c -o $(BUILDDIR)/demo_sortStrings.o demo_sortStrings.cpp 

heapsort.o: heap.o
	$(CC) -c -o $(BUILDDIR)/heapsort.o ../src/heapsort.cpp

heap.o:
	$(CC) -c -o $(BUILDDIR)/heap.o ../src/heap.cpp

# create the folders
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET):
	mkdir -p $(TARGET)

# remove the binary files
clean:
	rm -rf $(ROOTTARGET)
	rm -rf $(BUILDDIR)
