## Push Swap

Push_swap is a optimized sorting game. The game consists of 2 stacks A and B,<br>
at the start of the game there are a random amount of different values in stack A,<br>
the goal is to sort stack A with a small set of instructions, with the least moves possible.<br>

The algorithm is quite simple, I will use an example of A stack with 1-10 values in random order.<br>
First I split A stack into half according to values. (10 / 2)<br>
Then I move the lowest values (1-5) to B stack and any higher values (6-10) move them to the bottom of A stack.<br>
When all lower values are moved to B stack I split B (5 / 2) stack and move the highest (4-5)<br>
on top of A stack and the lowest (1-3) to the bottom of A stack in ascending order, until B stack is empty.<br>
Then split the values that are not in order in A stack in half repeated the cycle.<br>
```
I have the following operations at my disposal:
	sa : swap a - swap the first 2 elements at the top of stack a.
	sb : swap b - swap the first 2 elements at the top of stack b.
	ss : sa and sb at the same time.
	pa : push a - take the first element at the top of b and put it at the top of a.
	pb : push b - take the first element at the top of a and put it at the top of b.
	ra : rotate a - shift up all elements of stack a by 1. The first element becomes
			the last one.
	rb : rotate b - shift up all elements of stack b by 1. The first element becomes
			the last one.
	rr : ra and rb at the same time.
	rra : reverse rotate a - shift down all elements of stack a by 1. The last element
			becomes the first one.
	rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
			becomes the first one.
	rrr : rra and rrb at the same time
```
A much simpler algorithm is used in situation with less than 10 values.

------

## Checker
Checker is a program that checks if the value given are correct and if push_swap sorted them correctly.

-----
## Visualizer (only for mac)
Visualizes the individual moves taken to sort stack A.
 *	P - pause/unpause
 *	F - One move forwards, must be paused
 *	R	- Reverse one move, must be paused.
-------
<img src=/images/output.gif width="400"><rb>
## Use
```sh
git clone https://github.com/Epicurius/push_swap.git
cd push_swap && make

# Run (5,100,200,300 ... 700) random digit order tests and check if valid.
./test.sh

# Run visualizer with 300 random digits
# P - pause/unpause
# F - One move forwards, must be paused
# R	- Reverse one move, must be paused.
./show.sh

# Run normal
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG
# OR
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
```

5 values <12 moves <br>
100 values 670 moves +-20 <br>
500 values 5500 moves +-100 <br>
<img src=/images/checker.png width="700">


