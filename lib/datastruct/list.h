/*
 * Copyright (C) 2001 Sistina Software
 *
 * This file is released under the LGPL.
 */

#ifndef _LVM_LIST_H
#define _LVM_LIST_H

#include <assert.h>

struct list {
	struct list *n, *p;
};

static inline void list_init(struct list *head) {
	head->n = head->p = head;
}

static inline void list_add(struct list *head, struct list *elem) {
	assert(head->n);

	elem->n = head;
	elem->p = head->p;

	head->p->n = elem;
	head->p = elem;
}

static inline void list_add_h(struct list *head, struct list *elem) {
	assert(head->n);

	elem->n = head->n;
	elem->p = head;

	head->n->p = elem;
	head->n = elem;
}

static inline void list_del(struct list *elem) {
	elem->n->p = elem->p;
	elem->p->n = elem->n;
}

static inline int list_empty(struct list *head) {
	return head->n == head;
}

#define list_iterate(v, head) \
    for (v = (head)->n; v != head; v = v->n)

#define list_item(v, t) \
    ((t *)((char *)(v) - (unsigned int) &((t *) 0)->list))

#endif
