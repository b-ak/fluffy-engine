import threading
import time

class Mythread(threading.Thread):
  def __init__(self, myId, count, mutex):
    self.myId = myId
    self.count = count
    self.mutex = mutex
    threading.Thread.__init__(self)

  def run(self):
    # run provides thread logic
    for i in range(self.count):
      # time.sleep(1)
      # still sync stdout access
      with self.mutex:
        print('[%s] => %s' % (self.myId, i))
    return "Boom Boom"

stdoutmutex = threading.Lock()
threads = []
# for i in range(2):
#   thread = Mythread(i, 10, stdoutmutex)
#   thread.start()
#   threads.append(thread)

thread = Mythread(1267, 10, stdoutmutex)
thread.start()
# threads.append(thread)


# for thread in threads:
print(thread)
thread.join()

print('Main thread exiting.')