.nds
.relativeinclude on
.erroronwarning on

PROJECT_DIR equ "../../ROMs/PoR_Stairs"

.open PROJECT_DIR + "/ftc/overlay9_119", 023C0000h

.org 0x023C0000 ; Free space

.importobj "../build/linked.o"

.close

.open PROJECT_DIR + "/ftc/arm9.bin", 02000000h

.org 0x020344B4 ; Object 08's create code
  b StairsCreate
.org 0x020344B8 ; Object 08's update code
  b StairsUpdate

.close
