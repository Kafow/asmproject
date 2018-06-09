.const
DINO_Y_ONSCREEN = 294
DINO_X_ONSCREEN = 40
SPEED = 20
DINO_Y_OFST = 4
STANDING = 0
JUMPING = 1
isJump_adr = 28
SPACE_OFST = 16
DOWN_OFST = 20
JUMP_LVL_OFST = 32
JUMP_POWER = 200
DRCY = 12
DEAD = 0
ALIVE = 1
.data
h dword 800
w dword 1200
x dword 0
count dword ?
KEYS struct
	jump DWORD ?
	crouch DWORD ?
KEYS ends
Cactus struct
pos POINT<>
Cactus ends
Dmoot struct 
	pos POINT<> ;0 x /4 y
	drc POINT<> ; 8- 1/ 12 - 2
	keyboard KEYS<> ; jump 16 / crouch 20 
	isAlive DWORD ALIVE  ;24
	isJump DWORD STANDING ;28
	JUMP_LVL DWORD JUMP_POWER ;32
	
	 
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
