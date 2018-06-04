;drd funcs
include drd.inc
includelib drd.lib

;sound 
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code 
init proc
invoke drd_init,1200,800,0
invoke drd_imageLoadFile,offset dino, offset res.dino
invoke drd_imageLoadFile,offset background, offset res.background
invoke drd_imageSetTransparent, offset res.dino, 0ffffffh
invoke PlaySound,offset score,NULL,SND_ASYNC
ret
init endp
draw proc
invoke drd_pixelsClear ,0
invoke drd_imageDraw,offset res.background, 0, 0
invoke drd_imageDraw,offset res.dino, dinod.pos.x, dinod.pos.y
invoke drd_flip
ret
draw endp
update proc
invoke drd_processMessages
ret
update endp
