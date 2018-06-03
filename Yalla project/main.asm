include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
include main_funcs.inc
;sound
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code

main proc
invoke init
loopa:
invoke drd_pixelsClear ,0
invoke drd_imageDraw,offset dinod.info, dinod.pos.x, dinod.pos.y
invoke drd_flip
invoke drd_processMessages
jmp loopa
ret
main endp
end main