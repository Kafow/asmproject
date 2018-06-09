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
ret
DinoDraw endp