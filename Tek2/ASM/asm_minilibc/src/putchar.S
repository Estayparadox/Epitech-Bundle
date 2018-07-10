[BITS 64]
	section .text
	global putchar:function
	extern write
putchar:
	push rbp
	mov rbp, rsp

	mov byte [rsp + 4], dil
	lea rsi, [rsp + 4]
	mov rdi, 1
	mov rdx, 1
	call write wrt ..plt

	mov rsp, rbp
	pop rbp

	ret
