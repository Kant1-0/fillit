# Fillit
Emulate a kind of Tetris IA able to create the smallest square with given tetriminos. A 42's school project. See the (https://github.com/Kant1-0/fillit/blob/master/doc/fillit.fr.pdf "pdf file") for more information.

___________
#### Compile
To compile you should first download the libs: (https://github.com/Kant1-0/libft "libft") and (https://github.com/Kant1-0/lib-list "lib-list"). *If cloned as separate folders in the directory, no need to change the path in the Makefile. Otherwise you can change it as* ***PATHLIBFT*** *and* ***PATHLIBLIST***.

Then execute this code in fillit folder.

    make libs
    make

___________
#### Handle Libs
Directly from the fillit folder you can handle the libs folder with (as a 'make fclean' and a 'make re').:

    make cleanlibs
    make relibs 

Libs will be copy/paste into the **fillit/lib** folder.

___________
#### Render Tetriminos
You can render different type of tetriminos thanks to the (https://github.com/hqro/Tetriminos-generator "Tetriminos Generator") made by hqro. The makefile handle invalid and valid samples of 6 tetriminos. If you wanna learn more about it go at original project git.

To compile the Tetriminos generator:

    make retetris

Then choose between:

    make invalidtetris
    make validtetris

___________
#### Execute and Debug
To execute the compiled prog:

    ./fillit sample.fillit

In **fillit.h** you can choose the debguging option to show when the executables runs, look at line #42:

    // ************************************************************************** //
    // Debug Conditionnal Macro
    // Uncomment #define _MACRO to choose how to debug
* _DEBUG will simply show you if functions that code is running succeed or failed.
* _TRACE is more detailled than debug and show eg where variables are saved.
* _ERROR is a basic macro that output 'error' when the file is invalid. You should always keep it uncommented.
