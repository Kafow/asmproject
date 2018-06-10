include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
include main_funcs.inc
;sound
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code
 ; TODO: finish jump(V), add cactus, maybe add score, replace sleep with count(V), 
 ; Do a sperate count for dino and the rest (v), Do a func that would draw the cactus in random
 ; paces and cactus x Would go with speed game
main proc
invoke init
loopa:

invoke update
invoke draw

jmp loopa
ret
main endp
end main