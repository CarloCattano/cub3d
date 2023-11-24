#ifndef ANIMATION_H
# define ANIMATION_H
# include "cub3d.h"
# include <sys/time.h>

typedef struct	s_animation {
    t_image     *frames[8]; // Array of frames (images)
    int         num_frames;           // Number of frames
    int         width;                // Width of each frame
    int         height;               // Height of each frame
    int         delay;                // Delay between frames
    int         current_frame;        // Current frame number
    long int    last_updated;         // Last update time
}               t_animation;

void update_weapon_animation(t_animation *anim, t_image *weapon_img, int x, int y);
void render_image(t_image *dst, t_image *src, int x, int y);
t_image new_file_image(char *path, void *c);

long	timestamp_in_ms(void);
t_list	*ft_lstget(t_list *lst, int index);

#endif

