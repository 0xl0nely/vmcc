this project will implement a simple finite state machine to perform lexical analysis on files
that follow the C programming language syntax.

it will *attempt* to detect c syntax errors, as well as parse important variables, function calls, 
operators, and keywords correctly into lexical tokens for our backend bytecode compiler and runtime
evironment

we are going to convert the C syntax into bytecode that runs within a custom written vm. we will
also *attempt* to implement a JIT; only if its applicable in this scenario. If it only serves to
slow down our project and bloat the code, i think i will leave it out.

This lexer will be used within the actual code interpreter, as well as the REPL written with the
help of the GNU readline library.

there are also many applications for something like this; one of those includes program obfuscation
through the use of virtualized runtime environments. There have been interesting crackmes that have
implemented this particular idea; so i had decided to write an api for this; as well as a shared
object library.

so remember to compile with -lvmcc

why choose c for the interpretee of choice?
=================================================
it is a has a very simple and low level syntax that doesnt involve any object oriented features. This
is great for a multitude of reasons, the first one is the fact that the ability to understand the
relationship between the language of choice, and the architecture's assembler language is a must
when attempting to write an interpreted language.

c is essentially already a portable assembler which compiles across architectures; so it would be
much easier to design and construct a bytecode to efficiently run within a stable virtualized runtime
environment.

also, c is just my favorite language, its simplicity and lack of features gives it that fun creative
feeling that i dont usually find with other languages; besides c++.



i also think it would be very efficient if we were to read/load the entire source file into memory.
as normally this is a terrible idea for binary analysis, source files shouldnt use up too much memory so
it would be optimal to do this i think.

plus, its not like theres random junk within a source file, everything is important and needs to be known
to the backend interpreter.

this project will implement it's own glibc within the virtual machine; as we cannot port any other code
to our vm. So I doubt that any of the functions will be as efficient; especially when running in a vm.

oh well, at least this time i get to write my own malloc :)

a feature i do absolutely want to add is the ability to call syscalls, and threading support. Though threads
may actually mess something up; as whenever threads are introduced into a large code base something always
breaks down.

hmhm, yea maybe leave threading support out for now.

the actual vm/interpreter may leverage threading; but im pretty sure something is going to break if i
introduce threading support within the vm's execution runtime. plus i dont even know how to do that :(


we can perform lexical analysis on each source file, and convert it all into tokens within the following
format:

(TOKEN_TYPE, VALUE)

in this case, if we are to parse a variable:

int x = 10;

(32BIT_INTEGER, 10)

or a function:

int jojo(char* arg1, int arg2, long arg3, void* arg4) {}

(FUNC, jojo)

we now have this token, so it understands to read between each ',' and read in each parameter.

i also have no clue how to make runtime environments fast; i guess i have to go research other
primary examples like etherium smart contracts, js, java, c#?

it would also be nice to have exportable bytecode, something like a jar file that can run on other
environments?

also, include c structures as they are verrryy useful and i enjoy using them :)

we should also be smart with what we feed to our vm, like; if a function is not called, or a for/while loop
has no code within it. we can just directly omit that piece of code. this shouldnt be too hard, but it might
cause some unwanted overhead in our interpreter?