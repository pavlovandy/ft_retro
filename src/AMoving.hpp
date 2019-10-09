/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMoving.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 02:18:50 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:23:11 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOVING_HPP
# define AMOVING_HPP

#include <ncurses.h>
#define		WW 700
#define		WH 200
#define		PLAYER_PROJECTILES_SPEED 0.05
#define		ENEMY_PROJECTILES_SPEED 0.05

class	AMoving {
	protected:
		float	_x;
		float	_y;
		float	_dx;
		float	_dy;
		bool	_isVis;
		
	public:
		virtual ~AMoving();
		AMoving();
		AMoving( float x, float y, float dx, float dy, int vis );
		AMoving( AMoving const & );
		AMoving &	operator=(AMoving const &);

		void	move();
		void	draw() const ;
		int		getX() const ;
		int		getY() const ;
		void	setX( float );
		void	setY( float );
		bool	getVis() const ;
		void	setVis(bool b);
		void	setAll(float, float, float, float, bool);
		virtual bool	collision( AMoving & ) = 0;
};

#endif