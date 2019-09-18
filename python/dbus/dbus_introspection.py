from pydbus import SessionBus
bus = SessionBus()

# Create an object that will proxy for a particular remote object.
remote_object = bus.get(
    "org.freedesktop.DBus", # Bus name
    "/org/freedesktop/DBus" # Object path
)

# Introspection returns an XML document containing information
# about the methods supported by an interface.
print ("Introspection data:\n")
print (remote_object.Introspect()[0])
