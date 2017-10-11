
#pragma once

struct Entity* GetEntitySlot(int, int, int*);
void Object09Create(struct Entity*);
void MoveXVel(struct Entity*);
void MoveYVel(struct Entity*);
void OffsetHitbox(struct Entity*, int, int, int, struct hitbox_pair);
int CheckEntityPlayerCollision(struct hitbox_pair*, struct Entity*);

void SetEnemyOnTopScreen(u8 enemy_id);
void ShowItemOrSoulName3(u32 unk1, u32 unk2);
void ShowItemOrSoulName4(u32 unk1, u32 unk2, u32 unk3, u32 unk4, u32 unk5, u32 unk6);
void ShowItemOrSoulName5(u32 unk1);
void ShowItemOrSoulName6(u32 unk1, u32 unk2, u32 unk3, u32 unk4);
void RenderText(u32 string_pointer, u32 unk1, u16* text_width_in_pixels, u32 unk2, u32 unk3);
void SetOAMData(u32 x, u32 y, u32 palette, u32 first_oam_slot, u32 last_oam_slot);
