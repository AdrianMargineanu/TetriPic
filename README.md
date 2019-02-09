# TetriPic (work in progress)

### General Idea
This program is a Tretris game.The output of the game is a bmp file that contains the final map of the game. Every piece has a diferent color:
+ 'I' is blue
+ 'O' is yellow
+ 'J' is pink
+ 'L' is orange
+ 'S' is red
+ 'Z' is green
+ 'T' is purple
The main map is black, with some white lines.

### Input 
The input of the program is a file with the name "Moves.in", where is written how many moves do you have,what the height and width  of the map is, what piece do you want, what rotation it has and in what collomn it will fall.

### How does it work?
The program creates a matrix that is empty. For every move it creats the piece wich is placed on the map. Then the program is looking for full lines, using the same operation. If there is such a line, it will get removed and all the ones above will fall one space.

### Output 
The output of the program is a bmp file that is the final map of the game.

### Authors
Margineanu Adrian
