include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
;include main_funcs.inc

;sound
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code

main proc
invoke drd_init,1200,800,0
invoke drd_imageLoadFile,offset dino, offset dinod.info
invoke drd_imageSetTransparent, offset dinod.info, 0ffffffh
;invoke Playsound,offset score,null,SND_ASYNC
loopa:
invoke drd_pixelsClear ,0
invoke drd_imageDraw,offset dinod.info, dinod.pos.x, dinod.pos.y
invoke drd_flip
invoke drd_processMessages
jmp loopa
ret
main endp
end main