/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __LINUX_SWAP_CGROUP_H
#define __LINUX_SWAP_CGROUP_H

#include <linux/swap.h>

#if defined(CONFIG_MEMCG) && defined(CONFIG_SWAP)

extern void swap_cgroup_record(struct folio *folio, unsigned short id, swp_entry_t ent);
extern unsigned short swap_cgroup_clear(swp_entry_t ent, unsigned int nr_ents);
extern unsigned short lookup_swap_cgroup_id(swp_entry_t ent);
extern int swap_cgroup_swapon(int type, unsigned long max_pages);
extern void swap_cgroup_swapoff(int type);

#else

static inline
void swap_cgroup_record(struct folio *folio, unsigned short id, swp_entry_t ent)
{
}

static inline
unsigned short swap_cgroup_clear(swp_entry_t ent, unsigned int nr_ents)
{
	return 0;
}

static inline
unsigned short lookup_swap_cgroup_id(swp_entry_t ent)
{
	return 0;
}

static inline int
swap_cgroup_swapon(int type, unsigned long max_pages)
{
	return 0;
}

static inline void swap_cgroup_swapoff(int type)
{
	return;
}

#endif

#endif /* __LINUX_SWAP_CGROUP_H */
