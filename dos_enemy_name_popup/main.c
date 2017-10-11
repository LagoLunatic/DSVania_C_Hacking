
#include "../defines/dos_defines.h"

const u32 first_enemy_name_text_id = 0x1A8;

void ShowEnemyNamePopup(u8 enemy_id) {
  ShowItemOrSoulName3(1, 0);
  ShowItemOrSoulName4(0, 0x58, 0x60, 8, 0xFF, 0);
  ShowItemOrSoulName5(0);
  ShowItemOrSoulName6(0, 0x58, 0xFF, 0);
  
  u16 text_width_in_pixels;
  u32 string_pointer = text_list[first_enemy_name_text_id+enemy_id];
  RenderText(string_pointer, 0, &text_width_in_pixels, 0, 0);
  SetOAMData(0x4, 0xB4, -1, 0, 2);
}
