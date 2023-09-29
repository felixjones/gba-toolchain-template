#include <tonc.h>

#include "brin-full.h"

int main() {
    // Load palette
    dma3_cpy(pal_bg_mem, brin_fullPal, brin_fullPalLen);
    // Load tiles into CBB 0
    dma3_cpy(&tile_mem[0][0], brin_fullTiles, brin_fullTilesLen);
    // Load map into SBB 30
    dma3_cpy(&se_mem[30][0], brin_fullMap, brin_fullMapLen);

    // set up BG0 for a 4bpp 64x32t map, using
    //   using charblock 0 and screenblock 31
    REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_4BPP | BG_REG_64x32;
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

    // Scroll around some
    int x= 192, y= 64;
    while(1) {
        vid_vsync();
        key_poll();

        x += key_tri_horz();
        y += key_tri_vert();

        REG_BG0HOFS= x;
        REG_BG0VOFS= y;
    }
}
