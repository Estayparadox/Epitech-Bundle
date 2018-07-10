[BITS 64]
	global strchr:function
	section .text

null:
	mov rax, 0
	ret

check_null:
	cmp rsi, 0
	jnz null
	mov rax, rdi
	ret
	
end:
	cmp al, 0
	jz check_null
	mov rax, rdi	 	; give to the return value the address of the char (rdi)
	ret

instant_end:
	mov rax, 0
	ret

loop:
	mov al, byte[rdi]	; attribute the char of char * (rdi) to a 8-bit register
	movsx rdx, al		; attribute the value of 8 bit register to a new bigger (64 bits) register (increase size)

	cmp al, 0		; check if the character != '\0'
	jz end			; if true, then end
	cmp rdx, rsi		; check if the character of the first argument == the second argument
	je end			; if true, then end

	inc rdi			; increment the address of the char ptr
	inc rdx
	inc rcx

	jmp loop		; loop again

strchr:
	xor rax, rax		; return value = 0
	xor rcx, rcx
	cmp rdi, 0
	jz instant_end
	jmp loop		; loop
