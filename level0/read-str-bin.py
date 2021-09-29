with open("flasher.bin", 'rb') as f:
    f.seek(96)
    bytes = f.read(23)
    print(bytes)
    print(bytes.decode('utf-8'))
    #s = struct.unpack('bbbb', bytes)
    #print(s)

