#include "cube3d.h"

/* what we need 
-> need a array of t_sprites * 

- find dist to x/y of sprite
- sort list far first near last





*/
cub_sortsprite()
{
	ft_setupsprite();
	ft_quicksort();
}



/* what can be in a helper cub_sprite_struct */
void	cub_sprites(t_ray *r, t_cub *c, t_sc *s)
{
	int	i;

	cub_sortsprite();
	i = -1;
	while ( ++i < s->ns)
	{
			
		s->sarr[i].spritex = s->sarr[i].x - s->pl.posx;
     		s->sarr[i].spritey =  s->sarr[i].y - s->pl.posy;
		s->invDet = 1.0 / (s->plane_x * s->pl.dirY - s->pl.dirX * s->plane_y);
		s->sarr[i].transformx = s->invDet * (s->pl.dirY * s->sarr[i].spritex - s->pl.dirX * s->sarr[i].spritey);
     		s->sarr[i].transformy = s->invDet * (-s->planey * s->sarr[i].spritex + s->planex * s->sarr[i].spritey); 
		double spriteScreenX = (w / 2) * (1 + transformX / transformY));

		/* this has to be in the sprite struct */
		//parameters for scaling and moving the sprites
      		#define uDiv 1
      		#define vDiv 1
      		#define vMove 0.0
		
		double vMoveScreen = vMove / transformY;
		
 		double spriteHeight = fabs(( / (transformY))) / vDiv
		double drawStartY = -spriteHeight / 2 + h / 2 + vMoveScreen;
      		if(drawStartY < 0) 
			drawStartY = 0;
      		double drawEndY = spriteHeight / 2 + h / 2 + vMoveScreen;
      		if(drawEndY >= h) 
			drawEndY = h - 1;
		//calculate width of the sprite
      	int spriteWidth = abs(int (h / (transformY))) / uDiv; // same as height of sprite, given that it's square
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX > w) drawEndX = w;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
       int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) ZBuffer, with perpendicular distance
        if(transformY > 0 && transformY < ZBuffer[stripe])
        {
		/* find the pixelin the vertical line*/	
        }


	}






}
