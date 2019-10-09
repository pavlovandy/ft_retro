/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 02:30:47 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:48:35 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENEMY_HPP
# define AENEMY_HPP

#include "AMoving.hpp"
#include "Player.hpp"
#include "AProjectile.hpp"
#include <string>
#include "Ammo.hpp"

class Ammo;
class AProjectile;
class AMoving;
class Player;

class AEnemy : virtual public AMoving {
	private:
		AEnemy();
		int				_hp;
		std::string		_type;
		Ammo *			_ammo;
			
	public:
		virtual ~AEnemy();
		AEnemy( std::string type, int hp, int ammo_size );
		AEnemy( AEnemy const & );
		AEnemy &	operator=( AEnemy const & );

		void			fire( Player const & );
		void			getDmg( void );
		bool			collision( AMoving & );
		void			draw( );
		void			drawBullet() ;
		Ammo *			getAmmo();
};

#endif