# "CSCI 206: Computer Organization" has been renamed and renumbered a "CSCI 306:
# Computer Systems" with proper update. The following exercises are adapted as 
# they are in CSCI 306.
# Date: 2023-06-04
#
# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
# Revised: 2019-10-31 for RISC-V
#
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and
# supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Student name:
#
# This program calculates the sum of the values in array A and counts
# the number of values in the array.
#
# Similarly to a C-string, the array is terminated by sentinel value
# equal to zero.
#
# The sum is stored in $s0 and the count in $s1

	.data
A:	.word 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 0 # declare array int A[]={5,4,3,2,4,1,0};

    .globl main
	.text	
main:				# This symbols marks the first instruction of your program

#
# Add your code here
#
	add s0, zero, zero	# sum
	add t0, zero, zero	# counter
	la t1, A		# address of array
	
loop:

	lw t2, 0(t1)		# load value in array to t2
	beqz t2, end		# if value in t2 is 0, branch to end
	add s0, s0, t2		# add value in t2 to s0, which is the sum
	addi t0, t0, 1		# add 1 to the counter register t0
	addi t1, t1, 4		# add 4 (size of int) to address register t1
	j loop			# jump to start of loop if not sentinel value
	
	
end:
	add a0, t0, zero	# save the counter value into a0
	add a1, s0, zero	# save the sum value into a1
	
	li	a7, 10		# system call for exit. 

	ecall			# Exit!
	ebreak
	
# If we want to print, we can use system calls 
# github.com/scotws/RISC-V-tests/blob/master/docs/riscv_howto_syscalls.md
