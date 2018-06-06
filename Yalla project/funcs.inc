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

Key_pressed_space proc KeyOfst:DWORD
mov ebx, edi
add ebx, KeyOfst
invoke GetAsyncKeyState,[ebx] ;throw to eax 1 if key pressed
cmp eax, 0
jne jumpfunc
ret
jumpfunc:
mov ecx,JUMPING
mov [edi+isJump_adr], ecx

ret
Key_pressed_space endp

jump proc adrObj:DWORD

mov edi, adrObj
	mov ecx, JUMPING
	cmp [edi+isJump_adr],ecx 
	jne dontjump
	mov eax, [edi+JUMP_LVL_OFST]
	sub [edi + DINO_Y_OFST], eax ; jump up mf
	mov eax,1; drop down mf
	sub [edi+JUMP_LVL_OFST], eax
	
invoke PlaySound,offset jump_sound,NULL,SND_ASYNC
dontjump:
	
	

ret
jump endp