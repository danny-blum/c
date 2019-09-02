typedef struct {
  void *buf;
  int len;
  int head;
  int maxLen;
} cbuf_t;

bool init (cbuf_t *cbuf, int size) {
  if (!cbuf) return false;
  cbuf->buf = malloc(size);
  if (!cbuf->buf) return false;
  cbuf->len = 0;
  cbuf->head = 0;
  cbuf->maxLen = size;

  return true;
}

int write(cbuf_t *cbuf, void *dst, int wlen) {
  wlen = min(wlen, cbuf->maxLen - cbuf->Len);
  int tail = (cbuf->head + cbuf->len) % cbuf->maxLen;
  int cplen = min(cbuf->maxLen - tail, wlen);
  memcpy(&cbuf->buf[tail], buf, cplen);
  cplen = wlen - cplen;
  buf += cplen;
  memcpy(&cbuf->buf, buf, cplen);
  
  cbuf->len += wlen;
  
  return rlen;
}

int read(cbuf_t *cbuf, void *dst, int rlen) {
  rlen = min(rlen, cbuf->len);
  int cplen = min(cbuf->maxLen - cbuf->head, rlen);
  memcpy(buf, &cbuf->buf[cbuf->head], cplen);
  cplen = rlen - cplen;
  buf += cplen;
  memcpy(buf, &cbuf->buf, cplen);
  
  cbuf->len -= rlen;
  cbuf->head = (cbuf->head + rlen) % cbuf->maxLen;
  
  return rlen;
}
