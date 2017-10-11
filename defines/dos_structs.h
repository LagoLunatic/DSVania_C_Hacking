
#pragma once

struct Entity {
  u32 update_func;
  u32 draw_func;
  u32 unknown8;
  u8 unknownC;
  u8 state;
  u8 substate;
  u8 subsubstate;
  u32 unknown10;
  u32 unknown14;
  u16 timer_1;
  u16 unknown1A;
  u32 unknown1C;
  u32 screen_x;
  u32 screen_y;
  u32 screen_z;
  s32 x;
  s32 y;
  u32 z;
  s32 x_vel;
  s32 y_vel;
  u32 unknown40;
  u32 x_friction;
  u32 gravity;
  u32 unknown4C;
  u32 trail_scale;
  u32 scale;
  u32 enable_scaling;
  u32 unknown5C;
  u32 unknown60;
  u32 unknown64;
  u16 sprite_info_index;
  u16 unknown6A;
  u32 unknown6C;
  u32 unknown70;
  u8 dummypadding[0x5C];
  u32 player_states_bitfield;
  u8 dummypadding2[0x10];
  u32 unknown_bitfield;
  u8 dummypadding3[0x186];
  u16 var_a;
  u16 var_b;
  u8 dummypadding4[0x2E];
};

struct rect {
  u16 left;
  u16 top;
  u16 right;
  u16 bottom;
};

struct hitbox {
  struct rect box;
  u32 which_box;
  u32 type;
};

struct hitbox_pair {
  struct hitbox hitbox_1;
  struct hitbox hitbox_2;
};
