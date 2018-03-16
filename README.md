# Fillit

This program takes a file as parameter, which contains a list of **Tetriminos**
(4-block geometric figure, well-known from the **Tetris**), and arrange them in order to create the smallest square possible.

## Instalation and Usage

Compile project with **make**:

```
make
```

You will get an executable **fillit**, which takes a file, containing the list of tetriminos, as an argument.

Valid Tetrimino is:
* 4 x 4 block, containing empty cells - **'.'**, and filled cells - **'#'**;
* it has only 4 filled cells, each of which touches at least one other filled cell with it side (up, down, left, right);
* in the file, Tetriminos are divided by only one newline character;

The position of the figure in block does not matter:

```
.##.             ....
.##.  equals to  ....
....             ..##
....             ..##
```

Example of valid file:

```
cat -e valid.tetr
...#$
...#$
..##$
....$
$
....$
.##.$
.##.$
....$
```

Example of invalid file:

```
cat -e invalid.tetr
...#$
.###$
....$
.#..$
$
$
...$
...#$
...#$
..##$
```

Result is printed using latin capital letters, so the amount of Tetriminos is limited by **26 pieces**:

```
AABB
.ABB
.A..
CCCC
```
