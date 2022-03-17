import time
import matplotlib.pyplot as plt
import numpy as np
time1=time.time()
def matrix():
    Y1=[]
    X=[]
    Y2=[] 
    for i in range (1,40):
        matrix1= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        matrix2= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        matrix3=np.zeros([i,i],dtype=np.int64)
        matrix4=np.dot(matrix1,matrix2)
        Y1.append((time.time()-time1)*1000)
        #print(f"size {i}* {i} --",Y1,"milli secs \n")
        for k in range (i):
            for l in range(i):
                for t in range(i):
                    matrix3[k][l]+=matrix1[k][t]*matrix3[t][l]
    
         
        Y2.append ((time.time()-time1)*1000)
       
        X.append(i)
       # print(f"size {i}* {i} --",Y2,"milli secs \n")
      # print(matrix3,"\n")
    return [Y1 ,Y2,X]


def Strassen_Mul():
    Y3=[]
    X=[]
    for i in range (1,40):
        matrix1= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        matrix2= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        Strassen_algo(matrix1,matrix2)
        Y3.append ((time.time()-time1)*1000)
        X.append(i)
    return [Y3,X]
def Strassen_algo(x,y):
    if x.size == 1 or y.size == 1:
        return x * y

    n = x.shape[0]

    if n % 2 == 1:
        x = np.pad(x, (0, 1), mode='constant')
        y = np.pad(y, (0, 1), mode='constant')

    m = int(np.ceil(n / 2))
    a = x[: m, : m]
    b = x[: m, m:]
    c = x[m:, : m]
    d = x[m:, m:]
    e = y[: m, : m]
    f = y[: m, m:]
    g = y[m:, : m]
    h = y[m:, m:]
    p1 = Strassen_algo(a, f - h)
    p2 = Strassen_algo(a + b, h)
    p3 = Strassen_algo(c + d, e)
    p4 = Strassen_algo(d, g - e)
    p5 = Strassen_algo(a + d, e + h)
    p6 = Strassen_algo(b - d, g + h)
    p7 = Strassen_algo(a - c, e + f)
    result = np.zeros((2 * m, 2 * m), dtype=np.int32)
    result[: m, : m] = p5 + p4 - p2 + p6
    result[: m, m:] = p1 + p2
    result[m:, : m] = p3 + p4
    result[m:, m:] = p1 + p5 - p3 - p7

    return result[: n, : n]

def Strassen_Mul():
    Y3=[]
    X=[]
    for i in range (1,40):
        matrix1= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        matrix2= np.random.randint(1,10,size=(i,i),dtype=np.int64)
        Strassen_algo(matrix1,matrix2)
        Y3.append ((time.time()-time1)*1000)
        X.append(i)
    return [Y3,X]
def Strassen_algo(x,y):
    if x.size == 1 or y.size == 1:
        return x * y

    n = x.shape[0]

    if n % 2 == 1:
        x = np.pad(x, (0, 1), mode='constant')
        y = np.pad(y, (0, 1), mode='constant')

    m = int(np.ceil(n / 2))
    a = x[: m, : m]
    b = x[: m, m:]
    c = x[m:, : m]
    d = x[m:, m:]
    e = y[: m, : m]
    f = y[: m, m:]
    g = y[m:, : m]
    h = y[m:, m:]
    p1 = Strassen_algo(a, f - h)
    p2 = Strassen_algo(a + b, h)
    p3 = Strassen_algo(c + d, e)
    p4 = Strassen_algo(d, g - e)
    p5 = Strassen_algo(a + d, e + h)
    p6 = Strassen_algo(b - d, g + h)
    p7 = Strassen_algo(a - c, e + f)
    result = np.zeros((2 * m, 2 * m), dtype=np.int32)
    result[: m, : m] = p5 + p4 - p2 + p6
    result[: m, m:] = p1 + p2
    result[m:, : m] = p3 + p4
    result[m:, m:] = p1 + p5 - p3 - p7

    return result[: n, : n]


list=matrix()
list1=Strassen_Mul()
#print(list)
plt.plot(list[2],list[1],color='green',label='iterative')    
plt.plot(list[2],list[0],color='orange' ,label='vetorized')
plt.plot(list1[1],list1[0],color='red',label='Strassen')
plt.xlabel(' size ---->')
plt.ylabel(' time----> ')
plt.legend()
plt.show()     
