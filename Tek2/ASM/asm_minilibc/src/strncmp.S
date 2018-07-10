[BITS 64]
	section .text
	global strncmp:function

strncmp:
	xor rcx, rcx			; i = 0
	jmp check
loop:
	inc rcx				; i++
check:
	mov bl, byte [rdi + rcx]	; put str1[i] in rbx's first 8bits
	mov al, byte [rsi + rcx]	; put str2[i] in rax's first 8bits
	cmp bl, al			; if (str1[i] == str2[i])
	jne end
	cmp rdx, rcx			; if (i < n)
	jg loop
end:
	cmp rdx, rcx			; if (i == n)
	jne which
	mov eax, 0			; load 0 in return value
	ret
which:
	xor rax, rax			; clean bits in rax
	xor rbx, rbx			; clean bits in rbx
	mov al, byte [rdi + rcx]	; put str1[i] in rax's first 8 bits
	mov bl, byte [rsi + rcx]	; put str2[i] in rbx's first 8 bits
	sub rax, rbx			; str1[i] -= str2[i]
	ret
