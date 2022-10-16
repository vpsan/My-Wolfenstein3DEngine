# DESCRIPTION

This is my own Wolfenstein3D Engine


# Introduction
The main idea of this project is to implement in C language the Raycasting algorithm - a rendering method 
for creating a 3D perspective on a 2D map. And with this implementation build a simple engine of Wolfenstein3D game.

Wolfenstein 3D's raycasting engine was very limited, but this allowed it to run very fast even on low-end hardware.
Every wall in the game had the same height and were orthogonal squares on a 2D grid.
The game was in 1st person, the player could only move the camera left/right, no up/down.

Try to play Wolfenstein3D game here: https://www.retrogames.cz/play_408-DOS.php

# Program launch
### Dependencies

- MacOS:
  - clang
  - make
  - Minilibx
  

clang and make could be installed on MacOS:

```bash
$ brew install clang make 
```
or
```bash
$ xcode-select --install 
```


What is Minilibx? - https://qst0.github.io/ft_libgfx/man_mlx.html

All other necessary code is already in the project.

### Build and run
```bash
$ make
...
$ ./cub3D maps/valid/map1.cub
```

### Program arguments

The input of the program is a file with the extension ".cub"

1. Resolution X Y
    * identifier: R
    * x render size
    * y render size

2. North texture
    * identifier: NO
    * path to the north texure

3. South texture
    * identifier: SO
    * path to the south texure

4. West texture
    * identifier: WE
    * path to the west texure

5. East texture
    * identifier: EA
    * path to the east texure

6. Sprite texture
    * identifier: S
    * path to the sprite texure

7. Floor color
    * identifier: F
    * R,G,B colors in range [0,255]: 0, 255, 255

8. Ceilling color
    * identifier: C
    * R,G,B colors in range [0,255]: 0, 255, 255

The map must be composed of only 4 possible characters: 0 for an empty space, 1 for a wall, 2 for an item and N,S,E or W for the player’s start position and spawning orientation.
This is a simple valid map:

```Text
111111
100101
102001
1100N1
111111
```

# Implementation

### Basic idias

The basic idea of raycasting is as follows: the map is a 2D square grid, and each square can either be zero or a positive value:
- 0 = no wall
- 1 = a wall with a certain color or texture depended on side of the world
- 2 = a sprite item position

To find the first wall that a ray encounters on its way, you have to let it start at the player's position, and then all the time, check whether or not the ray is inside a wall. If it's inside a wall (hit), then the loop can stop, calculate the distance, and draw the wall with the correct height. If the ray position is not in a wall, you have to trace it further: add a certain value to its position, in the direction of the direction of this ray, and for this new position, again check if it's inside a wall or not. Keep doing this until finally a wall is hit.

This image shows a top down overview of two such rays (red) that start at the player (green dot) and hit blue walls:

<img width="365" alt="image" src="https://user-images.githubusercontent.com/75123248/196048724-7fbf017a-4f9e-4b3b-8f02-f518cedb0062.png">

------------------------------------------------

The algorithm is used in this project is based on DDA or "Digital Differential Analysis". DDA is a fast algorithm typically used on square grids to find which squares a line hits.
It helps to find which squares of the map our ray hits, and stop the algorithm once a square that is a wall is hit.

<img width="361" alt="image" src="https://user-images.githubusercontent.com/75123248/196048738-523c2ba0-94e1-4837-94bc-4eb001336a06.png">

------------------------------------------------

First of all, we need to define:
1. position vector 
2. direction vector
3. camera plane vector

The camera plane should always be perpendicular on the direction vector. The camera plane represents the surface of the computer screen, while the direction vector is perpendicular on it and points inside the screen.
The position of the player, which is a single point, is a point in front of the camera plane.

<img width="453" alt="image" src="https://user-images.githubusercontent.com/75123248/196048756-86a242ea-a4e2-4cee-be62-fe5529e50030.png">

When the player rotates, the camera has to rotate, so both the direction vector and the plane vector have to be rotated. 

<img width="380" alt="image" src="https://user-images.githubusercontent.com/75123248/196048761-8f796443-fbc6-4019-acf3-74677f635e87.png">


To rotate a vector, multiply it with the rotation matrix, like rotation matrix around the OZ:

```Text
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
```

------------------------------------------------

### Raycasting 

