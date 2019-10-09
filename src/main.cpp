/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 00:07:58 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:59:53 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include "Player.hpp"
#include "AEnemy.hpp"
#include "Ammo.hpp"
#include "AProjectile.hpp"
#include "AMoving.hpp"
#include "Enemy1.hpp"
#include <unistd.h>

int		main()
{
	Player player;
	
	AEnemy* enemies = new Enemy1[100];
	
	char	_input;
	int		_quit = 1;
	int		max_x;
	int		max_y;

	initscr();
	noecho();
	cbreak();
	curs_set(false);
	nodelay(stdscr, TRUE);
	mousemask(BUTTON1_PRESSED | BUTTON2_PRESSED, NULL);
	keypad(stdscr, true);
	getmaxyx(stdscr, max_y, max_x);
	if (max_y < 20 && max_x < 80)
	{
		endwin();
		exit(1);
	}
	for (int i = 0; i < 100; i++)
		enemies[i].setAll(max_x - rand() % 5 - 2, rand() % max_y , -0.001 * (rand() % 5), 0, 1);
	while (_quit)
	{
		clear();
		usleep(100);
		_input = getch();
		if (_input == 'q' || _input == 'Q')
			_quit = 0;
		player.controlMovement( _input );
		player.move(max_x, max_y);
		
		player.draw();
		player.drawBullet();
		AProjectile* player_bullet = player.getAmmo()->getBullet();
		for (int i = 0; i < 100; i++)
		{
			if (enemies[i].getVis() == 0)
				continue ;
			if (rand() % 50000 < 1)
				enemies[i].fire(player);
			enemies[i].move();
			player.collision(enemies[i]);
			for (int j = 0; j < enemies[i].getAmmo()->getCount(); j++)
			{
				AProjectile & enem_bullet = enemies[i].getAmmo()->getBullet()[j];
				if (enem_bullet.getVis() == 0)
					continue ;
				player.collision(enem_bullet);
			}
			for (int j = 0; j < player.getAmmo()->getCount(); j++)
				enemies[i].collision(player_bullet[j]);
			enemies[i].draw();
			enemies[i].drawBullet();
		}
		refresh();
	}
	endwin();
	exit(0);
}
