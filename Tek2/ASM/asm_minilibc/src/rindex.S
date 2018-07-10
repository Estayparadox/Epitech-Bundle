[BITS 64]
	global rindex:function
	section .text

eos:
	mov rax, rdi
	ret

return_eos:
	cmp bl, 0
	jz eos
	mov bl, byte[rdi]
	cmp bl, 0
	jz eos
	inc rdi
	jmp return_eos

end:
	cmp cl, 0
	jz return_eos
	mov rax, rdx		; return value = saved value
	ret

instant_end:
	mov rax, 0
	ret

store_addr:
	xor rdx, rdx		; initialize rdx at 0
	mov rdx, rdi		; put the address of rdi in rdx in order to save the occurence
	inc rdi			; increment the address of rdi
	jmp loop		; re-jmp on loop

loop:
	mov bl, byte[rdi]	; initialize the 8-bit register with the first arg's char

	mov cl, sil		; initialize the 8-bit register with the 8-bit value of rsi

	cmp bl, 0		; compare if bl == '\0'
	jz end			; if true, then jmp
	cmp cl, 0		; else if cl == '\0'
	jz end			; if true, then jmp
	cmp bl, cl		; else if bl == cl
	je store_addr		; jmp to save the address

	inc rdi			; increment the address of the first argument
	jmp loop

rindex:
	xor bl, bl
	xor cl, cl
	xor rax, rax
	xor rdx, rdx

	cmp rdi, 0
	jz instant_end

	jmp loop
