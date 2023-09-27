#include <stdio.h>
#include <stdlib.h>

int main() {

	int i = 0;

    const char *good[] = {
    "./cube3d ./maps/good/cheese_maze.cub",
    "./cube3d ./maps/good/creepy.cub",
	"./cube3d ./maps/good/dungeon.cub",
    "./cube3d ./maps/good/library.cub",
    "./cube3d ./maps/good/matrix.cub",
	"./cube3d ./maps/good/sad_face.cub",
	"./cube3d ./maps/good/square_map.cub",
	"./cube3d ./maps/good/subject_map.cub",
	"./cube3d ./maps/good/test_map_hole.cub",
	"./cube3d ./maps/good/test_map.cub",
	"./cube3d ./maps/good/test_pos_bottom.cub",
	"./cube3d ./maps/good/test_pos_left.cub",
	"./cube3d ./maps/good/test_pos_right.cub",
	"./cube3d ./maps/good/test_pos_top.cub",
	"./cube3d ./maps/good/test_textures.cub",
	"./cube3d ./maps/good/test_whitespace.cub",
	"./cube3d ./maps/good/works.cub",
    };

	const char *bad[] = {
		"./cube3d ./maps/bad/color_invalid_rgb.cub",
		"./cube3d ./maps/bad/color_missing_ceiling_rgb.cub ",
		"./cube3d ./maps/bad/color_missing_floor_rgb.cub ",
		"./cube3d ./maps/bad/color_missing.cub ",
		"./cube3d ./maps/bad/color_none.cub ",
		"./cube3d ./maps/bad/empty.cub ",
		"./cube3d ./maps/bad/file_letter_end.cub ",
		"./cube3d ./maps/bad/filetype_missing ",
		"./cube3d ./maps/bad/filetype_wrong.buc ",
		"./cube3d ./maps/bad/forbidden.cub ",
		"./cube3d ./maps/bad/map_first.cub ",
		"./cube3d ./maps/bad/map_middle.cub ",
		"./cube3d ./maps/bad/map_missing.cub ",
		"./cube3d ./maps/bad/map_only.cub ",
		"./cube3d ./maps/bad/map_too_small.cub ",
		"./cube3d ./maps/bad/player_multiple.cub ",
		"./cube3d ./maps/bad/player_none.cub ",
		"./cube3d ./maps/bad/player_on_edge.cub ",
		"./cube3d ./maps/bad/textures_dir.cub ",
		"./cube3d ./maps/bad/textures_duplicates.cub ",
		"./cube3d ./maps/bad/textures_forbidden.cub ",
		"./cube3d ./maps/bad/textures_invalid.cub ",
		"./cube3d ./maps/bad/textures_missing.cub ",
		"./cube3d ./maps/bad/textures_not_xpm.cub ",
		"./cube3d ./maps/bad/textures_none.cub ",
		"./cube3d ./maps/bad/wall_hole_north.cub ",
		"./cube3d ./maps/bad/wall_hole_east.cub ",
		"./cube3d ./maps/bad/wall_none.cub ",
		"./cube3d ./maps/bad/wall_hole_west.cub ",
		"./cube3d ./maps/bad/wall_hole_south.cub",
	};

    int numgood = sizeof(good) / sizeof(good[0]);
    int numbad = sizeof(bad) / sizeof(bad[0]);

    int ok = system("make re");
	// printf("********** GOOD MAPS **********\n");
    // while(numgood--) {
    //     printf("Executing command: %s\n", good[i]);
    //     int result = system(good[i]);
	// 	printf("=============================================\n");
	// 	i++;
    // }
	i = 0;
	printf("********** BAD MAPS **********\n");
	while(numbad--) {
		printf("Executing command: %s\n", bad[i]);
		int result = system(bad[i]);
		printf("=============================================\n");
		i++;
	}

    return 0;
}
