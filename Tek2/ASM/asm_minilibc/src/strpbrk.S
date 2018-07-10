[BITS 64]
	global strpbrk:function
	section .text

instant_end:
	mov rax, 0
	ret

end:
	cmp byte[rsi], 0	; if the char's address of rsi == '\0'
	jz instant_end		; leave with ptr = NULL
	cmp rcx, 0		; else if counter == 0
	jz instant_end		; leave with ptr
	mov rax, rdi		; else, initialize rax with the address of rdi
	ret

count:
	inc rdi			; increment the address of the first argument
	jmp first_loop		; jump on the first loop

second_loop:
	mov bl, byte[r9]	; initialize bl with the converted value of r9

	cmp bl, 0		; if bl == '\0'
	jz count		; jump on count
	cmp bl, dl		; if bl == dl
	je end			; end

	inc r9			; increment the address of r9
	jmp second_loop		; loop again on second_loop

check_count:
	mov r9, rsi		; initialize r9 (tmp) with rsi
	jmp second_loop		; jump on second loop

first_loop:
	mov dl, byte[rdi]	; initialize the 8bit register with the converted value of rdi (64 bits)
	xor bl, bl

	cmp dl, 0		; if dl == '\0'
	jz instant_end		; then end
	inc rcx
	jmp check_count		; else loop with the second argument

strpbrk:
	xor rcx, rcx
	xor r9, r9
	xor bl, bl
	xor dl, dl

	cmp rdi, 0
	jz instant_end
	cmp rsi, 0
	jz instant_end
	
	jmp first_loop
