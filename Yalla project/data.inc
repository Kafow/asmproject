.const
DINO_Y = 294
DINO_X = 40

STANDING = 0
JUMPING = 1

DEAD = 0
ALIVE = 1
.data
h dword 800
w dword 1200
x dword 0
Cactus struct
pos POINT<>
Cactus ends
Dmoot struct 
	pos POINT<>
	drc POINT<>
	isAlive DWORD ALIVE
	isJump DWORD STANDING
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

dinod Dmoot<<40,DINO_Y>,<1,0>,<>>
