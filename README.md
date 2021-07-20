<img width="192" height="192" align="left" style="float: left; margin: 0 10px 0 0;" alt="logo" src="https://github.com/0xmanjoos/vmcc/blob/main/img/icon.png?raw=true">

# VMCC: The Virtual Machine C Compiler
A fully featured interpreter for the C language syntax.
<br/>
<br/>
<br/>
<br/>
<br/>

## Goals with the Project
* Create a way to port C code across architecture efficiently.
* Extremely Fast Runtime Environment.
* Easily Extensible.
* Find an easy way to obfuscate malicious C code from static analysis.
* Make it as efficient as possible

## Features
* The RISC Register Based Virtual Machine utilizes 64 bit addressing mode.
* Extremely fast lexer, parser, analysis, and bytecode generation.
* Does not rely on any bloated external libraries besides GLIBC.
* Virtual Machine supports 32 bit addressing modes as well.
* Minimal Memory Footprint.
* Custom Bytecode File Format.
* Built-in REPL for ease of use.
* Extremely Small Custom written GLIBC, optimized for the virtual machine
* Debugger for code running in the virtual machine
* Easy to use API for c++

## Installation

```bash
git clone https://github.com/0xmanjoos/vmcc
cd vmcc && make && make install
```

## Usage

There are multiple ways to use this project. If you are looking for the command line
interpreted REPL, or the C bytecode compiler; simply run the following command:

```
user@ghost~# vmcc --help
```

If you are looking for the VMCC api, then please look towards the DOCUMENTATION.md, as it will
contain all the information required to utilize it.

## Contributing

If you would like to directly contribute to the project, feel free to buy me a coffee as it makes
me feel good :)

[ ![rickroll_:)](/img/coffee.gif)](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

### How to report issues

Before reporting it to us, be sure to check that the following are correct:

* You are using a clean installation
* The issue has not already been reported

Its okay if you forget these sometimes :)

If you find that this project seems to be missing something, or if the code is completely abominable;
you can contribute to this project by creating that feature (or fixing one). You may fork the
main repository and implement the feature there; but odds are that I wont merge if you do not 
directly reach out to me.

Here is my contact information:

```
Email:
manjoos@protonmail.com

Discord:
manjoos#0745

Address:
2430 E St NW, Washington, DC 20037
```

Please do not send pipe bombs, that would not be a worthwhile contribution >:(

