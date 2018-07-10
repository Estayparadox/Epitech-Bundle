[BITS 64]
	section .text
	global putstr:function
	extern write

len:
	mov rbx, rdi
	xor rax, rax
	jmp check
loop:
	inc rax
check:
	cmp byte [rbx + rax], 0
	jnz loop
	ret

putstr:
	test rdi, rdi
	jz retu
	call len
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	call write wrt ..plt
retu:
	ret
