[BITS 64]
	global strcspn:function
	section .text

end:
	mov rax, rcx		; initialize rax with the value of rcx
	ret

count:
	inc rcx			; increment rcx (for the return value)
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

	cmp dl, 0		; if dl == '\0'
	jz end			; then end
	jmp check_count		; else loop with the second argument

strcspn:
	xor rcx, rcx
	xor r9, r9
	xor bl, bl
	xor dl, dl
	jmp first_loop
