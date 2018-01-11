.nds
.relativeinclude on
.erroronwarning on

PROJECT_DIR equ "../../ROMs/PoR_Interarea_Doors"
@Overlay119Start equ 0x02308EC0
@FreeSpace equ 0x02308EC0

.open PROJECT_DIR + "/ftc/overlay9_119", @Overlay119Start

.org @FreeSpace

.importobj "../build/linked.o"

.close

.open PROJECT_DIR + "/ftc/arm9.bin", 02000000h

.org 0x020344BC ; Object 07's create code
  b FakeDoorCreate
.org 0x020344C0 ; Object 07's update code
  b FakeDoorUpdate

.close
