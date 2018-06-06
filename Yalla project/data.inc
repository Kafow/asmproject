.const
DINO_Y_ONSCREEN = 294
DINO_X_ONSCREEN = 40
DINO_Y_OFST = 8
STANDING = 0
JUMPING = 1
isJump_adr = 28
SPACE_OFST = 16
DOWN_OFST = 20
DEAD = 0
ALIVE = 1
.data
h dword 800
w dword 1200
x dword 0
KEYS struct
	jump DWORD ?
	crouch DWORD ?
KEYS ends
Cactus struct
pos POINT<>
Cactus ends
Dmoot struct 
	pos POINT<> 
	drc POINT<> 
	keyboard KEYS<> 
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
jump_sound db "button-press.wav",0
dino db "pics\dino.png",0
background db "pics\background.png",0

dinod Dmoot<<DINO_X_ONSCREEN,DINO_Y_ONSCREEN>,<1,0>,<VK_SPACE,VK_DOWN>>
