
"""
https://www.cnblogs.com/jessonluo/p/4717140.html
"""


class Desc:
    def __get__(self, ins, cls):
        print('self in Desc: %s ' % self )
        print(self, ins, cls)


class Test:
    x = Desc()

    def prt(self):
        print('self in Test: %s' % self)
        class_name = self.__class__.__name__
        print("here", class_name)


t = Test()
t.prt()
print(t.x)
