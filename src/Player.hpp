/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 02:45:07 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:38:17 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "AMoving.hpp"
#include "AProjectile.hpp"
#include "Ammo.hpp"

class Ammo;
class AProjectile;
class AMoving;

class Player : public AMoving {
	private:
		int					_hp;
		Ammo *				_ammo;

		
		Player &		operator=(Player const &);
		void	changeSpeed( void );

	public:
		Player(Player const &);
		Player();
		~Player();
		void			controlMovement( const char & );
		void			fire();
		Ammo *			getAmmo();
		bool			loseHP( void );
		bool			collision( AMoving & );
		void			draw( ) const ;
		void			move( int max_x, int max_y);
		void			drawBullet( ) ;
};

#endif