The explanation of input variables goes here before Raycasting explanation. 

All necossary variables for raycasting are declared in struct s_player and struct s_rcstg in [game.h](includes/game.h).

struct s_player:
```C

typedef struct          s_player
{
double			pos_x;
double			pos_y;
double			dir_x;
double			dir_y;
double			plane_x;
double			plane_y;
}			t_player;
```

struct s_player consists of double type variables:
1. pos_x, pos_y - start position of the player
2. dir_x, dir_y - initial direction vector of the player
3. plane_x, plane_y - the 2d raycaster version of camera plane

The camera plane should always be perpendicular on the direction vector. Thats why depending on which side of the world (North, South, West, East) the player is initialized to look, we set ([game_player_init.c](srcs/game/game_player_init.c)) the camera plane and the direction vector:

```C
int	set_player_prmtrs(t_cube3D *cube, char plr_dir)
{
	if (plr_dir == 'W')
	{
		set_dirx_diry(cube, 0, -1);
		set_planex_planey(cube, -0.66, 0);
	}
	if (plr_dir == 'E')
	{
		set_dirx_diry(cube, 0, 1);
		set_planex_planey(cube, 0.66, 0);
	}
	if (plr_dir == 'S')
	{
		set_dirx_diry(cube, 1, 0);
		set_planex_planey(cube, 0, -0.66);
	}
	if (plr_dir == 'N')
	{
		set_dirx_diry(cube, -1, 0);
		set_planex_planey(cube, 0, 0.66);
	}
	return (0);
}
```

The ratio between the length of the direction and the camera plane determinates the FOV, here the direction vector is a bit longer than the camera plane, so the FOV will be smaller than 90° (more precisely, the FOV is 2 * atan(0.66/1.0)=66°, which is perfect for a first person shooter game).

------------------------------------------------

Here starts the actual raycasting.

The raycasting [loop](srcs/game/rcstng.c) is a for loop that goes through every x of window width, so there isn't a calculation for every pixel of the screen, but only for every vertical stripe,
Each iteration fires a ray from the location of the game

Firstly, we need to [calculate](srcs/game/rcstng_init.c) ray vector for every x_i:

```C
cube->rcstg.camera_x = 2 * (cube->map_prmtrs.win_width - x_i) / (double)(cube->map_prmtrs.win_width) - 1;
cube->rcstg.ray_dir_x = cube->plr.dir_x + cube->plr.plane_x * cube->rcstg.camera_x;
cube->rcstg.ray_dir_y = cube->plr.dir_y + cube->plr.plane_y * cube->rcstg.camera_x;
```

cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents, done this way so that the right side of the screen will get coordinate 1, the center of the screen gets coordinate 0, and the left side of the screen gets coordinate -1. Out of this, the direction of the ray can be calculated as was explained earlier: as the sum of the direction vector, and a part of the plane vector. This has to be done both for the x and y coordinate of the vector (since adding two vectors is adding their x-coordinates, and adding their y-coordinates).

------------------------------------------------

Secondly, we need to do some preparations to use DDA (Digital Differential Analysis) algorithm for each ray.

Define mapX, mapY - the current square of the map the ray is in. The ray position itself is a floating point number and contains both info about in which square of the map we are, and where in that square we are, but mapX and mapY are only the coordinates of that square.

```C
cube->rcstg.map_x = (int)cube->plr.pos_x;
cube->rcstg.map_y = (int)cube->plr.pos_y;
```

Сonsider the drawing below and introduce some more variables:

<img width="346" alt="image" src="https://user-images.githubusercontent.com/75123248/196048775-114677b1-77fc-48a7-9b97-5bf7c0b38c01.png">

sideDistX and sideDistY are initially the distance the ray has to travel from its start position to the first x-side and the first y-side. Later in the code they will be incremented while steps are taken.

deltaDistX and deltaDistY are the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side. The following image shows the initial sideDistX, sideDistY and deltaDistX and deltaDistY

When deriving deltaDistX geometrically you get, with Pythagoras, the formulas below. For the blue triangle (deltaDistX), one side has length 1 (as it is exactly one cell) and the other has length raydirY / raydirX because it is exaclty the amount of units the ray goes in the y-direction when taking 1 step in the X-direction. For the green triangle (deltaDistY), the formula is similar.


