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
invoke init ;openning the window and loading the images
loopa:
invoke restart, offset dinod ;check if need to restart
invoke update ;update the loop and the funcs
invoke draw ;drawing the game
jmp loopa
ret
main endp
end main