# DSA-Implementation
#### This is my implementation of the Sem-3 Data structures in C.
_Some key points_ :  
* **THERE IS NO ERROR CHECKING FOR WRONG INPUT. INPUT VALUES CORRECTLY.**
* The functions have been made using no-return type. You can try to implement return type functions yourself.
* If while compiling, the compiler shows errors, then look for any `for` loops in the code and check for the loop variable declaration.

If the loop is declared like this:
```c
for(int i = 0; i<n; i++){
    //some code here
}
```
Change it to:
```c
int i;
for(i = 0; i<n; i++){
    //some code here
}
```
Some IDEs like Code::Blocks use C89 syntax which creates the compile time error.

The programs should work fine with gcc or clang compilers using make. If they don't work then pass in `-std=C99` as a flag with the compiler.

