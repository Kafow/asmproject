include \masm32\include\masm32rt.inc
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code
Key_pressed proc KeyOfst:DWORD
mov ebx, eax
add ebx, KeyOfst

invoke GetAsyncKeyState,[ebx] ;throw to eax if sapce is pressed (value won't be zero)
ret
Key_pressed endp
jump proc adrObj:DWORD
mov eax, adrObj
mov edi, adrObj
invoke Key_pressed, SPACE_OFST
cmp eax,0
jne doJump
ret
doJump:
	
	mov ecx,JUMPING
	mov [edi+isJump_adr], ecx
	invoke PlaySound,offset jump_sound,NULL,SND_ASYNC

ret
jump endp