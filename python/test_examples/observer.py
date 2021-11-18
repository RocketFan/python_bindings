from pybind11_example.observer import ISubscriber, Publisher

class Subscraiber(ISubscriber):
    def update(self, msg):
        print("Update python!!!")

pub = Publisher()
sub = Subscraiber()

pub.attach(sub)
pub.notify("")
pub.notify("")
pub.notify("")
pub.notify("")