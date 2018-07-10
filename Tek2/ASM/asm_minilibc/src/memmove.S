[BITS 64]
	section .text
	extern malloc
	extern free
	global memmove:function
memmove:
	push rbp
	mov rbp, rsp

	push rdi			; save ptr1
	push rsi			; save ptr2
	push rdx			; save n

	mov rdi, rdx			; load n for malloc
	call malloc wrt ..plt		; tmp = malloc(n * sizeof(char))
	mov r11, rax			; save tmp
	cmp r11, 0			; if (!tmp)
	je error

	pop rdx				; restore n
	pop rsi				; restore ptr2
	pop rdi				; restore ptr1

	xor rcx, rcx			; i = 0
	jmp check
loop:
	mov al, byte [rsi + rcx]
	mov byte [r11 + rcx], al	; s[i] = ((char *)ptr2)[i]
	inc rcx				; i++
check:
	cmp rdx, rcx			; if (i < n)
	jg loop
	xor rcx, rcx			; i = 0
	jmp check2
loop2:
	mov al, byte [r11 + rcx]
	mov byte [rdi + rcx], al	; ((char *)ptr)[i] = s[i]
	inc rcx				; i++
check2:
	cmp rdx, rcx			; if (i < n)
	jg loop2
end:
	mov rax, rdi			; return (ptr)
	push rax			; save ptr
	mov rdi, r11			; prepare free
	call free wrt ..plt		; free(tmp)
	pop rax				; restore ptr
	leave
	ret
error:
	xor rax, rax			; return NULL
	leave
	ret
