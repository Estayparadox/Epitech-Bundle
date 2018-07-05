[BITS 64]
	
section .text
	
	global strlen

strlen:
	
	push	ebp			; push le contenue du bas de la pile sur la pile 
	mov	ebp, esp		; le bas de la pile = le haut de la pile 
	push	ebx
	push	ecx
	
	mov	ebx, [ebp + 8]		; ebx = haut de pile + 8o
	mov	eax, 0 
	
count_char:

	mov	cl, [ebx + eax]
	cmp 	cl, 0
	jne	more
	
	pop	ecx
	pop	ebx

	leave
	ret

more:

	inc	eax
	jmp	count_char
