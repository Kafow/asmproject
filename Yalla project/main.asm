include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
include main_funcs.inc
;sound
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib 
.code
 ; TODO: finish jump, add cactus, maybe add score, replace sleep with count
main proc
invoke init




loopa:
invoke Sleep, 5
invoke update
invoke draw

jmp loopa
ret
main endp
end main