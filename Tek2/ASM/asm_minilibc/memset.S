[BITS 64]

section .text
	global memset

memset:
	
	push	ebp
	mov	ebp, esp
	push	ebx
	push	ecx

	mov	eax, [ebp + 8]
	mov	ebx, [ebp + 12]
	mov	ecx, [ebp + 16]

my_loop:	

	cmp 	ecx, 0
	je 	go_out

	mov 	[eax], bl
	dec 	ecx
	inc	eax
	jmp 	my_loop

go_out:
	
	mov	eax, [ebp + 8]

	pop ecx
	pop ebx

	leave
	ret
