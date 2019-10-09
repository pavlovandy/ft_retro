/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy1.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 07:27:21 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/06 08:32:25 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY1_HPP
# define ENEMY1_HPP

#include "AEnemy.hpp"

class AEnemy;

class Enemy1 : public AEnemy 
{
private:
public:
	Enemy1();
	~Enemy1();
};

Enemy1::Enemy1() : AEnemy("Enemy1", 2, 11)  {
}

Enemy1::~Enemy1() {
}


#endif