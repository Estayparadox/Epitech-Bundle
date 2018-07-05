[BITS 64]

section.text
	
	global	strchr
	
strchr:
	push	rbp
	mov	rbp, rsp

	push	rdi

my_loop:
	cmp	BYTE [rdi], sil
	jz	isnt_empty
	cmp	BYTE [rdi], 0
	jz	is_empty
	inc	rdi
	jmp	my_loop

isnt_empty: mov 	rax, rdi

is_empty:
	mov	rax, 0
	jmp	end

go_out:
	pop     rdi
	mov     rsp, rbp
	pop     rbp
	  
	ret
	
