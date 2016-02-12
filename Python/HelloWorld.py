from sys import argv

script, from_file, to_file = argv

print "Copying from files %s to %s" %(from_file, to_file)

infile=open(from_file)

indata=infile.read()

outFile=open(to_file,'w')
outFile.write(indata)

outFile.close()
infile.close();
