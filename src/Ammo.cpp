/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ammo.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:58:42 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:40:24 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ammo.hpp"
#include "AMoving.hpp"
#include <iostream>
#include <cmath>

Ammo::Ammo( void ) : _count(0), _bullets(0) {
}

Ammo::Ammo( Ammo const & a) {
	(void)a;
}

Ammo & Ammo::operator=( Ammo const & a) {
	(void)a;
	return (*this);
}

Ammo::Ammo( int size, char projct_char ) {
	_bullets = new AProjectile[size];
	_count = size;
	for (int i = 0; i < size; i++)
	{
		_bullets[i].setChar(projct_char);
		_bullets[i].setVis(false);
	}
}

int		Ammo::getCount( void ) const  {
	return (_count);
}

Ammo::~Ammo() {
	if (_bullets)
		delete[] _bullets;
}

bool	Ammo::fire( int n , AMoving const & from, AMoving const & to) {
	if (n < _count && n > -1)
		if (!_bullets[n].getVis())
		{
			double	dir_x = (to.getX() - from.getX());
			double	dir_y = (to.getY() - from.getY());
			double	mod = ENEMY_PROJECTILES_SPEED / sqrt(dir_x * dir_x + dir_y * dir_y);
			dir_x *= mod;
			dir_y *= mod;
			_bullets[n].setAll(from.getX(), from.getY(), dir_x, dir_y, true);
			return (true);
		}
	return (false);
}

bool	Ammo::fire_player( int n , AMoving const & p ) {
	if (n < _count && n > -1)
		if (!_bullets[n].getVis())
		{
			_bullets[n].setAll(p.getX(), p.getY(), PLAYER_PROJECTILES_SPEED, 0, true);
			return (true);
		}
	return (false);
}

void	Ammo::drawBullet() {
	for (int i = 0; i < _count; i++)
		_bullets[i].draw();
}

void	Ammo::moveBullet() {
	for (int i = 0; i < _count; i++)
		_bullets[i].move();
}

AProjectile *	Ammo::getBullet() {
	return (_bullets);
}