```C
cube->rcstg.delta_dist_x = sqrt(1 + cube->rcstg.ray_dir_y^2/ cube->rcstg.ray_dir_x^2)
cube->rcstg.delta_dist_y = sqrt(1 + cube->rcstg.ray_dir_x^2/ cube->rcstg.ray_dir_y^2)
```

But it can be simplified to:

```C
cube->rcstg.delta_dist_x = fabs(1 / cube->rcstg.ray_dir_x);
cube->rcstg.delta_dist_y = fabs((1 / cube->rcstg.ray_dir_y));
```

Now, before the actual DDA can start, the initial sideDistX and sideDistY still have to be calculated.

If the ray direction has a negative x-component, stepX is -1, if the ray direciton has a positive x-component it's +1. If the x-component is 0, it doesn't matter what value stepX has since it'll then be unused.
The same goes for the y-component.

If the ray direction has a negative x-component, sideDistX is the distance from the ray starting position to the first side to the left, if the ray direciton has a positive x-component the first side to the right is used instead.
The same goes for the y-component, but now with the first side above or below the position.
For these values, the integer value mapX is used and the real position subtracted from it, and 1.0 is added in some of the cases depending if the side to the left or right, of the top or the bottom is used. Then you get the perpendicular distance to this side, so multiply it with deltaDistX or deltaDistY to get the real Euclidean distance.

```C
if (cube->rcstg.ray_dir_x < 0)
{
    cube->rcstg.step_x = -1;
    cube->rcstg.side_dist_x = (cube->plr.pos_x - cube->rcstg.map_x) * cube->rcstg.delta_dist_x;
}
else
{
    cube->rcstg.step_x = 1;
    cube->rcstg.side_dist_x = (cube->rcstg.map_x + 1.0 - cube->plr.pos_x) * cube->rcstg.delta_dist_x;
}
if (cube->rcstg.ray_dir_y < 0)
{
    cube->rcstg.step_y = -1;
    cube->rcstg.side_dist_y = (cube->plr.pos_y - cube->rcstg.map_y) * cube->rcstg.delta_dist_y;
}
else
{
    cube->rcstg.step_y = 1;
    cube->rcstg.side_dist_y = (cube->rcstg.map_y + 1.0 - cube->plr.pos_y) * cube->rcstg.delta_dist_y;
}
```

------------------------------------------------

Now the actual DDA starts. It's a loop that increments the ray with 1 square every time, until a wall is hit. Each time, either it jumps a square in the x-direction (with stepX) or a square in the y-direction (with stepY), it always jumps 1 square at once. If the ray's direction would be the x-direction, the loop will only have to jump a square in the x-direction everytime, because the ray will never change its y-direction. If the ray is a bit sloped to the y-direction, then every so many jumps in the x-direction, the ray will have to jump one square in the y-direction. If the ray is exactly the y-direction, it never has to jump in the x-direction, etc...

sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction, and mapX and mapY get incremented with stepX and stepY respectively.

When the ray has hit a wall, the loop ends, and then we'll know whether an x-side or y-side of a wall was hit in the variable "side", and what wall was hit with mapX and mapY. We won't know exactly where the wall was hit however, but that's not needed in this case because we won't use textured walls for now.

```C
while (cube->rcstg.hit == 0)
{
    if (cube->rcstg.side_dist_x < cube->rcstg.side_dist_y)
    {
        cube->rcstg.side_dist_x += cube->rcstg.delta_dist_x;
        cube->rcstg.map_x += cube->rcstg.step_x;
        cube->rcstg.side = 0;
    }
    else
    {
        cube->rcstg.side_dist_y += cube->rcstg.delta_dist_y;
        cube->rcstg.map_y += cube->rcstg.step_y;
        cube->rcstg.side = 1;
    }
    if (cube->map[cube->rcstg.map_x][cube->rcstg.map_y] == '1')
        cube->rcstg.hit = 1;
}
```
Start values of hit = 0 and size = -1

------------------------------------------------


After the DDA is done, we have to calculate the distance of the ray to the wall, so that we can calculate how high the wall has to be drawn after this.































---------------


total struct s_rcstg:

```C
typedef struct s_rcstg
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int			map_x;
	int			map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double			wall_x;
	t_texture		*tex;
	int			tex_x;
	int			tex_y;
	double			tex_step;
	double			tex_pos;
}				t_rcstg;
```


