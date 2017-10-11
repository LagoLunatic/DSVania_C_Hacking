.nds
.relativeinclude on
.erroronwarning on

PROJECT_DIR equ "../../ROMs/DoS_Enemy_Names"

.open PROJECT_DIR + "/ftc/overlay9_0", 0219E3E0h

.org 0x021C4264 ; Where the game would normally call SetEnemyOnTopScreen
  b @FreeSpace

.close

.open PROJECT_DIR + "/ftc/overlay9_41", 023E0100h

.org 0x023E0100 ; Free space
@FreeSpace:
  push r0 ; Preserve the enemy ID
  bl 0203B308h ; SetEnemyOnTopScreen, this is the line of code we overwrote to jump here.
  pop r0
  bl ShowEnemyNamePopup
  b 021C4268h
  
  .importobj "../build/linked.o"

.close
