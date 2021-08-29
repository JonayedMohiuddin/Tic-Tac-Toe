# TIC-TAC-TOE
An implementation of `minimax` algorithom on classic tic tac toe game making it `UNBEATABLE`. Give it a try ;). Minimax is a recursive algorithm which simulates every move as both opponent first and choses the best move which saves AI from losing.

## HOW TO PLAY
__HUMAN PLAYER__ is denoted as `X` on the board and __AI PLAYER__ is denoted as `O` on the board.</br>
If you want to play fist then just type y on the prompt.If not then type n.</br>
The configuration of board is:
```
+-----+-----+-----+
|  1  |  2  |  3  |
+-----+-----+-----+
|  4  |  5  |  6  |
+-----+-----+-----+
|  7  |  8  |  9  |
+-----+-----+-----+
```
Just type the number and press enter where you want to place your move `X`.</br>
AI will play automatically after your move.

## DEMO :
```
####################
# TIC TAC TOE A.I. #
####################

+-----+-----+-----+
|  1  |  2  |  3  |
+-----+-----+-----+
|  4  |  5  |  6  |
+-----+-----+-----+
|  7  |  8  |  9  |
+-----+-----+-----+

## Do you want to go first? (Y/N) : y

## Where do you want to place (X)? (1-9) : 5

+-----+-----+-----+
|     |     |     |
+-----+-----+-----+
|     |  X  |     |
+-----+-----+-----+
|     |     |     |
+-----+-----+-----+

$$ My turn :

+-----+-----+-----+
|  O  |     |     |
+-----+-----+-----+
|     |  X  |     |
+-----+-----+-----+
|     |     |     |
+-----+-----+-----+

## Where do you want to place (X)? (1-9) : 3

+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+
|     |  X  |     |
+-----+-----+-----+
|     |     |     |
+-----+-----+-----+

$$ My turn :

+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+
|     |  X  |     |
+-----+-----+-----+
|  O  |     |     |
+-----+-----+-----+

## Where do you want to place (X)? (1-9) : 4

+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+
|  X  |  X  |     |
+-----+-----+-----+
|  O  |     |     |
+-----+-----+-----+

$$ My turn :

+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+
|  X  |  X  |  O  |
+-----+-----+-----+
|  O  |     |     |
+-----+-----+-----+

## Where do you want to place (X)? (1-9) : 9

+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+
|  X  |  X  |  O  |
+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+

$$ My turn :

+-----+-----+-----+
|  O  |  O  |  X  |
+-----+-----+-----+
|  X  |  X  |  O  |
+-----+-----+-----+
|  O  |     |  X  |
+-----+-----+-----+

## Where do you want to place (X)? (1-9) : 8

+-----+-----+-----+
|  O  |  O  |  X  |
+-----+-----+-----+
|  X  |  X  |  O  |
+-----+-----+-----+
|  O  |  X  |  X  |
+-----+-----+-----+

== This match was a TIE. I will see you next time.
```
