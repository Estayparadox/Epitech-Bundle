[BITS 64]
	section .text
	global strcasecmp:function
	global casecmp
casecmp:
	cmp dil, 65
	jl return
	cmp dil, 90
	jg return
	add dil, 32
return:
	ret

isend:
	cmp bl, 0
	jne loop
	mov rax, 0
	ret

strcasecmp:
	xor rcx, rcx			; i = 0
	mov rdx, rdi			; save str1
	jmp check
loop:
	inc rcx				; i++
check:
	mov bl, byte [rdx + rcx]	; put str1[i] in rbx's first 8bits
	mov dil, bl
	call casecmp			; if (str1[i] >= 'a' && str1[i] <= 'z');
	mov bl, dil
	mov al, byte [rsi + rcx]	; put str2[i] in rax's first 8bits
	mov dil, al
	call casecmp			; if (str2[i] >= 'a' && str2[i] <= 'z');
	mov al, dil
case:
	cmp bl, al			; if (str1[i] == str2[i])
	je isend
which:
	xor rax, rax			; clean bits in rax
	xor rbx, rbx			; clean bits in rbx
	mov al, byte [rdx + rcx]	; put str1[i] in rax's first 8 bits
	mov dil, al
	call casecmp			; if (str1[i] >= 'a' && str1[i] <= 'z');
	mov al, dil
	mov bl, byte [rsi + rcx]	; put str2[i] in rbx's first 8 bits
	mov dil, bl
	call casecmp			; if (str2[i] >= 'a' && str2[i] <= 'z');
	mov bl, dil
	sub rax, rbx			; str1[i] -= str2[i]
	ret
