/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 03:08:02 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 11:00:06 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <cmath>
#include <iostream>
#include <ncurses.h>

void			Player::drawBullet( ) {
	_ammo->moveBullet();
	_ammo->drawBullet();
}

void	Player::move( int max_x, int max_y ) {
	if (_x + _dx < max_x - 1 && _x + _dx > 1)
		_x += _dx;
	else
		_dx = -_dx / 2;
	if (_y + _dy < max_y - 1 && _y + _dy > 1)
		_y += _dy;
	else
		_dy = -_dy / 2;
	changeSpeed();
}

void	Player::draw() const {
	mvprintw((int)_y, (int)_x, ">");
}

Player::Player() : AMoving(10, 40, 0, 0, 1), _hp(5) {
	_ammo = new Ammo(50, '-');
}

Player::~Player() {
	delete _ammo;
}

Player::Player(Player const & p) {
	*this = p;
}

Player &		Player::operator=(Player const & p) {
	this->AMoving::operator=(p);
	_hp = p._hp;
	_ammo = p._ammo;
	return (*this);
}

void	Player::changeSpeed( void ) {
	_dy *= 0.999;
	_dx *= 0.999;
}

void	Player::controlMovement( const char & c ) {
	if (c == 'w' || c == 'W')
		_dy = fmax(_dy - 0.02, -0.04);
	else if (c == 's' || c == 'S')
		_dy = fmin(_dy + 0.02, 0.04);
	else if (c == 'd' || c == 'D')
		_dx = fmin(_dx + 0.05, 0.10);
	else if (c == 'a' || c == 'A')
		_dx = fmax(_dx - 0.05, -0.10);
	else if (c == 'm')
		fire();
}

void	Player::fire() {
	for (int i = 0; i < _ammo->getCount(); i++)
		if (_ammo->fire_player(i, *this))
			break ;
}

bool			Player::loseHP( void ) {
	_hp--;
	if (_hp == 0)
		return (true);
	return (false);
}

bool			Player::collision( AMoving & moving ) {
	if ((int)_x == moving.getX() && (int)_y == moving.getY())
	{
		_hp--;
		if (_hp == 0)
		{
			endwin();
			exit(0);
		}
		moving.setVis(0);
		return (true);
	}
	return (false);
}

Ammo *			Player::getAmmo() {
	return (_ammo);
}
