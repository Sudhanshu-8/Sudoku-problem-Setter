# Sudoku-problem-Setter

Sudoku Solver and Generator

A simple Sudoku game that generates puzzles and allows users to solve them. The program includes three difficulty levels and uses a backtracking algorithm to both solve and generate puzzles, checking for valid moves as users interact with the board.

🛠️ Features:

    Sudoku Puzzle Generation: Generates a fully solved Sudoku puzzle and removes numbers based on the selected difficulty level.
    Difficulty Levels: Three levels of difficulty (easy, medium, and hard), determined by the number of empty cells.
    Backtracking Algorithm: Solves the puzzle automatically using a backtracking approach.
    Validation: Ensures that the user’s input follows Sudoku rules (numbers do not repeat in rows, columns, or subgrids).
    Interactive Gameplay: Users can enter their own moves and see an updated board after each move.

⚙️ Technologies Used:

    C Programming: For implementing the Sudoku logic, puzzle generation, and validation.
    Standard Library: For functions like input/output and random number generation.

🚀 How to Run the Project:

    Clone the repository:
    git clone https://github.com/sudhanshu-8/sudoku-solver.git
    Open the project folder and compile the program:
    gcc -o sudoku main.c
    Run the compiled program:
    ./sudoku

📂 Project Structure:

    main.c: Contains the logic for Sudoku puzzle generation, solving, validation, and user interaction.
    Makefile: For compiling and running the project (if applicable).
