[BITS 64]
	section .text
	global strlen:function
strlen:
	mov rbx, rdi		; move char * in register
	xor rax, rax		; reinit iterator
	jmp check
loop:
	inc rax			; i++
check:
	cmp byte [rbx + rax], 0	; if (str[i])
	jnz loop
	ret			; return (i)
