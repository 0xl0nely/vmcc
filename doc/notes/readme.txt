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
