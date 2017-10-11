
#include "../defines/por_defines.h"

const s32 SCREEN_WIDTH_IN_SUBPIXELS = 0x100 * 0x1000;
const s32 SCREEN_HEIGHT_IN_SUBPIXELS = 0xC0 * 0x1000;

void FakeDoorCreate(struct Entity* entity) {
  // Round position down to the nearest screen in case the level designer didn't place this fake door aligned to the screen.
  if (entity->x >= 0) {
    entity->x = entity->x / SCREEN_WIDTH_IN_SUBPIXELS * SCREEN_WIDTH_IN_SUBPIXELS;
  } else {
    entity->x = -SCREEN_WIDTH_IN_SUBPIXELS;
  }
  if (entity->y >= 0) {
    entity->y = entity->y / SCREEN_HEIGHT_IN_SUBPIXELS * SCREEN_HEIGHT_IN_SUBPIXELS;
  } else {
    entity->y = -SCREEN_HEIGHT_IN_SUBPIXELS;
  }
}

void FakeDoorUpdate(struct Entity* entity) {
  // Check if the controlled player is within the door's screen.
  if (controlled_player->x >= entity->x
      && controlled_player->y >= entity->y
      && controlled_player->x < (entity->x + SCREEN_WIDTH_IN_SUBPIXELS)
      && controlled_player->y < (entity->y + SCREEN_HEIGHT_IN_SUBPIXELS)
  ) {
    // Extract the location this fake door should teleport the player to from the fake door entity's var A and var B.
    // Var A has the area index and sector index.
    // Var B has the room index, x offset in screens, and y offset in screens.
    u8 area_index    = (entity->var_a & 0xFF00) >> 8;
    u8 sector_index  = (entity->var_a & 0x00FF);
    u8 room_index    = (entity->var_b & 0xFF00) >> 8;
    u8 dest_x_screen = (entity->var_b & 0x00F0) >> 4;
    u8 dest_y_screen = (entity->var_b & 0x000F);
    
    // Determine what the player's x/y pos in pixels should be in the destination room.
    s32 dest_x = dest_x_screen * SCREEN_WIDTH_IN_SUBPIXELS;
    s32 dest_y = dest_y_screen * SCREEN_HEIGHT_IN_SUBPIXELS;
    dest_x += controlled_player->x - entity->x;
    dest_y += controlled_player->y - entity->y;
    dest_x /= 0x1000;
    dest_y /= 0x1000;
    
    TeleportPlayer(area_index, sector_index, room_index, dest_x, dest_y);
    TriggerRoomTransition();
  }
}
