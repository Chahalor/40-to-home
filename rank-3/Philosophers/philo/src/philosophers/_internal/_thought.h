/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thougth.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:34:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 13:42:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _THOUGHT_H
# define _THOUGHT_H

# pragma once

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define NB_THOUGHTS 40

# define THOUGHT_0  "about the meaning of forks."
# define THOUGHT_1  "about whether to eat or to wait."
# define THOUGHT_2  "about deadlock prevention."
# define THOUGHT_3  "about the illusion of free will."
# define THOUGHT_4  "about quantum soup theory."
# define THOUGHT_5  "about mutex metaphysics."
# define THOUGHT_6  "about the spoon that does not exist."
# define THOUGHT_7  "about the optimal bite size."
# define THOUGHT_8  "about thread priorities."
# define THOUGHT_9  "about why the others keep eating."
# define THOUGHT_10 "about recursion in life."
# define THOUGHT_11 "about starving slowly with purpose."
# define THOUGHT_12 "about upgrading to philosopher++."
# define THOUGHT_13 "about compiler optimization flags."
# define THOUGHT_14 "about race conditions in the soul."
# define THOUGHT_15 "about which lock to acquire first."
# define THOUGHT_16 "about the void between meals."
# define THOUGHT_17 "about the nature of hunger."
# define THOUGHT_18 "about the paradox of waiting."
# define THOUGHT_19 "about dinner as a simulation."
# define THOUGHT_20 "about whether thinking is a waste of CPU time."
# define THOUGHT_21 "about replacing forks with chopsticks."
# define THOUGHT_22 "about implementing yield()."
# define THOUGHT_23 "about the dining table as a state machine."
# define THOUGHT_24 "about running garbage collection on thoughts."
# define THOUGHT_25 "about the cache coherence of the mind."
# define THOUGHT_26 "about becoming a forkless philosopher."
# define THOUGHT_27 "about joining the main thread."
# define THOUGHT_28 "about achieving enlightenment through starvation."
# define THOUGHT_29 "about writing a book: *Concurrency and Cuisine*."
# define THOUGHT_30 "about forking a new process… for dessert."
# define THOUGHT_31 "about renaming itself to Philosopher GPT."
# define THOUGHT_32 "about switching to a no-lock algorithm."
# define THOUGHT_33 "about why printf causes context switches."
# define THOUGHT_34 "about escaping the monitor of life."
# define THOUGHT_35 "about whether 'thinking' is just busy-waiting."
# define THOUGHT_36 "about semaphores as spiritual guidance."
# define THOUGHT_37 "about Nietzsche's take on thread starvation."
# define THOUGHT_38 "about releasing locks on attachments."
# define THOUGHT_39 "about redefining hunger as a memory leak."

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_thougth_access
{
	get_thougth = 0,
	set_thougth = 1
};

#endif /* !_THOUGHT_H */