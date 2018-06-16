.686
.code 
modulu proc first:DWORD, sec:DWORD ; returns x%y
xor edx, edx
mov eax,first
div sec
mov eax,edx ; eax contains the value of x%y
ret
modulu endp
DinoDraw proc
inc DinoDraww
mov eax, DinoDraww
mov ebx, 25
invoke modulu, eax, ebx
cmp eax, 0
je change
ret
change:
mov eax, 0
mov ebx, 1
mov ecx, DinoDrawC
cmp ecx, ebx
je ChangeToZero
cmp ecx, eax
je ChangeToOne
ChangeToZero:
mov DinoDrawC, eax
ret
ChangeToOne:
mov DinoDrawC, ebx
ret
DinoDraw endp
calcCenterDino proc
mov eax, offset dinod
mov ebx, [eax + dinoRad_OFST]
mov ecx, [eax + DINO_X_OFST]
add ecx, ebx
mov [eax + dinoCenter_X_OFST], ecx
mov ecx, [eax + DINO_Y_OFST]
add ecx, ebx
mov [eax + dinoCenter_Y_OFST], ecx
ret
calcCenterDino endp

calcCenterCactus proc adrObj:DWORD
mov eax, adrObj
mov ebx, [eax + CactusRad_OFST]
mov ecx, [eax + Cactus_X_OFST]
add ecx, ebx
mov [eax + CactusCenter_X_OFST], ecx
mov ecx, [eax + Cactus_Y_OFST]
add ecx, ebx
mov [eax + CactusCenter_Y_OFST], ecx
ret
calcCenterCactus endp

Random proc max:dword;return a random number in eax between 0 and max
    Rdrand eax
    Xor edx,edx
    div max
    mov eax,edx
    ret 
Random endp

setCactusPos proc adrObj:DWORD
mov eax, count 
invoke modulu, eax, SPEED
cmp eax , 0
je do_funcc
ret
do_funcc:
mov eax, adrObj
mov ebx, 1

sub [eax + Cactus_X_OFST], ebx
mov ecx,[eax + Cactus_X_OFST]
cmp ecx, 0
je NotONScreen
ret
NotONScreen:
mov ebx, 0
mov [eax + 20 ], ebx
mov ebx, 1200-dinoRad
mov [eax + Cactus_X_OFST], ebx
ret
setCactusPos endp

IsDrawCactus proc 


invoke Random, 500
invoke modulu, eax, 43
cmp eax, 0
je tell_to_active
ret
tell_to_active:
mov eax, 1
mov CactusDraw, eax

ret
IsDrawCactus endp

collision proc
ret
collision endp