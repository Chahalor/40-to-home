/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:54:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 11:17:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#pragma regions   Headers

#include <iostream>

#pragma endregion Headers
#pragma region    Macros

#define likely(cond)	__builtin_expect(!!(cond), 1)	/* This condition should be true  */
#define unlikely(cond)	__builtin_expect(!!(cond), 0)	/* This condition should be false */


#define PRINT(message)	std::cout << message << std::endl	/* print a message to the standare output*/
#define ERROR(message)	std::cerr << message << std::endl	/* print a message to the standare error*/

#pragma endregion Macros