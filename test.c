// #include <stdio.h>
// #include <stdlib.h>

// int main() {

// 	int i = 0;

//     const char *good[] = {
//     "./Cub3D ./maps/good/cheese_maze.cub",
//     "./Cub3D ./maps/good/creepy.cub",
// 	"./Cub3D ./maps/good/dungeon.cub",
//     "./Cub3D ./maps/good/library.cub",
//     "./Cub3D ./maps/good/matrix.cub",
// 	"./Cub3D ./maps/good/sad_face.cub",
// 	"./Cub3D ./maps/good/square_map.cub",
// 	"./Cub3D ./maps/good/subject_map.cub",
// 	"./Cub3D ./maps/good/test_map.cub",
// 	"./Cub3D ./maps/good/test_pos_bottom.cub",
// 	"./Cub3D ./maps/good/test_pos_left.cub",
// 	"./Cub3D ./maps/good/test_pos_right.cub",
// 	"./Cub3D ./maps/good/test_pos_top.cub",
// 	"./Cub3D ./maps/good/test_textures.cub",
// 	"./Cub3D ./maps/good/test_whitespace.cub",
// 	"./Cub3D ./maps/good/works.cub",
// 	"./Cub3D ./maps/good/forbidden.cub ",
//     };

// 	const char *bad[] = {
// 		"./Cub3D ./maps/bad/color_invalid_rgb.cub",
// 		"./Cub3D ./maps/bad/color_missing_ceiling_rgb.cub ",
// 		"./Cub3D ./maps/bad/color_missing_floor_rgb.cub ",
// 		"./Cub3D ./maps/bad/color_missing.cub ",
// 		"./Cub3D ./maps/bad/color_none.cub ",
// 		"./Cub3D ./maps/good/test_map_hole.cub",
// 		"./Cub3D ./maps/bad/empty.cub ",
// 		"./Cub3D ./maps/bad/file_letter_end.cub ",
// 		"./Cub3D ./maps/bad/filetype_missing ",
// 		"./Cub3D ./maps/bad/filetype_wrong.buc ",
// 		"./Cub3D ./maps/bad/map_first.cub ",
// 		"./Cub3D ./maps/bad/map_middle.cub ",
// 		"./Cub3D ./maps/bad/map_missing.cub ",
// 		"./Cub3D ./maps/bad/map_only.cub ",
// 		"./Cub3D ./maps/bad/map_too_small.cub ",
// 		"./Cub3D ./maps/bad/player_multiple.cub ",
// 		"./Cub3D ./maps/bad/player_none.cub ",
// 		"./Cub3D ./maps/bad/player_on_edge.cub ",
// 		"./Cub3D ./maps/bad/textures_dir.cub ",
// 		"./Cub3D ./maps/bad/textures_duplicates.cub ",
// 		"./Cub3D ./maps/bad/textures_forbidden.cub ",
// 		"./Cub3D ./maps/bad/textures_invalid.cub ",
// 		"./Cub3D ./maps/bad/textures_missing.cub ",
// 		"./Cub3D ./maps/bad/textures_not_xpm.cub ",
// 		"./Cub3D ./maps/bad/textures_none.cub ",
// 		"./Cub3D ./maps/bad/wall_hole_north.cub ",
// 		"./Cub3D ./maps/bad/wall_hole_east.cub ",
// 		"./Cub3D ./maps/bad/wall_none.cub ",
// 		"./Cub3D ./maps/bad/wall_hole_west.cub ",
// 		"./Cub3D ./maps/bad/wall_hole_south.cub",
// 	};

//     int numgood = sizeof(good) / sizeof(good[0]);
//     int numbad = sizeof(bad) / sizeof(bad[0]);

//     int ok = system("make re");
// 	printf("********** GOOD MAPS **********\n");
//     while(numgood--) {
//         printf("Executing command: %s\n", good[i]);
//         int result = system(good[i]);
// 		printf("=============================================\n");
// 		i++;
//     }

// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");å
// 	printf("++++\n");
// 	printf("++++\n");
// 	printf("++++\n");
	
// 	i = 0;
// 	printf("********** BAD MAPS **********\n");
// 	while(numbad--) {
// 		printf("Executing command: %s\n", bad[i]);
// 		int result = system(bad[i]);
// 		printf("=============================================\n");
// 		i++;
// 	}

//     return 0;
// }

# include <stdio.h>
int main()
{
	int color;

	color = 7 << 16;

	color += 225 << 8;

	color += 232 << 4;

	color += 255;

	printf("%d\n", color);		
}