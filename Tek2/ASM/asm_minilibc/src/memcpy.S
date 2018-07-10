[BITS 64]
	section .text
	global memcpy:function
memcpy:
	xor rcx, rcx			; i = 0
	jmp check
loop:
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al 	; ((char *)ptr)[i] = ((char *)ptr2)[i]
	inc rcx				; i++
check:
	cmp rdx, rcx			; if (i < n)
	jg loop
end:
	mov rax, rdi			; return (ptr)
	ret
