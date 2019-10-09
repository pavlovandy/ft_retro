/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ammo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:38:11 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 10:40:06 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMMO_HPP
# define AMMO_HPP

# include "AProjectile.hpp"
# include "AMoving.hpp"

class AMoving;

class Ammo {
	private:
		Ammo( Ammo const &);
		Ammo & operator=( Ammo const &);
		Ammo( void );

		int				_count;
		AProjectile *	_bullets;

	public:
		Ammo( int size, char projct_char );
		int		getCount( void ) const ;
		~Ammo();

		bool	fire( int n , AMoving const & , AMoving const & to );
		bool	fire_player( int n , AMoving const & p );
		AProjectile *	getBullet();
		void	drawBullet() ;
		void	moveBullet() ;
};

#endif