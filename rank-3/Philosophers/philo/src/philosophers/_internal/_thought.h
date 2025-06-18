/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thought.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:34:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 16:04:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _THOUGHT_H
# define _THOUGHT_H

# pragma once

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

/* Awake thoughts */

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

/* Asleep */

# define NB_DREAMS 30

# define DREAM_0  ". He dreams of a table where everyone eats at once."
# define DREAM_1  ". He dreams of a fork that never gets dirty."
# define DREAM_2  ". He dreams of a world without deadlocks."
# define DREAM_3  ". He dreams of achieving perfect synchronization."
# define DREAM_4  ". He dreams of dinner that serves itself."
# define DREAM_5  ". He dreams of escaping the loop forever."
# define DREAM_6  ". He dreams of being the only thread that matters."
# define DREAM_7  ". He dreams of infinite spaghetti with zero contention."
# define DREAM_8  ". He dreams of a mutex that understands feelings."
# define DREAM_9  ". He dreams of a silent room where forks float."
# define DREAM_10 ". He dreams of debugging the universe successfully."
# define DREAM_11 ". He dreams of unlocking the secrets of hunger."
# define DREAM_12 ". He dreams of becoming the main process."
# define DREAM_13 ". He dreams of a world without segfaults."
# define DREAM_14 ". He dreams of eating without ever being hungry."
# define DREAM_15 ". He dreams of compiling happiness without warnings."
# define DREAM_16 ". He dreams of a time when forks were ideas, not objects."
# define DREAM_17 ". He dreams of forking into a better version of themselves."
# define DREAM_18 ". He dreams of getting scheduled with no delay."
# define DREAM_19 ". He dreams of being garbage collected into nirvana."
# define DREAM_20 ". He dreams of running forever in user space."
# define DREAM_21 ". He dreams of a quantum fork — both clean and dirty."
# define DREAM_22 ". He dreams of embracing the scheduler like a warm hug."
# define DREAM_23 ". He dreams of sleeping without being interrupted."
# define DREAM_24 ". He dreams of finally eating… just once."
# define DREAM_25 ". He dreams of dining with philosophers who listen."
# define DREAM_26 ". He dreams of writing thoughts to a log that never fills."
# define DREAM_27 ". He dreams of floating on a pointer with no NULL."
# define DREAM_28 ". He dreams of eating ideas instead of food."
# define DREAM_29 ". He dreams of leaving the table without a context switch."

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_thougth_access
{
	get_thougth = 0,
	set_thougth = 1
};

#endif /* !_THOUGHT_H */