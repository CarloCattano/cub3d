#include "cube3d.h"

/* what we need 
-> need a array of t_sprites * 

- find dist to x/y of sprite
- sort list far first near last





*/


/* sv -> sortvalue
void	^ft_setupsprite(t_sprites **a, double posx, double posyi, int size)
{
	int i;

	i = -1;
	while ( ++i < size)
	{
		a[i]->sv = ((posx - a[i]->x) * (posx - a[i]->x) + (posy - a[i]->y) * (posy - a[i]->y));
	}

}

static void	ft_swap(t_sprite **p1, t_sprite **p2)
{
	t_sprite	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	quicksort(t_sprite **tab, int size)
{
	double	pivot;
	int		i;
	int		j;

	if (size < 2)
		return ;
	pivot = tab[size / 2]->sv;
	i = -1;
	j = size;
	while (1)
	{
		while (tab[++i]->sv < pivot)
			;
		while (tab[--j]->sv > pivot)
			;
		if (i >= j)
			break ;
		ft_swap(&tab[i], &tab[j]);
	}
	quicksort(tab, i);
	quicksort(tab + i, size - i);
}








cub_sortsprite()
{
	ft_setupsprite(s->sarr, s->ply.posx, s->ply.posy, s->ns);
	ft_quicksort(s->sarr, s->ns);
}

typedef struct s_hst
{
	double x; // spriteX
	double y; // spriteY
	double tx; // transformX
	double ty; // transformY
	double sx; // spriteScreeX
	double ms; //vMoveScreen
	double sh; // spriteHeight
	double dsy; // drawStartY
	double dey; // drawEndY
	doubel sw; // spriteWidth
	doubel dsx; // DrawstartX
	double dex; // DrawStartX	


} t_hst;


void	ft_init_hst(t_sc *s, t_cub *c, t_hst *h, int i)
{
	double invDet;
	
	invDet = 1.0 / (s->plane_x * s->pl.dirY - s->pl.dirX * s->plane_y);
	h->x = s->sarr[i]->x - s->pl.posx;
     	h->y =  s->sarr[i]->y - s->pl.posy;
	h->tx = invDet * (s->pl.dirY * h->x - s->pl.dirX * h->y);
     	h->ty = invDet * (-s->plane_y * h->x + s->plane_x * h->y); 
	h->sx = (c->win_w / 2) * (1 + h->tx / h->ty));
	h->ms = s->sarr[i]->vm / h->ty; 
	h->sh = fabs(c->win_h / h->ty) / s->sarr[i]->vdiv; 	
	h->dsy = -h->sh / 2 + c->win_h / 2 + h->ms;
	if (h->dsy < 0)
		h->dsy = 0;
	h->dey = h->sh / 2 + c->win_h / 2 h->ms;
	if ( h->dey >= c->win_h)
		h->dey = c->win_h - 1;
	h->sw = fabs(c->win_h / h->ty) / s->sarr[i]->udiv;	 
	h->dsx = -h->sw / 2 + h->sx;
	if (h->dsx < 0)
		h->dsx = 0;
	h->dex = h_>sw / 2 + h->sx;
	if (h->dex > c->win_w )
		h->dex = c->win_w;	
}



/*all  wrong -> instead ,  what can be in a helper cub_sprite_struct */
void	cub_sprites(t_ray *r, t_cub *c, t_sc *s)
{
	int	i;
	t_hst	h;	

	cub_sortsprite();
	i = -1;
	
	while ( ++i < s->ns)
	{
		ft_init_hst(s, c , &h, i);
	


      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
       int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) ZBuffer, with perpendicular distance
        if(transformY > 0 && transformY < ZBuffer[stripe])
        { 
		for(int y = drawStartY; y < drawEndY; y++)
		/* find the pixelin the vertical line*/	
        }


	}






}
