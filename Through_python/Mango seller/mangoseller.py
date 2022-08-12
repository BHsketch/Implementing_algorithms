from collections import deque

graph={}
graph["You"]=["Alice", "Bob", "Claire"]
graph["Bob"]=["Anuj", "Peggy"]
graph["Alice"]=["Peggy"]
graph["Claire"]=["Thom", "Jonny"]
graph["Peggy"]=[]
graph["Anuj"]=[]
graph["Thom"]=[]
graph["Jonny"]=[]

personqueue = deque()

def mangoseller(name):
    for x in graph[name]:
        personqueue.append(x)
    for x in personqueue:
        temp=personqueue.popleft()
        if(temp[-1]=='m'):
            print(temp, "is a mango seller")
            return 0
        elif(temp[-1]!='m'):
            mangoseller(temp)
            return 0
    
mangoseller("You")

