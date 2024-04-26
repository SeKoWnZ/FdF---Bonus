#include <fdf.h>

void print_map_status(t_map *map, char *status)
{
	int i = -1;
	printf("Status on: %s\n", status);
	printf("Map Memory: \n%s\n", map->map_memory);
	printf("Map limit X: %f | Map limit Y: %f\n", map->limits.axis[X], map->limits.axis[Y]);
	printf("Map total length: %d\n", map->map_length);
	printf("Ground color: %X | Top color: %X\n", map->colors.groundcolor, map->colors.topcolor);
	while (++i < map->map_length)
	{
		printf("%f ", map->points[i].axis[Z]);
		if (i % ((int)map->limits.axis[X]) == 0)
			printf("\n");
	}
	i = -1;
	while (++i < map->map_length)
	{
		printf("%u ", map->points[i].color);
		if (i % (int)map->limits.axis[X] == 0)
			printf("\n");
	}
}