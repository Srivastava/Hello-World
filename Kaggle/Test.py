import csv as csv
import numpy as np

csvFile=csv.reader(open('train.csv','rb'))
header=csvFile.next()

data=[]

for row in csvFile:
    data.append(row)
data=np.array(data)

print data
