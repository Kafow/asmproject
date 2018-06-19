;drd funcs

include funcs.inc
include Little_funcs.inc


;sound 
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code 
init proc ;openning the window and loading the files
invoke drd_init,1200,800,0
invoke drd_imageLoadFile,offset dino, offset res.dino
invoke drd_imageLoadFile,offset dinof, offset res.dinof
invoke drd_imageLoadFile,offset dinoUP, offset res.dinoUP
invoke drd_imageLoadFile,offset dinoDOWN, offset res.dinoDOWN
invoke drd_imageLoadFile,offset background, offset res.background
invoke drd_imageLoadFile,offset cactus1, offset res.cactus
invoke drd_imageLoadFile,offset gameover, offset res.gameover
invoke drd_imageLoadFile,offset restarttt, offset res.restarttt
invoke drd_imageSetTransparent, offset res.cactus, 0ffffffh
invoke drd_imageSetTransparent, offset res.dino, 0ffffffh
invoke drd_imageSetTransparent, offset res.dinof, 00000000h
invoke drd_imageSetTransparent, offset res.dinoDOWN, 0ffffffh
invoke drd_imageSetTransparent, offset res.dinoUP, 0ffffffh
invoke drd_imageSetTransparent, offset res.gameover, 0ffffffh
invoke drd_imageSetTransparent, offset res.restarttt, 0ffffffh



ret
init endp


draw proc ;drawing the things based on the game situation
mov eax, dinod.isAlive
cmp eax, 0
je col
invoke drd_pixelsClear ,0
invoke drd_imageDrawCrop, offset res.background ,0,0,x,0,w,h
invoke drd_imageDrawCrop, offset res.background ,w,0,0,0,x,h
invoke drd_imageDraw, offset res.cactus, michsol.pos.x, michsol.pos.y
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



Draw1:

invoke drd_imageDraw,offset res.dinoUP, dinod.pos.x, dinod.pos.y
jmp flip

Draw2:
invoke drd_imageDraw,offset res.dinoDOWN, dinod.pos.x, dinod.pos.y
jmp flip

drawnet:
invoke drd_imageDraw,offset res.dino, dinod.pos.x, dinod.pos.y
jmp flip

flip:
invoke drd_flip


ret
col:
;invoke drd_imageDelete, offset res.dinoUP
;invoke drd_imageDelete, offset res.dinoDOWN
invoke drd_imageDraw, offset res.gameover, 400, 200
invoke drd_imageDraw, offset res.restarttt, 551, 280
invoke drd_imageDraw, offset res.dinof, dinod.pos.x, dinod.pos.y
invoke drd_flip
ret
draw endp


update proc ;updating the game funcs in loop and delay the project
mov eax, dinod.isAlive
cmp eax, 0
je coll
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
invoke calcCenterCactus ,offset michsol
invoke setCactusPos, offset michsol
invoke Key_pressed_space
invoke jump, offset dinod
invoke collision, offset dinod,offset michsol
invoke CalculateDistance2
invoke drd_setWindowTitle, offset distance
invoke drd_processMessages
ret



do_again:
mov x,0 
mov w,1200
jmp returnoush
coll:
invoke drd_processMessages
ret

update endp

restart proc adrObj:DWORD ; restarts the values and game
mov ebx, DEAD
mov ecx, adrObj
cmp [ecx+ 24], ebx
je checkifrestart
ret
checkifrestart:

invoke GetAsyncKeyState, VK_SPACE
cmp eax, 0

jne restartt
ret
restartt:
mov ecx, adrObj
mov ebx, ALIVE
mov [ecx+ 24], ebx
mov ebx, 1200 - dinoRad
mov michsol.pos.x, ebx

ret
restart endp
