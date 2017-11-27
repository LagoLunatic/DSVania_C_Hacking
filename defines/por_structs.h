
#pragma once

struct Entity {
  u32 update_func;
  u32 draw_func;
  u32 unknown8;
  u8 unknownC;
  u8 state;
  u8 substate;
  u8 subsubstate;
  u16 unknown10;
  u16 unknown12;
  u16 timer_1;
  u16 timer_2;
  u32 unknown18;
  u32 unknown1C;
  u32 unknown20;
  s32 screen_x;
  s32 screen_y;
  u32 screen_z;
  s32 x;
  s32 y;
  u32 z;
  s32 x_vel;
  s32 y_vel;
  u32 unknown44;
  u32 x_friction;
  u32 gravity;
  u8 dummypadding1[0x80];
  u32 player_state_booleans;
  u32 player_state_booleans_2;
  u8 dummypadding4[0x5A];
  u8 subtype;
  u8 byte_5;
  u8 dummypadding2[8];
  u16 var_a;
  u16 var_b;
  u8 dummypadding3[0x20];
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
