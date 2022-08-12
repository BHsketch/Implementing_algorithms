def intersection(a, b):
    c=a.intersection(b)
    return c

def union(a, b):
    c=a.union(b)
    return c

a=[1, 2, 3]
b=[]
b.append(a.pop(0))
print(b)
print(a)
d=[]

for x in a:
    print("before: ", x)
    x=2*x
    print("now: ", x)
    d.append(x)

print("a after multiplying all elements by 2: ", d)

g=[5, 1, 3, 0, 44, 21]
g.sort(reverse=True)
print(g)

set1={'s', 'e', 't', 's'}
set2={3, 4, 1, 0, 'e'}
set3=set1.intersection(set2)
print(set3)
