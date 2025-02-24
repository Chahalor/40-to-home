/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 09:34:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# pragma once

/* -----| Header |----- */
// Glibc
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <errno.h>

// Local
# include "libft.h"

/* -----| Define |----- */

# ifndef BONUS
#  define BONUS 0
# endif

# define EOT 4

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;

/* -----| Enum |----- */

typedef enum e_bool
{
	false,
	true
}	t_bool;

/**
 * @brief literaly an enum of errno.h error code
 */
typedef enum e_error
{
	eperm	= 1,		// Operation not permitted
	enoent,				// No such file or directory
	esrch,				// No such process
	eintr,				// Interrupted system call
	eio,				// Input/output error
	enxio,				// No such device or address
	e2big,				// Argument list too long
	enoexec,			// Exec format error
	ebadf,				// Bad file descriptor
	echild,				// No child processes
	eagain,				// Resource temporarily unavailable
	enomen,				// Cannot allocate memory
	eacces,				// Permission denied
	efault,				// Bad address
	enotblk,			// Block device required
	ebusy,				// Device or resource busy
	eexist,				// File exists
	exdev,				// Invalid cross-device link
	enodev,				// No such device
	enotdir,			// Not a directory
	eisdir,				// Is a directory
	einval,				// Invalid argument
	enfile,				// Too many open files in system
	emfile,				// Too many open files
	enotty,				// Inappropriate ioctl for device
	etxtbsy,			// Text file busy
	efbig,				// File too large
	enospc,				// No space left on device
	espipe,				// Illegal seek
	erofs,				// Read-only file system
	emlink,				// Too many links
	epipe,				// Broken pipe
	edom,				// Numerical argument out of domain
	erange,				// Numerical result out of range
	edeadlk,			// Resource deadlock avoided
	enametoolong,		// File name too long
	enolck,				// No locks available
	enosys,				// Function not implemented
	enotempty,			// Directory not empty
	eloop,				// Too many levels of symbolic links
	ewouldblock	= eagain,	// Resource temporarily unavailable
	enomsg,				// No message of desired type
	eidrm,				// Identifier removed
	echrng,				// Channel number out of range
	el2nsync,			// Level 2 not synchronized
	el3hlt,				// Level 3 halted
	el3rst,				// Level 3 reset
	elnrng,				// Link number out of range
	eunatch,			// Protocol driver not attached
	enocsi,				// No CSI structure available
	el2hlt,				// Level 2 halted
	ebade,				// Invalid exchange
	ebadr,				// Invalid request descriptor
	exfull,				// Exchange full
	enoano,				// No anode
	ebadrqc,			// Invalid request code
	ebadslt,			// Invalid slot
	edeadlock	= edeadlk,	// Resource deadlock avoided
	ebfont,				// Bad font file format
	enostr,				// Device not a stream
	enodata,			// No data available
	etime,				// Timer expired
	enosr,				// Out of streams resources
	enonet,				// Machine is not on the network
	enopkg,				// Package not installed
	eremote,			// Object is remote
	enolink,			// Link has been severed
	eadv,				// Advertise error
	esrmnt,				// Srmount error
	ecomm,				// Communication error on send
	eproto,				// Protocol error
	emultihop,			// Multihop attempted
	edotdot,			// RFS specific error
	ebadmsg,			// Bad message
	eoverflow,			// Value too large for defined data type
	enotuniq,			// Name not unique on network
	ebadfd,				// File descriptor in bad state
	eremchg,			// Remote address changed
	elibacc,			// Can not access a needed shared library
	elibbad,			// Accessing at type not supported
	eopnotsupp	= 95,	// Operation not supported
	epfnosupport,		// Protocol family not supported
	eafnosupport,		// Address family not supported by protocol
	eaddrinuse,			// Address already in use
	eaddrnotavail,		// Cannot assign requested address
	enetworkdown,		// Network is down
	enetworkunreach,	// Network is unreachable
	enetworkreset,		// Network dropped connection on reset
	econnaborted,		// Software caused connection abort
	econnreset,			// Connection reset by peer
	enobufs,			// No buffer space available
	eisconn,			// Transport endpoint is already connected
	enotconn,			// Transport endpoint is not connected
	eshutdown,			// Cannot send after transport endpoint shutdown
	etoomanyrefs,		// Too many references: cannot splice
	etimedout,			// Connection timed out
	econnrefused,		// Connection refused
	ehostdown,			// Host is down
	ehostunreach,		// No route to host
	ealready,			// Operation already in progress
	einprogress,		// Operation now in progress
	estale,				// Stale file handle
	euclean,			// Structure needs cleaning
	enotnam,			// Not a XENIX named type file
	enavail,			// No XENIX semaphores available
	eisnam,				// Is a named type file
	eremoteio,			// Remote I/O error
	edquot,				// Disk quota exceeded
	enomedium,			// No medium found
	emediumtype,		// Wrong medium type
	ecanceled,			// Operation canceled
	enokey,				// Required key not available
	ekeyexpired,		// Key has expired
	ekeyrevoked,		// Key has been revoked
	ekeyrejected,		// Key was rejected by service
	eownerdead,			// Owner died
	enotrecoverable,	// State not recoverable
	erfkill,			// Operation not possible due to RF-kill
	ehwpoison,			// Memory page has hardware error
	enotsup	= eopnotsupp,	// Operation not supported
	elibscn	= 81,		// .lib section in a.out corrupted
	elibmax,			// Attempting to link in too many shared libraries
	elibexec,			// Cannot exec a shared library directly
	eilseq,				// Invalid or incomplete multibyte or wide character
	erestart,			// Interrupted system call should be restarted
	estrpipe,			// Streams pipe error
	eusers,				// Too many users
	enotsock,			// Socket operation on non-socket
	edestaddrreq,		// Destination address required
	emsgsize,			// Message too long
	eprototype,			// Protocol wrong type for socket
	enoprotoopt,		// Protocol not available
	eprotonosupport		// Protocol not supported
}	t_error;

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

__attribute__((hot)) static inline int	translate(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("0");
		return (0);
	}
	else
	{
		ft_printf("1");
		return (1);
	}
}

__attribute__((cold)) static inline int bit_to_sig(int bit)
{
	if (bit)
		return (SIGUSR1);
	else
		return (SIGUSR2);
}

__attribute__((cold, unused, noreturn)) static inline void	exiting(
	const t_error code, const char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (code)
		errno = code;
	exit(code);
}

#endif	/* MINITALK_H */