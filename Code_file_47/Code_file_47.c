#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 9
#define UNASSIGNED 0

void printGrid(int grid[N][N], int x) {
    if(x == 1 || x == 2 || x == 3){
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("---------------------\n");
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                printf("| ");
            }
            if (grid[row][col] == UNASSIGNED) {
                printf("  ");
            } else {
                printf("%d ", grid[row][col]);
            }
        }
        printf("\n");
    }
}
else{
    printf("No such level exist");
}
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    if (!isEmpty) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}


void generateSudoku(int grid[N][N], int x) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    solveSudoku(grid);
    int removeCount;
    if(x == 1){
     removeCount = 40;
    }
    else if(x == 2){
        removeCount = 50;
    }
   else if(x == 3){
       removeCount = 60;
   }
   else{
       printf("no level exist");
       exit(1);
   }
    while (removeCount > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = UNASSIGNED;
            removeCount--;
        }
    }
    
}
int main() {
    int grid[N][N];
    int x;
    printf("Difficulty level ( 1 for easy , 2 for medium , 3 for hard ): ");
    scanf("%d",&x);
    generateSudoku(grid,x);
    printf("Sudoku Puzzle: \n");
    printGrid(grid,x);

    while (1) {
        int row, col, num;
        printf("Enter row, column, and number (0 to quit): ");
        scanf("%d", &row);
        if (row == 0) {
            break;
        }
        scanf("%d %d", &col, &num);
        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (!isSafe(grid, row - 1, col - 1, num)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        grid[row - 1][col - 1] = num;
        printf("Updated Sudoku Puzzle: \n");
        printGrid(grid,x);
    }

    return 0;
}
