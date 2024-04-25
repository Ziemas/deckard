#include "apu.h"
#include "event.h"
#include "list.h"
#include "string.h"
#include "types.h"
#include "utils.h"

static LIST_HEAD(event_list);
static LIST_HEAD(free_events);
static struct event event_pool[24];

void
event_remove(struct event *evt)
{
	evt->cb = NULL;
	list_remove(&evt->evt_list);

	/* Theres more her but it makes no sense
	 * given we cleared cb above */

	// Silly, we just removed it
	if (evt->cb != NULL) {
		evt->cb(evt->param);
	}

	list_insert(&free_events, &evt->evt_list);
}

struct event *
event_add(int time, void *cb, uint32 param)
{
	struct event *evt;

	if (list_empty(&free_events)) {
		return NULL;
	}

	evt = list_first_entry(&free_events, struct event, evt_list);
	list_remove(&evt->evt_list);

	evt->cb = cb;
	evt->param = param;
	evt->time = time + 0; // FIXME

	list_insert(&event_list, &evt->evt_list);

	return evt;
}

/* FIXME unfinished */
void
event_init()
{
	memset(event_pool, 0, sizeof(event_pool));

	list_init(&event_list);
	list_init(&free_events);

	for (int i = 0; i < 24; i++) {
		list_insert(&free_events, &event_pool[i].evt_list);
	}
}

void
run()
{
	struct event *evt;

	if (!list_empty(&event_list)) {
		evt = list_first_entry(&event_list, struct event, evt_list);
	}
}

#define UART_THR 0x01000200
#define UART_LSR 0x01000205
#define UART_THR_EMPTY 0x20

void
serial_putc(char c)
{
	write8(UART_THR, c);
	__asm__ volatile("eieio");
	while ((read8(UART_LSR) & UART_THR_EMPTY) == 0) {
		__asm__ volatile("eieio");
	}
}

void
serial_puts(char *s)
{
	while (*s != '\0') {
		serial_putc(*s);
		s++;
	}
}

int
deckard_main()
{
	// printf("\n%s\n","D E C K A R D compiled Apr 12 2006 22:21:21");

	// if (!insane_init_function()) {
	//     return 1;
	// }

	while (1) {
		run();
	}

	return 0;
}
