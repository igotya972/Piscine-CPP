/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:37 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:37 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void annouce(void);
	Zombie *newZombie(std::string name);
	void randomChump(std::string name);
};
