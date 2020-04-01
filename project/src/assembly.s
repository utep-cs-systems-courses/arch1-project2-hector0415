	.arch msp430g2553
	.p2align 1,0

	.data
	
	
	.text
	
jt:	.word case_zero
	.word case_one
	.word case_two
	.word case_three


	.global state_one
state_one:
	mov.b #1, &red_on
	mov.b #0, &green_on
	ret

	.global state_two
state_two:
	mov &state_counter_two, r12
	add r12, r12
	mov jt(r12), r0

case_zero:
	call #state_two_zero
	jmp exit
	
case_one:
	call #state_two_one
	jmp exit
	
case_two:
	call #state_two_two
	jmp exit
	
case_three:	
	call #state_two_three
	jmp exit

exit:	
	ret
	
	.global state_four
state_four:
	mov.b #1, &red_on
	mov.b #1, &green_on
	ret
