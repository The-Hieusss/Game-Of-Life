#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rows = 5, cols = 5;
int location[25];   // location array
char grid[5][5];    // Global grid, 5x5
char newgrid[5][5]; // new grid for the next generation
char input[10];
int loc_index = 0;

void printGrid1();
void printGrid2();
void locationAssign();
void gameLogic();
void onetimePrint();
int countNeighbors(int row, int col);
void PlayGameofLife();

/**
 * Main program for the Game of Life.
 *
 * This program repeatedly prompts the user to play another round of the
 * Game of Life, until the user chooses to quit. The user is first prompted
 * to enter a character; if the character is 'q', the program quits.
 * Otherwise, the program runs one round of the Game of Life, and then
 * prompts the user to play again.
 *
 * The program uses a 5x5 grid, and the user is prompted to enter up to 25
 * locations (in row-major order) to place "alive" cells on the grid. The
 * program then prints the initial grid, and then repeatedly applies the
 * rules of the Game of Life to generate the next generation, until the
 * user chooses to quit.
 */
int main()
{
    // Prmompt user input to begin the game
    char userin;
    printf("Welcome to Life ! Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &userin);

    // if not 'q' then the game keeps going
    while (userin != 'q')
    {

        PlayGameofLife();

        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &userin);
    }

    printf("Bye Bye! \n");

    return 0;
}

/**
 * Initializes the grid with all cells set to dead ('*'),
 * and then calls locationAssign() to place the alive cells
 * in the grid.
 */
void printGrid1()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = '*';
        }
    }

    locationAssign();
}

/**
 * Prints the current state of the grid.
 *
 * This function first calls gameLogic() to apply the rules of the Game of Life
 * to the grid, and then prints the current state of the grid.
 *
 * The grid is printed with each row on a separate line, and each cell
 * represented by a character: 'X' for a live cell, and '*' for a dead cell.
 */

void printGrid2()
{

    gameLogic();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * Assigns values to the grid array based on the values in the location array.
 *
 * For each index in the location array, the row and column indices are
 * calculated and the corresponding value in the grid array is set to 'X'.
 *
 * The assignment is done only if the row or column index is not zero, which is
 * done to prevent having a zero value in the grid array.
 */
void locationAssign()
{
    for (int k = 0; k < sizeof(location) / sizeof(location[0]); k++)
    {
        int pos = location[k]; // Get the position from the location array
        int row = pos / cols;  // Calculate row index
        int col = pos % cols;  // Calculate column index

        if (row != 0 || col != 0)
        {
            grid[row][col] = 'X'; // this is to prevent having an unwanted zero
        }
    }
}

/**
 * Counts the number of live neighbors a cell has.
 *
 * The function iterates through the adjacent cells of the given cell
 * and checks if the cell is alive ('X'). The number of live neighbors
 * is returned.
 *
 * The function also checks the boundaries of the grid to avoid going
 * outside of it.
 *
 * @param row The row index of the cell.
 * @param col The column index of the cell.
 * @return The number of live neighbors.
 */
int countNeighbors(int row, int col)
{
    int liveNeighbors = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue; // Skip the current cell
            int r = row + i;
            int c = col + j;

            // Check boundaries to avoid going outside the grid
            if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 'X')
            {
                liveNeighbors++;
            }
        }
    }
    return liveNeighbors;
}

/**
 * Applies the rules of the Game of Life to the grid.
 *
 * The function iterates over each cell in the grid and checks how many
 * live neighbors it has. It then applies the rules of the Game of Life
 * to the cell and stores the result in the newgrid array. The rules are:
 * 1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 * 2. Any live cell with two or three live neighbors lives on to the next generation.
 * 3. Any live cell with more than three live neighbors dies, as if by overpopulation.
 * 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 * After the rules have been applied to each cell, the function copies the
 * newgrid array to the current grid array, and vice versa.
 */
void gameLogic()
{
    // Apply the rules to each cell and store the result in the newgrid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int liveNeighbors = countNeighbors(i, j);

            // Rule 1
            if (grid[i][j] == 'X')
            {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    newgrid[i][j] = '*'; // Cell dies
                }
                else
                {
                    newgrid[i][j] = 'X'; // Cell survives
                }
            }
            // Rule 2
            else
            {
                if (liveNeighbors == 3)
                {
                    newgrid[i][j] = 'X'; // Cell becomes alive
                }
                else
                {
                    newgrid[i][j] = '*'; // Cell remains dead
                }
            }
        }
    }

    // Copy the new grid to the current grid and vice versa
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = newgrid[i][j];
        }
    }
}

/**
 * Prints the current state of the grid.
 *
 * The grid is printed with each row on a separate line, and each cell
 * represented by a character: 'X' for a live cell, and '*' for a dead cell.
 */
void onetimePrint()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * Main loop to play the Game of Life.
 *
 * This function prompts the user to input numbers between 0-24, or type 'no'
 * to stop. The numbers entered are stored in an array, and the array is printed
 * out at the end. The function then prints out the initial state of the grid,
 * and then applies the rules of the Game of Life to the grid 6 times, printing
 * out the state of the grid after each application of the rules.
 */
void PlayGameofLife()
{

    // Main loop to get user input to place the initial cells
    while (1)
    {

        printf("Enter a number between 0-24 (or type 'no' to stop): ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0;

        // If user types "no", exit the loop
        if (strcmp(input, "no") == 0)
        {
            break;
        }

        // Convert input to an integer
        int num = atoi(input);

        if (num >= 0 && num <= 24)
        {
            if (loc_index < 25)
            {
                location[loc_index++] = num; // add to the location array
                printf("Number %d added to the array.\n", num);
            }
            else
            {
                printf("Array is full, can't add more numbers.\n");
                break;
            }
        }
        else
        {
            printf("Invalid input, please enter a number between 0-24.\n");
        }
    }

    // just in case one does not remember what he inputed
    printf("Here are the locations of the cells you entered: ");
    for (int i = 0; i < loc_index; i++)
    {
        printf("%d ", location[i]);
    }
    printf("\n");

    printf("Here is Generation 0\n");
    printGrid1();
    onetimePrint();

    for (int b = 1; b < 7; b++)
    {
        printf("Here is Generation %d \n", b);

        printGrid2();
    }

    printf("Good Life! \n");
}