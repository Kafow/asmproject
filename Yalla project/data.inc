.const
DINO_Y_ONSCREEN = 294
DINO_X_ONSCREEN = 40
SPEED = 12 ;3 on laptop, 12 desktop
Jump_speed = 16 ;; 4 on laptop, 16 desktop
DINO_X_OFST = 0
DINO_Y_OFST = 4
dinoRad_OFST = 44
dinoRad = 35
dinoCenter_X_OFST = 36
dinoCenter_Y_OFST = 40
Cactus_X_OFST = 0
Cactus_Y_OFST = 4
CactusCenter_X_OFST = 8
CactusCenter_Y_OFST = 12
CactusRad_OFST = 16
STANDING = 0
JUMPING = 1
isJump_adr = 28
SPACE_OFST = 16
DOWN_OFST = 20
JUMP_LVL_OFST = 32
JUMP_POWER = 430
DRCY = 12
DEAD = 0
ALIVE = 1
.data

h dword 800
w dword 1200
x dword 0

count dword ?
JumpCount DWORD ?
Distance DWORD ?
DinoDraww DWORD 0
DinoDrawC DWORD 0 ;0 for false, 1 for true
CactusDraw DWORD 0 ; 0 for false, 1 for true
KEYS struct
	jump DWORD ?
	crouch DWORD ?
KEYS ends
Cactus struct
pos POINT<>; 0 x / 4 y
center POINT<> ;8 x/ 12 y
RAD DWORD dinoRad ; 16
IsScreen DWORD 0;20
Cactus ends
Dmoot struct 
	pos POINT<> ;0 x /4 y
	drc POINT<> ; 8- 1/ 12 - 2
	keyboard KEYS<> ; jump 16 / crouch 20 
	isAlive DWORD ALIVE  ;24
	isJump DWORD STANDING ;28
	JUMP_LVL DWORD JUMP_POWER ;32
	center POINT<>; 36 x / 40 y
	RAD DWORD dinoRad; 44
Dmoot ends

Images struct
	dino Img<>
	dinoUP Img<>
	dinoDOWN Img<>
	background Img<>
	cactus Img<>
	dinof Img<>
	gameover Img<>
	restarttt Img<>
Images ends
res Images<>

score db "score-reached.wav", 0
hit db "hit.wav",0
jump_sound db "button-press.wav",0
dino db "pics\dino.png",0
dinoUP db "pics\leg_up.png",0
dinoDOWN db "pics\leg_down.png",0
background db "pics\background.png",0
cactus1 db "pics\cactus1.png",0
dinof db "pics\dinof.png", 0
gameover db "pics\gameover.png",0
restarttt db "pics\restart.png", 0

dinod Dmoot<<DINO_X_ONSCREEN,DINO_Y_ONSCREEN>,<1,0>,<VK_SPACE,VK_DOWN>, <>>
michsol Cactus <<1200 - dinoRad,DINO_Y_ONSCREEN >, <>>
michsol2 Cactus <<1200, DINO_Y_ONSCREEN>, <>>
