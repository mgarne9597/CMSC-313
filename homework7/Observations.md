Looking at all the assembly code from each of the .S files 
I attached to this repository, there are a few general similarities 
and differences. It looks like all of the files have a
similar structure. For example at the top of each of them
it says the name of the file and various definitions. There are
also several sections throughout the code that start with LF followed by
another letter and a number. There are also sections that are just L followed
by a number. There are also what appears to be functions being used several
times throughout each file, such as "movel" and "jmp".
One difference is that in the addmats.s file, there are a few definitions
that do not appear in the other two files called ".align 2",
".linkonce discard", and ".section". 
