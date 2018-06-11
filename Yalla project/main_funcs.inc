;drd funcs

include funcs.inc
include Little_funcs.inc


;sound 
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code 
init proc
invoke drd_init,1200,800,0
invoke drd_imageLoadFile,offset dino, offset res.dino
invoke drd_imageLoadFile,offset dinoUP, offset res.dinoUP
invoke drd_imageLoadFile,offset dinoDOWN, offset res.dinoDOWN
invoke drd_imageLoadFile,offset background, offset res.background
invoke drd_imageLoadFile,offset cactus1, offset res.cactus
invoke drd_imageSetTransparent, offset res.cactus, 0ffffffh
invoke drd_imageSetTransparent, offset res.dino, 0ffffffh
invoke drd_imageSetTransparent, offset res.dinoDOWN, 0ffffffh
invoke drd_imageSetTransparent, offset res.dinoUP, 0ffffffh


ret
init endp


draw proc
invoke drd_pixelsClear ,0
invoke drd_imageDrawCrop, offset res.background ,0,0,x,0,w,h
invoke drd_imageDrawCrop, offset res.background ,w,0,0,0,x,h
;invoke drd_imageDraw, offset res.cactus, 250,450
;invoke drd_imageDraw,offset res.background, 0, 0
;invoke drd_imageDraw,offset res.dino, dinod.pos.x, dinod.pos.y
invoke DinoDraw
mov ecx, DinoDrawC
mov ebx, dinod.isJump
cmp ebx, 1
je drawnet

cmp ecx, 0
je Draw1
jne Draw2

flip:
invoke drd_flip
ret

Draw1:

invoke drd_imageDraw,offset res.dinoUP, dinod.pos.x, dinod.pos.y
jmp flip

Draw2:
invoke drd_imageDraw,offset res.dinoDOWN, dinod.pos.x, dinod.pos.y
jmp flip

drawnet:
invoke drd_imageDraw,offset res.dino, dinod.pos.x, dinod.pos.y
jmp flip

draw endp


update proc
;;;;;;;delay the project;;;;;;;;;
inc count
mov eax, count 
invoke modulu, eax, SPEED
cmp eax , 0
je do_func
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;delay the jump;;;;;;;;;;;
mov eax, count
invoke modulu, eax, Jump_speed
cmp eax, 0
je returnoush
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
do_func:
;invoke CalculateDistance; not finished, need to fix
inc x
dec w
cmp x,1200

je do_again
returnoush:

invoke calcCenterDino
invoke Key_pressed_space
invoke jump, offset dinod

invoke drd_processMessages
ret



do_again:
mov x,0
mov w,1200
jmp returnoush

update endp
