# formatter

In this repository you can find some ready-to-use function writte in ANSI C language for formatting text.

- The program 'detab.c' replace tabs with the correct number of blanks to space to the next tab stops.
    How to compile? 'cc detab.c'
    How to run? './a.out tabsize'
    Constraints: the 'tabsize' argument must be a non-negative number 

- The program 'entab.c' replace blanks with the minimum number of tabs + blanks to obtain the same spacing.
    How to compile? 'cc detab.c'
    How to run? './a.out tabsize'
    Constraints: the 'tabsize' argument must be a non-negative number 

- The program 'decomment.c' remove all comments from a '*.c' program.
    How to compile? 'cc decomment.c'
    How to run? './a.out file1 (file2)'
    Constraints: the 'file1' argument must be a '*.c' file and is open in read mode. The 'file2' argument is optional and is open in WRITE MODE.
    
WARNING:

pay attention when using the 'decomment.c' file with 'file2' argument!!!
Whatever the content of the file is, it will be deleted!!!
