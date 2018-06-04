.const
DINO_Y = 294
.data
Dmoot struct ; 36
	pos POINT<>
	drc POINT<> 
	info Img<>
Dmoot ends
Images struct
	dino Img<>
	background Img<>
Images ends
res Images<>

score db "score-reached.wav", 0
hit db "hit.wav",0
start db "button-press.wav",0
dino db "pics\dino.png",0
background db "pics\background.png",0

dinod Dmoot<<100,DINO_Y>,<1,0>,<>>
