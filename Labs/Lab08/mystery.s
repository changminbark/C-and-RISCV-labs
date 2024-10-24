# "CSCI 206: Computer Organization" has been renamed and renumbered a "CSCI 306:
# Computer Systems" with proper update. The following exercises are adapted as 
# they are in CSCI 306.
# Date: 2023-06-04
#
# CSCI 206 Computer Organization & Programming
# Date: 2019-10-26
# Copyright (c) 2019 Bucknell University
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
# Student name: Chang Min Bark


	.data				# This tells the simulator the following section
					# initializes declared variables
	
unused:	.word 0xFEEDBEEF		# This intiailizes the unused variable	
						
x:	.word 89			# This initializes the x variable to the value of 89	
						
	.text				# This tells the simulator the following section is the code
main:					# This tells the simulator
						# where start your program

	
	add		t0, zero, zero		# This sets the t0 value to zero (initialization)
	add		s2, zero, zero		# This sets the s2 value to zero (initialization)

loop:						# This loop iterates for 11 cycles because the counter of t3 increments by 1 until it reaches 1
	add		s2, s2, t0		# This adds the value of t0 to s2 every iteration, which is summing the counter values and saving it to s2.
	addi	t0, t0, 1			# This adds 1 to t0 with every iteration. This is kind of like the counter in a for loop
	addi	t3, t0, -10			# This sets t3 to t0 - 10 in every iteration. This variable is also like a counter, but modifiedso that the next line can use blez.
	blez	t3, loop			# This branches back to the start of loop if t3 <= 0

	la		t2, x			# This loads the address of x into t2
	sw		s2, 0(t2)		# This saves the value of s2 at the base address of x (in t2)
	
	add		a0, zero, s2		# Move result into a0 for return code
	li		a7, 93			# Code (93) for system call Exit2
	ecall					# Exit!
	ebreak					# Break if something went wrong (should not get here!)

# This code adds up all integers from 0 to 10 and stores it at the base address of x.
