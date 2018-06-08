include \masm32\include\masm32rt.inc
;sound
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code
stop proc
	mov ebx, offset dinod
	pusha
	xor eax,eax
	
	mov [ebx+DRCY],eax
	popa

ret
stop endp

Key_pressed_space proc 
mov ebx, edi
add ebx, SPACE_OFST
invoke GetAsyncKeyState,[ebx] ;throw to eax 1 if key pressed
cmp eax, 0
jne jumpfunc
ret
jumpfunc:
invoke PlaySound,offset jump_sound,NULL,SND_ASYNC
mov ecx,JUMPING
mov [edi+isJump_adr], ecx

ret
Key_pressed_space endp

jump proc adrObj:DWORD

	mov edi, adrObj
	mov ecx, JUMPING
	cmp [edi+isJump_adr],ecx  
	jne dontjump
	xor edx,edx
	mov eax, JUMP_POWER
	mov [edi+JUMP_LVL_OFST], eax
	mov ebx, 2	
	div ebx 
	mov ebx, [edi+JUMP_LVL_OFST]
	cmp eax, ebx
	jl jumpp
	jg drop
	jumpp:
	mov ecx, 1
	sub [edi + DINO_Y_OFST], ecx
	sub [edi+JUMP_LVL_OFST], ecx
	ret
	drop:
	mov ecx, 1
	add [edi + DINO_Y_OFST], ecx
	sub [edi+JUMP_LVL_OFST], ecx
	mov ecx, [edi+JUMP_LVL_OFST]
	cmp ecx, 0
	je dontjump
	ret

	
dontjump:
mov ecx, STANDING
mov [edi+isJump_adr], ecx
ret
jump endp

modulu proc first:DWORD, sec:DWORD ; returns x%y
xor edx, edx
mov eax,first
div sec
mov eax,edx ; eax contains the value of x%y
ret
modulu endp

