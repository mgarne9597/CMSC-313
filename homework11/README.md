**Compiling and Executing Instructions**
1) open terminal and cd to the asm file location.
2) Assemble the code using NASM to produce an object file. Do this by running the cmd "nasm -f elf32 hw11translate2Ascii.asm -o hw11translate2Ascii.o"
3) Use the GNU linker in 32-bit mode to turn the object file into an executable. Do this by running the cmd "ld -m elf_i386 hw11translate2Ascii.o -o hw11translate2Ascii"
4) Finally, run the program by using the cmd "./hw11translate2Ascii"
