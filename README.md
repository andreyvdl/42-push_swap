<div align="center">
  <img src="https://github.com/gawbsouza/42-pdh/blob/main/dark/push_swap_dark.svg"><br>
  <a href="https://github.com/gawbsouza/42-pdh"><img src="https://github.com/gawbsouza/42-pdh/blob/main/badge/42pdh_badge.svg"></a>
</div>

___
Program name | Files to turn in | Makefile rules | External functions | Result
:---: | :---: | :---: | :---: | :---:
push_swap (checker) | Makefile, \*.h, \*.c (\*.h, \*.c) | NAME, all, clean, fclean, re (bonus) | read, write, malloc, free, exit, libft | 0/80%

## Objective

> The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity.   
> Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Execution

```sh
make
./push_swap <num1> <num2> <num3> ... <numx>
```
or
```sh
make
ARG=$(seq <numi> <numf> | shuf) && ./push_swap $ARG
```

