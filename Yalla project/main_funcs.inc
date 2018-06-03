;drd funcs
include drd.inc
includelib drd.lib
;sound 
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code 
init proc
invoke drd_init,1200,800,0
invoke drd_imageLoadFile,offset dino, offset dinod.info
invoke drd_imageSetTransparent, offset dinod.info, 0ffffffh
invoke PlaySound,offset score,NULL,SND_ASYNC
ret
init endp

