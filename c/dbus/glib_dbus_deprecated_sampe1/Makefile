COMPILER = -gcc
LDFLAGS+=-ldbus-1
LDFLAGS+=-ldbus-glib-1
LDFLAGS+=-lglib-2.0
CFLAGS+=-I/usr/include/dbus-1.0
CFLAGS+=-I/usr/lib/dbus-1.0/include/
CFLAGS+=-I/usr/lib/glib-2.0/include/
CFLAGS+=-I/usr/include/glib-2.0/

BUILD_LIST+=dbus_ping_send
BUILD_LIST+=dbus_ping_listen
all: $(BUILD_LIST)

$(BUILD_LIST) : %: %.c 
	$(COMPILER) $(CFLAGS) -o $@ $@.c $(LDFLAGS)
clean:
	rm -f *.o dbus_ping_send dbus_ping_listen

