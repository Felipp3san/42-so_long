# so_long

A **2D game** built in **C** using **MiniLibX**, developed as part of the **42 School curriculum**.  
The goal is to create a small graphical game where a player collects items, avoids enemies (bonus), and reaches the exit.  
The project focuses on **graphics programming**, **event handling**, and **map validation**.

## Features (Mandatory)

- **2D map rendering** using MiniLibX
- **Player movement** with keyboard input
- **Collectibles**, **walls**, and **exit tiles**
- **Valid path validation** for every map
- **Frame rendering** and window management
- **Error handling** and **memory management**

## Features (Bonus)

- **Enemy movement** and collision detection  
- **Animations** for player, collectibles, and enemies  
- **Extra sprites** and dynamic elements  
- **Improved visual experience**

## Tech Stack

- **C** – Core language  
- **MiniLibX** – Rendering and event handling  
- **Libft** – Utility functions  
- **Makefile** – Build and management  

## Installation

1. Clone the repository:

```bash
git clone https://github.com/Felipp3san/42-so_long.git
cd 42-so_long
```

2. Compile the project:

```bash
make          # Compile mandatory version
make bonus    # Compile bonus version
```

## Usage

### Run the game

```bash
./so_long maps/map.ber
```

- The `.ber` map file defines the layout of the game.
- The player can move using **W, A, S, D**.
- The goal is to collect all items and reach the exit.

### Example

```bash
./so_long maps/level1.ber
```

This loads the map `level1.ber` and starts the game.

### Bonus

```bash
./so_long_bonus maps/map_bonus.ber
```

Runs the bonus version with enemies, animations, and additional features.

## Map Format

Each map is a `.ber` file containing:

| Symbol | Meaning       |
|:------:|:--------------|
| `1`    | Wall          |
| `0`    | Floor         |
| `C`    | Collectible   |
| `E`    | Exit          |
| `P`    | Player start  |
| `X`    | Enemy (bonus) |

Example:

```
111111
1P0C01
1000E1
111111
```

## Compilation

- Build the mandatory executable:

```bash
make
```

- Build the bonus executable:

```bash
make bonus
```

- Remove object files:

```bash
make clean
```

- Remove all binaries and rebuild:

```bash
make re
```

## Project Structure

```
.
├── include/           # Header files
├── src/
│   ├── mandatory/     # Core game source files
│   └── bonus/         # Bonus version source files
├── libft/             # Custom Libft library
├── mlx/               # MiniLibX library
├── build/             # Object files
└── maps/              # Example map files
```

## License

Educational project under 42 School academic policy.
