[BITS 64]
	global strcmp:function
	section .text

end:
	mov al, bl		; store bl in al
	sub al, cl		; al = al - cl (difference between two chars)
	movsx rax, al		; move the result of al in rax (increase the size of al to store it in the register
	ret



loop:
	mov bl, byte[rdi]		; store first char of first argument in bl
	mov cl, byte[rsi]		; store first char of second argument in bl

	cmp bl, 0		; if first char of first argument == '\0'
	jz end			; end the function
	cmp cl, 0		; if first char of second argument == '\0'
	jz end			; end the function

	cmp bl, cl		; if first char of first argument != first char of second argument
	jne end			; end the function

	inc rdi			; get next char
	inc rsi			; get next char

	jmp loop		; loop again


strcmp:
	xor rax, rax		; return_value = 0
	xor rbx, rbx		; initialize first argument
	xor rcx, rcx		; initialize second argument

	xor rdx, rdx

	xor al, al		; initialize result char
	xor bl, bl		; initialize first char of first argument
	xor cl, cl		; initialize first char of second argument

	jmp loop
