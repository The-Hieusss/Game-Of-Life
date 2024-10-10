Game of Life - C Implementation
Overview
This project is a simple implementation of Conway's Game of Life in C. The program simulates the cellular automaton known as the Game of Life on a 5x5 grid, allowing the user to input initial live cells and observe the evolution of the grid over time according to the game's rules.

How to Play
Starting the Game:

When the program starts, you will be prompted to either press any key to start the game or 'q' to quit.
Inputting Live Cells:

You will be asked to input locations for live cells by entering numbers between 0 and 24. These numbers correspond to the positions on the 5x5 grid in row-major order (e.g., 0 is the top-left corner, and 24 is the bottom-right corner).
You can input up to 25 locations for live cells. Once you have finished entering locations, type "no" to stop.
Game Flow:

The initial grid (Generation 0) will be displayed with your specified live cells.
The program will then run six generations of the Game of Life. For each generation, the grid will be updated based on the game's rules and printed on the screen.
Repeating the Game:

After six generations, you will be prompted to play again or quit by pressing 'q'.
Game Rules
The Game of Life operates on the following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors survives to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The grid uses the following symbols:

'X' represents a live cell.
'*' represents a dead cell.

Files
life.c: This is the main program file containing the Game of Life logic.
Compilation
To compile the program, use a C compiler like gcc:

bash
gcc -o Game-Of-Life life.c

Running the Program
After compiling, run the program with:

bash
./Game-Of-Life

Example
Here is an example of how the game works:

Enter numbers between 0-24 to place live cells.
After the initial setup, the grid will look something like this for Generation 0:
* * X * *
* * * X *
* X X X *
* * * * *
* * * * *
The program will then evolve the grid for the next six generations, updating the live and dead cells according to the rules.
Future Improvements
Possible enhancements to the program could include:

Allowing the user to change the size of the grid.
Adding a graphical interface to make the game more interactive.
Extending the game to run for more than six generations or allowing the user to specify the number of generations to run.

License
This project is open-source. You can modify and distribute it as needed.

Author
This implementation of the Game of Life was written in C for flexing purposes. 
