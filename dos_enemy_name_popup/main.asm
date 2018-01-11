.nds
.relativeinclude on
.erroronwarning on

PROJECT_DIR equ "../../ROMs/DoS_Enemy_Names"
@Overlay41Start equ 0x02308920
@FreeSpace equ 0x02308920

.open PROJECT_DIR + "/ftc/overlay9_0", 0219E3E0h

.org 0x021C4264 ; Where the game would normally call SetEnemyOnTopScreen
  b @FreeSpace

.close

.open PROJECT_DIR + "/ftc/overlay9_41", @Overlay41Start

.org @FreeSpace
  push r0 ; Preserve the enemy ID
  bl 0203B308h ; SetEnemyOnTopScreen, this is the line of code we overwrote to jump here.
  pop r0
  bl ShowEnemyNamePopup
  b 021C4268h
  
  .importobj "../build/linked.o"

.close
