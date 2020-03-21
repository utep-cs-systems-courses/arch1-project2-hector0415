	.arch msp430g2553

	.text
	.global state_one
state_one:
	mov.b #1, &red_on
	mov.b #0, &green_on
	ret

	.global state_four
state_four:
	mov.b #1, &red_on
	mov.b #1, &green_on
	ret
