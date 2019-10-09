/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AProjectile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 02:41:21 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 09:15:11 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APROJECTILE_HPP
# define APROJECTILE_HPP

#include "AMoving.hpp"
#include <string>

class AMoving;

class AProjectile : public AMoving {
	private:
		char _c;

	public:
		AProjectile( void );
		AProjectile( float x, float y, float dx, float dy, int vis );
		AProjectile( AProjectile const & );
		virtual ~AProjectile( void );
		AProjectile &	operator=( AProjectile const & );
		bool			collision( AMoving & );
		void			setChar( char c);
		void			draw(  ) ;
};

#endif