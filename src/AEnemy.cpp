/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:30:05 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:48:57 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"
#include "AProjectile.hpp"
#include <ncurses.h>

AEnemy::AEnemy() :  _hp(0), _type(0), _ammo(0) {
}

AEnemy::~AEnemy() {
	if (_ammo)
		delete _ammo;
}

AEnemy::AEnemy( std::string type, int hp, int ammo_size ) : AMoving(0, 0, 0 ,0, 0), _hp(hp), _type(type) {
	_ammo = new Ammo(ammo_size, '*');
}

AEnemy::AEnemy( AEnemy const & e) {
	*this = e;
}

AEnemy &	AEnemy::operator=( AEnemy const & e) {
	this->AMoving::operator=(e);
	_type = e._type;
	_hp = e._hp;
	_ammo = new Ammo(e._ammo->getCount(), '*');
	return (*this);
}

void	AEnemy::fire( Player const & p) {
	for (int i = 0; i < _ammo->getCount(); i++){
		if (_ammo->fire(i, *this, p))
			break ;
	}
		
}

void			AEnemy::getDmg( void ) {
	_hp--;
	if (_hp == 0)
		_isVis = 0;
}

bool			AEnemy::collision( AMoving & m) {
	if ((int)_x == m.getX() && (int)_y == m.getY())
	{
		_hp--;
		if (_hp == 0)
			_isVis = 0;
		m.setVis(0);
		return (true);
	}
	return (false);
}

void			AEnemy::draw( ) {
	mvprintw((int)_y, (int)_x, "()");
}

void			AEnemy::drawBullet( ) {
	_ammo->moveBullet();
	_ammo->drawBullet();
}

Ammo *			AEnemy::getAmmo() {
	return (this->_ammo);
}
