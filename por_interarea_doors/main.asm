.nds
.relativeinclude on
.erroronwarning on

PROJECT_DIR equ "../../ROMs/PoR_Interarea_Doors"

.open PROJECT_DIR + "/ftc/overlay9_119", 023C0000h

.org 0x023C0000 ; Free space

.importobj "../build/linked.o"

.close

.open PROJECT_DIR + "/ftc/arm9.bin", 02000000h

.org 0x020344BC ; Object 07's create code
  b FakeDoorCreate
.org 0x020344C0 ; Object 07's update code
  b FakeDoorUpdate

.close
