Simple linear dynamic memory allocator for our virtual machine. It will encorporate a caching bin
very similar to the simple thread local caching implemented by ptmalloc.

also, something that should be noted is that this vm does not care about unsafe code or memory
corruption vulnerabilities. It is already slow enough and i want to stay true to the memory unsafe
language of C.

2 bins will be implemented within this memory allocator, tcache; and the unsorted bin

the only difference with the functionality of the unsorted bin is that it will not attempt to
actually sort the bin. Instead, the only functionality it serves is to return a chunk if it has the
same allocation size, or if the user requests a chunk size that is smaller, split off that chunk
size and add the last remainder chunk into the tcache.

All cached chunks will stay within the unsorted bin until another allocation makes it split, and
adds the last remainder chunk into the tcache.

this way, we can optimize for speed but also prevent large amounts of fragmentation. If we are to
simply cache chunks by a first fit basis, then if the chunk requested is not an exact fit; or lower, 
then it will simply allocate a new chunk. That is very inefficient.
