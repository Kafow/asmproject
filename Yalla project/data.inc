
.data
Dmoot struct ; 36
	pos POINT<200,100>
	drc POINT<1,0> 
	info Img<>
Dmoot ends

score db "score-reached.wav", 0
hit db "hit.wav",0
start db "button-press.wav",0
dino byte "pics\dino.png",0

dinod Dmoot<<200,200>,<1,0>,<>>
