P = vlcsmpl
OBJS = main.o samptbl.o \
	korg_syro_volcasample.o korg_syro_func.o korg_syro_comp.o
CFLAGS = -g -Wall -Wstrict-prototypes
LDLIBS = -lb

$(P): $(OBJS)
	$(CC) -o $(P) $(LDFLAGS) $(OBJS) $(LDLIBS)

clean:
	rm -f *o; rm -f $(P)
