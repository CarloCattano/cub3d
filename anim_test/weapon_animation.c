#include "animation.h"

long	timestamp_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
t_image new_file_image(char *path, void *mlx_ptr) {
	t_image img;
	img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img.w, &img.h);
	img.pix = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	return (img);
}

void clear_image(t_image *img)
{
	ft_bzero(img->pix, img->w * img->h * (img->bpp / 8));
}

void my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pix + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void update_weapon_animation(t_animation *animation, t_image *weapon_img, int x, int y)
{
    if (timestamp_in_ms() - animation->last_updated < animation->delay)
        return;

    animation->last_updated = timestamp_in_ms();
    animation->current_frame = (animation->current_frame + 1) % animation->num_frames;
    t_image *current_frame_img = animation->frames[animation->current_frame];
    clear_image(weapon_img);
    render_image(weapon_img, current_frame_img, x, y);
}

void render_image(t_image *dst, t_image *src, int x, int y)
{
    int i;
    int j;
    int color;

    i = 0;
    while (i < src->h)
    {
        j = 0;
        while (j < src->w)
        {
			color = *mlx_get_data_addr(src->img, &src->bpp, &src->ll, &src->endian);
            if (color != 0)
                my_mlx_pixel_put(dst, x + j, y + i, color);
            j++;
        }
        i++;
    }
}
