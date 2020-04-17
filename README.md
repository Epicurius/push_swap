## Push_swap
Push_swap is a optimized sorting game. The game consists of 2 stacks A and B,
at the start of the game there are a random amount of different values in stack A,
the goal is to sort stack A with a small set of instructions, with the least moves possible.

## Checker
Checker is a program that checks if the value given are correct and if push_swap sorted them correctly.

## Visulaizer (only for mac)
Visualizes the individual moves taken to sort stack A.
Press space to see the next move.

## Use
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./visualizer/visualizer $ARG

5 values <12 moves |
100 values 670 moves +-20 |
500 values 5500 moves +-100 |
