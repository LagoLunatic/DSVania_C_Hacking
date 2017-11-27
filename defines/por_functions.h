
#pragma once

void TeleportPlayer(u32 area_index, u32 sector_index, u32 room_index, s32 x_pos, s32 y_pos);
void TriggerRoomTransition();
bool LoadSpriteSingleGfx(struct Entity* entity, u32 sprite_pointer, u32 gfx_asset_pointer, u32 palette_list_pointer);
void SetEntityCollision(struct Entity* entity, u32 collision_type);
void SetCallbacksAndIframesIndex(struct Entity* entity, u32 iframes_index, u32 on_touch_player_callback, u32 on_touched_by_player_callback);
void SetHitbox(struct Entity* entity, u32 x_pos, u32 y_pos, u32 z_pos, struct hitbox hitbox);
