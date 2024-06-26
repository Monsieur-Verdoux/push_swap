# push_swap

This project is an implementation of a sorting algorithm that takes a list of unique integers and uses two stacks to sort them using a given list of instructions. The goal is to sort the numbers efficiently, not exceeding the limits 

Allowed instructions:

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
- ss : sa and sb at the same time
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one
- rr : ra and rb at the same time
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one
- rrr : rra and rrb at the same time

Limits:

- 5 integers: 12 moves
- 100 integers: 700 moves
- 500 integers: 5500 moves

## example

```
./push_swap 2 4 23 6 -1 501 -365
pb
pb
pb
rra
pb
sa
rb
rra
pa
rra
pa
pa
rra
pa
