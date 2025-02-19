# so_long

## Description
`so_long` is a simple 2D game developed using the MinilibX library. The objective of the game is to navigate through a maze-like map, collect all the collectibles, and reach the exit.

## Features
- 2D graphics using MinilibX
- Multiple map support
- Basic character movement
- Collision detection
- Collectibles and exit points

## Requirements
- gcc
- make
- MinilibX library
- X11 include files (for Linux)
- Xquartz (for MacOS)

## Installation
1. Clone the repository:
    ```sh
    git clone <repository_url>
    ```
2. Navigate to the project directory:
    ```sh
    cd so_long
    ```
3. Build the project:
    ```sh
    make
    ```
4. For additional features, such as sprite animation and moving enemies:
    ```sh
    make bonus
    ```

## Usage
Run the game with a map file:
```sh
./so_long maps/map.ber
```