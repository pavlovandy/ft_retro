/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AProjectile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:48:45 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 09:59:35 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AProjectile.hpp"

AProjectile::AProjectile( float x, float y, float dx, float dy, int vis ) : AMoving(x, y, dx, dy, vis) {
	_c = 0;
}

void	AProjectile::draw( ) {
	mvprintw((int)_y, (int)_x, &_c);
}

AProjectile::AProjectile( void ) : AMoving(0, 0, 0, 0, 0) {
	_c = 0;
}

AProjectile::AProjectile( AProjectile const & p) {
	*this = p;
}

AProjectile::~AProjectile( void ) {
}

AProjectile &	AProjectile::operator=( AProjectile const & p) {
	this->AMoving::operator=(p);
	_c = p._c;
	return (*this);
}


bool	AProjectile::collision( AMoving & m) {
	if ((int)_x == m.getX() && (int)_y == m.getY())
		return (true);
	return (false);
}

void	AProjectile::setChar( char c) {
	_c = c;
}