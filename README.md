# C++ Tic-Tac-Toe (XO Game)

A clean, object-oriented C++ implementation of the classic Tic-Tac-Toe game. This project demonstrates the use of classes, private/public encapsulation, 2D arrays, and basic game logic.

## 🚀 Features
* **Symbol Selection:** Player 1 can choose to play as **X** or **O**.
* **Input Validation:** Prevents players from selecting invalid numbers or positions already taken on the board.
* **Dynamic Win Detection:** Automatically checks for horizontal, vertical, and diagonal win conditions.
* **Draw Detection:** Recognizes when the board is full and no winner is found.
* **Replayability:** Option to restart the game immediately after a match ends.
* **Clean UI:** Uses system commands to refresh the console for a smoother visual experience.

## 🛠 Project Structure
The project is organized into three main files:
* `XO_Project.cpp`: The entry point of the application.
* `clsXO_Game.h`: The core game engine containing the logic for turns, win-checking, and board rendering.
* `clsPlayer.h`: A simple class managing player properties and game choices using enums.

## 🎮 How to Play
1.  **Start:** Run the compiled executable.
2.  **Choose Symbol:** Player 1 selects `1` for **X** or `2` for **O**.
3.  **Place Marks:** Players take turns entering a number between `1-9` corresponding to the grid position:
    ```
      1  2  3
      4  5  6
      7  8  9
    ```
4.  **Win:** The first player to get three marks in a row (horizontally, vertically, or diagonally) wins!
5.  **Restart:** Enter `Y` at the end of the game to play another round.

## 💻 Technical Requirements
* A C++ compiler (supporting C++11 or later).
* `clsInputValidate.h`: This project relies on a custom input validation header (expected in the include path defined in `clsXO_Game.h`).

## 📝 Note
This project was developed as part of a C++ programming course, focusing on Object-Oriented Programming (OOP) principles and clean code structure.

📄 License

Distributed under the MIT License. See LICENSE for more information.
