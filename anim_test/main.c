#include "animation.h"
#include "animation.h"

int main(void)
{
    t_cub c;

    c.mlx = mlx_init();
    c.win = mlx_new_window(c.mlx, 500, 500, "test");
	

    t_image weapon_sprite1 = new_file_image("../res/gun3.xpm", &c);
    t_image weapon_sprite2 = new_file_image("../res/guna.xpm", &c);
	t_animation weapon_animation;
	weapon_animation.num_frames = 0;
	weapon_animation.width = weapon_sprite1.w;
	weapon_animation.height = weapon_sprite1.h;
	weapon_animation.delay = 100; // Adjust delay as needed
	weapon_animation.current_frame = 0;
	weapon_animation.last_updated = timestamp_in_ms();
	
	// Add frames to the animation
	weapon_animation.frames[weapon_animation.num_frames++] = &weapon_sprite1;
	weapon_animation.frames[weapon_animation.num_frames++] = &weapon_sprite2;
	while (1) // Main game loop
	{
	    update_weapon_animation(&weapon_animation, &weapon_sprite1, 200, 200);
	    mlx_put_image_to_window(c.mlx, c.win, weapon_sprite1.img, 0, 0);
	    mlx_do_sync(c.mlx); // Ensure proper synchronization
	}

	mlx_destroy_image(c.mlx, weapon_sprite1.img);
	mlx_destroy_image(c.mlx, weapon_sprite2.img);

    return (0);
}

