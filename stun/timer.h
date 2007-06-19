/*
 * This file is part of the Nice GLib ICE library.
 *
 * (C) 2007 Nokia Corporation. All rights reserved.
 *  Contact: Rémi Denis-Courmont
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Nice GLib ICE library.
 *
 * The Initial Developers of the Original Code are Collabora Ltd and Nokia
 * Corporation. All Rights Reserved.
 *
 * Contributors:
 *   Rémi Denis-Courmont, Nokia
 *
 * Alternatively, the contents of this file may be used under the terms of the
 * the GNU Lesser General Public License Version 2.1 (the "LGPL"), in which
 * case the provisions of LGPL are applicable instead of those above. If you
 * wish to allow use of your version of this file only under the terms of the
 * LGPL and not to allow others to use your version of this file under the
 * MPL, indicate your decision by deleting the provisions above and replace
 * them with the notice and other provisions required by the LGPL. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under either the MPL or the LGPL.
 */

#ifndef STUN_TIMER_H
# define STUN_TIMER_H 1

/**
 * @file timer.h
 * @brief STUN retransmission timer
 */

# include <sys/types.h>
# include <time.h>

typedef struct stun_timer_s
{
	struct timespec deadline;
	unsigned delay;
} stun_timer_t;


# ifdef __cplusplus
extern "C" {
# endif

/**
 * Starts a STUN transaction retransmission timer.
 * @param timer structure for internal timer state
 */
void stun_timer_start (stun_timer_t *timer);
void stun_timer_start_reliable (stun_timer_t *timer);

/**
 * Updates a STUN transaction retransmission timer.
 * @param timer internal timer state
 * @return -1 if the transaction timed out,
 * 0 if the transaction should be retransmitted,
 * otherwise milliseconds left until next time out or retransmit.
 */
int stun_timer_refresh (stun_timer_t *timer);
unsigned stun_timer_remainder (const stun_timer_t *timer);

# ifdef __cplusplus
}
# endif

#endif /* !STUN_TIMER_H */
