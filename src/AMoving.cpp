/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMoving.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:17:54 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:08:35 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMoving.hpp"
#include "ctime"
#include <iostream>

void	AMoving::move() {
	_x += _dx;
	_y += _dy;
	if (_x > WW || _x < 0)
		_isVis = 0;
	if (_y > WH || _y < 0)
		_isVis = 0;
}

void	AMoving::draw() const  {
	mvprintw((int)_y, (int)_x, "&_c");
}

int		AMoving::getX() const  {
	return (_x);
}

int		AMoving::getY() const  {
	return (_y);
}

void	AMoving::setX( float x ) {
	_x = x;
}

void	AMoving::setY( float y ) {
	_y = y;
}

void	AMoving::setVis(bool b) {
	_isVis = b;
}

bool	AMoving::getVis() const {
	return (_isVis);
}

void	AMoving::setAll(float x, float y, float dx, float dy, bool v) {
	_x = x;
	_y = y;
	_dx = dx;
	_dy = dy;
	_isVis = v;
}

AMoving::~AMoving() {
}

AMoving::AMoving( float x, float y, float dx, float dy, int vis ) : _x(x), _y(y), _dx(dx), _dy(dy), _isVis(vis) {
}

AMoving::AMoving( AMoving const & m) {
	*this = m;
}

AMoving::AMoving() : _x(0), _y(0), _dx(0), _dy(0), _isVis(0) {
}

AMoving &	AMoving::operator=(AMoving const & c) {
	_x = c._x; 
	_y = c._y;
	_dx = c._dx;
	_dy = c._dy;
	_isVis = c._isVis;
	return (*this);
}
