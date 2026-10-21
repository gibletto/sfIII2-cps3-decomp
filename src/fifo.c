/*
 * fifo.c  Word FIFO queue
 *
 * fifo_init sets up a ring buffer of 32-bit entries (size, buffer top, read pointer, count,
 * write pointer) and fifo_get takes the next entry, wrapping the read pointer at the end of the
 * buffer and returning 0 when the queue is empty.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "fifo.h"
/* provisional name */
void fifo_init(fifo, buf, size)
u32 *fifo;
u32 buf;
u32 size;
{
    fifo[0] = size;
    fifo[1] = buf;      /* buffer top */
    fifo[2] = buf;      /* read pointer */
    fifo[3] = 0;        /* entries queued */
    fifo[4] = buf;      /* write pointer */
}



/* provisional name */
s32 fifo_put(FIFO32* q, u32 dat) {
    u32* wr;
    u32* next = q->wr + 1;
    if ((u32)next >= (u32)q->base + q->size) {
        next = q->base;
    }
    if (next != q->rd) {
        wr = q->wr;
        *wr = dat;
        q->wr = next;
        q->count++;
        return 0;
    }
    return -1;
}



/* provisional name */
s32 fifo_get(FIFO32* q) {
    u32* rd;
    u32 dat;
    if (q->wr != q->rd) {
        rd = q->rd;
        dat = *rd;
        q->rd = ++rd;
        q->count--;
        if ((u32)rd >= (u32)q->base + q->size) {
            q->rd = q->base;
        }
        return dat;
    }
    return 0;
}
