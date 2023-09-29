# Cofo - Data Structure

This project implements a data structure called "cofo" to store information about players.

## Files

- `main.c`: Contains the main function and the interaction menu logic.
- `gCofo.c`: Contains the implementations of functions related to the `gCofo` structure.
- `gCofo.h`: Contains the definitions of the `gCofo` structure and related functions.

## Structure

### Player

The `Player` structure contains the following information:

- `id`: A unique identifier for each player.
- `name`: The player's name.
- `salary`: The player's salary.

### gCofo

The `gCofo` structure is a data structure that stores players.

## Features

- **Create Cofo**: Allows creating a cofo with a size specified by the user.
- **Insert Player**: Inserts a player into the cofo.
- **Query Player**: Checks if a specific player is in the cofo.
- **Show Players**: Displays all players present in the cofo.
- **Remove Player**: Removes a specific player from the cofo.
- **Empty Cofo**: Removes all players from the cofo.
- **Destroy Cofo**: Destroys the cofo, freeing all allocated memory.

## How to Compile and Run

### Compilation

```
gcc main.c gCofo.c -o main
Execution

Copy code
./main
Contribution
Feel free to contribute to this project by forking it and submitting a pull request.

License
This project is licensed under the MIT license.