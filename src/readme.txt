c syntax parser and lexer written in c++

this c interpreter works in the following fashion

1. Read file into memory and tokenize
2. Pass tokens to parser and construct an Abstract Syntax Tree
3. Pass Abstract Syntax Tree and Symbol Table to Semantic Analyzer
4. Generate Bytecode (may also be exported into file format)
5. Run Bytecode in Custom Runtime Environment

note:
*it is reccomended to compile into bytecode first, as compiling it will cause a large startup time*


each statement will have specific conditions that must be met
for example, each statement must have multiple expressions

we can see that "int", will be the statement; which must be followed by
the variable name, assignment operator, and semi colon expression.
for example, our lexer will tokenize the following as:

char* test = "jotaro";

(CHAR) (POINTER) (VAR, test) (ASSIGN) (LEFT_DQUOTE) (LITERAL, jotaro) (RIGHT_DQUOTE) (SEMICOLON)

int x = 20;

(INTEGER) (VAR, x) (ASSIGN) (LITERAL, 20) (SEMICOLON)

int main(int argc,char**argv) {
    return -1;
}

(INTEGER) (VAR, main) (LEFT_PAR) (INTEGER) (VAR, argc) (COMMA) (CHAR) (POINTER) (POINTER)
(RIGHT_PAR) (LEFT_BRACKET) (RETURN) (LITERAL, -1) (SEMICOLON) (RIGHT_BRACKET)

lets go through and explain how we can decipher what these tokens are telling us.
we can see that we want to assign a value through the int keyword. Next, we parse the main
string as a variable to the int. Next, we will see that it is attempting to create a function
through the left parenthesis.

This paranthesis will tell our state machine that we want to transition to the function
state. When we are here, we now know that we are declaring a function.

Then, we know that the next variables assigned will be parameters to this function; and they
will all be parameters until our lexer reads until the RIGHT_PAR/right parenthesis.
Then, if it is simply a function declaration, if it reads a semicolon; then it will make
another transition and declare that function. Else, if it finds a left bracket, it will
go and know that it is now reading code; it will attempt to read until a right bracket
has been reached.

then, it will reach the return keyword, since this is a keyword it will know that the next
literal or variable being passed to return will be the parameter to return. Again, it will
read until semi colon.

Finally, it reaches the right bracket and will continue to read until new data or EOF.
as we can see, it will first initialize our integer declaration as to prevent previous stack
frame uaf bugs.

the lexer will be implemented in a "naive" way; which is according to my own logical
standards. no regex implementation, no deterministic state machine, just according to my
own logic. Of course, this could also be considered a state machine, but the more accepted
version is when we use a fsm table. This takes up too much memory in my opinion, so im just
not gonna do that.

I will however, play around with other lexer models; and in the future if i find one faster than
this basic naive approach, i will implement that.

of course, we will be passing these tokens to our parser to contruct our Abstract Syntax
Tree, so we will only have to worry about interpreting tokens at that stage of devlopment.
at this point, the only thing i have to worry about is dumbing down the syntax into little
bite sized chunks of info.

yes okay, lexer is coming along great; except for one little detail. i really hate how dumb the
keyword comparison is, its literally comparing each char we iterate through with a huge list of
strings.

im gonna be implementing a hash table

first parse into literal tokens, then afterwards search hash table for matching keywords. This
method will work much better, as we dont have to strcmp each and every single char to check if it
matches a keyword.

The rest of the literals will be interpreted depending on context. An example is function name,
variable names, parameters, et cetera.

open addressing, linear probing, robin hood hashing for the hash table, pretty fast combination.

lets explain each of these in depth

open addressing
================================================
separate chaining and open addressing are the two most common ways of organizing our hash table. open
addressing simply means that the entire table will be stored within one large allocation, all adjacent
to each other.

separate chaining on the other hand simply means to store each allocation in separate allocations.

This is a very simple concept, simply a choice in how we choose to organize memory, but they have
pretty drastic advantages and implications

when organizing memory into separate chains, it provides extremely fast access due to no indirection
within our entries. This allows for extremely fast access (as stated), but also provides instability
when we attempt to reference elements.

this method also uses a lot more memory, this is also due to glibc's allocator attempting to be
as smart and efficient as possible. This efficiency causes a bit of a caveat as the minimal
allocation size is 24 on 64 bit addressing mode machines; and will continue to allocate chunk
sizes by a factor of 16.

This prevents irreparable fragmentation within the heap memory, and allows the caching bins to
set a fixed size on each index. This however, means that each allocation will not be as memory
efficient if we want to only allocate an exact size.

so the only instance in which we should be using separate chaining in my opinion is if we are to
implement our own memory allocator that is very efficient in memory reuse. Just because we have all
the memory we want doesnt mean we should abuse it >:(

now for the downside to open addressing, it will attempt to use the first freed slot, and sometimes
the key that points to that slot is very far away. This may slow down the retrieval as well.

we will solve this worst case problem later, and drastically improve the speed of our open addressing
implementation through the help of the robin hood algorithm. 

Since we are implementing this within a lexer, the most common case that will occur is that we will
not find a keyword with each char. This means that we will have to search through the hash table
and probe it every time we iterate through a char? theres no way that can be efficient right??

well, you are correct this is very inefficient i think a determinstic state machine would
be much better but the robin hood algorithm actually has much lower probing counts than the
alternatives. This means that, our issue is sort of reduced thanks to this algorithm as well?

linear probing
================================================
the term linear probing simply means that we will be populating each entry on the table by the
freed adjacent entries. This allows us to perform extremely fast population without the count of
an index or keeping track.

here is a basic example of an array allocated on the heap:

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char**argv) {
    int n = sizeof(long)*3, i;
    void* heaparray = (void*)malloc(n);
    for (i = 0; i < (n/4); i++) {
        if (!*(int*)(heaparray + (sizeof(int)*i))) {
            printf("You can use slot: %d!\n", i);
        }
    }
}

so this little script will print out that slot 1-5 is free, since its memory we had just allocated.

of course, when working with glibc we are bound to get free chunk metadata left on the chunk we
had just allocated. This is due to the caching mechanisms leaving important data within the
usable chunk. these were meant to reduce overhead, as the only purpose of these caching bins were
to recycle previous chunks and prevent the overhead that brk/mmap had when dynamically allocating
memory.

so when working with dynamic memory, make sure to zero out that memory. the same goes with the stack
as when we declare an uninitialized variable, the only purpose it serves is an access pointer on the
stack.

robin hood hashing
================================================
this is an algorithm that attempt to efficiently implement the normal open addressing hash table.
















