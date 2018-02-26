import os

#frompath = open("traceroutes/v6-8.txt","r")
#topath = open("processedTraceroutes/pv4-0.txt", "w+")

fromdir = "traceroutes/"
todir = "processedTraceroutes/"

def format(ls):
	formatted = ""
	ipls = []
	for i in range(1,len(ls)):
		line = ls[i][4:-4]
		line = line[:line.rfind(' ')-1]
		#print "line: ", line, len(line)
		if len(line) != 0:
			ipls.append(line)
	#print "ipls: ", ipls

	for i in range(len(ipls)-1):
		#print ipls[i] + " -- " + ipls[i+1]
		formatted += "\"" + ipls[i] + "\" -- \"" + ipls[i+1] +"\"\n"

	#print "formatted: ", formatted
	return formatted

#before = frompath.readlines()
#print "before: ", before
#after = format(before)

for dirname, dirnames, filenames in os.walk(fromdir):
	for filename in filenames:
		filePath = os.path.join(dirname, filename)
		fileOpen = open(filePath, "r").readlines()
		fileName = filePath[filePath.rfind('/')+1:]
		formatted = format(fileOpen)
		print "formatted: ", formatted
		writePath = todir + "p" + filename
		writePath = open(writePath, "w+")
		print "writePath: ", writePath
		writePath.write(formatted)



#frompath.close()
#topath.close()

