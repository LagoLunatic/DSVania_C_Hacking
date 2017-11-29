
#include "../defines/por_defines.h"

void StairsCreate(struct Entity* self) {
  SetCallbacksAndIframesIndex(self, 0, 0, 0); // Needed to initialize the hitbox index
}

void StairsUpdate(struct Entity* self) {
  struct hitbox hitbox;
  hitbox.box.left = -0x10;
  hitbox.box.right = 0x10;
  hitbox.box.top = 0;
  hitbox.box.bottom = 0x10;
  hitbox.which_box = 0;
  hitbox.type = 4;
  
  if (self->state == 0) {
    // Player is not on stairs.
    if (pressed_buttons & 0x40 // Up button pressed
        && controlled_player->x >= self->x - 0x8000
        && controlled_player->y >= self->y - 0x8000
        && controlled_player->x < self->x + 0x8000
        && controlled_player->y < self->y + 0x8000
    ) {
      // Pressed up while close to the stairs (within 8px in any direction).
      // Go to the on stairs state.
      self->state = 1;
      controlled_player->x = self->x;
    }
    
    hitbox.type = 0;
    SetHitbox(self, self->x, self->y, self->z, hitbox);
  } else {
    // Player is on stairs.
    
    if (controlled_player->player_state_booleans & 0x10) { // In air bit
      // Jump/fell off the stairs. Go back to the not on stairs state.
      self->state = 0;
      return;
    }
    
    if (controlled_player->player_state_booleans_2 & 0x20) { // On a real floor bit (not an entity)
      // Player is on a real floor. If at the top of the stairs we want to turn them off because it means the player reached the top. But if at the bottom we stay in this state because the player probably just starting to climb the stairs.
      if (controlled_player->y < self->y - 0x8000) {
        self->state = 0;
        return;
      }
    }
    
    if (controlled_player->x >= self->x + 0x8000
        || controlled_player->y >= self->y + 0x8000) {
      // Player is past the bottom right of the stairs, so go back to the not on stairs state.
      self->state = 0;
      return;
    }
    
    // Create an invisible platform hitbox under the player to simulate the stairs.
    u32 platform_y = self->y - (self->x - controlled_player->x);
    
    SetHitbox(self, controlled_player->x, platform_y, self->z, hitbox);
    
    SetEntityCollision(self, 1); // Set as a jumpthrough platform.
  }
}
