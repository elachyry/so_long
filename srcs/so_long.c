/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melachyr <melachyr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/02 18:04:59 by melachyr		  #+#	#+#			 */
/*   Updated: 2024/01/07 23:56:33 by melachyr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_ghost	ghost;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		close_program();
	if (!init_tests(&ghost, argv[1]))
		return (1);
	count_collectibles(&ghost);
	ghost.wall_size = 48;
	ghost.mlx = mlx_init();
	ghost.win = mlx_new_window(ghost.mlx,
			ghost.map_dimension[0] * ghost.wall_size,
			ghost.map_dimension[1] * ghost.wall_size,
			"Running*ghost");
	variable_init(&ghost);
	set_hooks(&ghost);
	mlx_loop(ghost.mlx);
	free_map(ghost.map, ghost.map_dimension[1]);
	return (0);
}
