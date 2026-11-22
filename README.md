*This project has been created as part of the 42 curriculum by buehara and csilva-s*

# Cub3D

## Description
This project aims to create a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective.
This project was created using the ray-casting techniques used in several early games like Wolfenstein 3D.


## Instructions
How to run it:

git clone the repo:

```bash
git clone https://github.com/project42sp/cub3d.git
```

Run Make to install it:

```bash
make
```

Get a .cub map file ready, this project has several variations meant for testing, so they can be a bit boring, but you can use them:

```bash
./cub3D ./map/maps.valid_reference_map.cub
```

To be able to accept a text file for parsing, the map must follow some constrains:
- It must have 6 parameters:
	- 4 Directional Textures files as NO (north texture), SO (south), EA (east) and WE (west). Only accepts XPM files.
	- 2 Colors for F (Floor) and C (Ceiling). Color format in HEX.

Example:
```bash
NO ./texture/north_texture.xpm
SO ./texture/south_texture.xpm
EA ./texture/east_texture.xpm
WE ./texture/west_texture.xpm

F 255,10,10
C 240,100,110
```

The map must be the last content of the file. Any other parameter can be on any particular order if it is before the map.

Maps must be built using 1 (one) as walls, and the player must be one of the following letters: N, S, E or W. Any other letter is not allowed.
Map must be completelly closed by walls. An open map will not be accepted. A map can have a hole inside it, if it is surrounded by walls, it will me accepted.

Map Example:
```bash
11111
10001
10E01
10001
11111
```

This is project has a texture wall referencing the old Maze Windows Screensaver.

## Resources

- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)

- [Make Your Own Raycaster Series - 3DSage](https://www.youtube.com/watch?v=gYRrGTC7GtA)

### AI Usage

AI was mainly used as a research tool, and explaining tool. We used it to understand better the concepts used in this project. Also used it to come up with tests cenarios for the project. 
