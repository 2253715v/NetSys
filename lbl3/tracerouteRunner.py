
#traceroute -6 -q 1 -n

IP_DICT = {"ipv4":[], "ipv6":[]}
v4s = []
v6s = []
def readDnsLookupFile():

	dnsLookupFile = open("ipList.txt", "r")
	lines = dnsLookupFile.readlines()

	for line in lines:
		lineSplit = line.split(" ")
		#print "line: ", lineSplit
		#print "line[1]: ", lineSplit[1]
		
		if lineSplit[1] == "IPv4":
			IP_DICT["ipv4"].append(lineSplit[2])
		else:
			IP_DICT["ipv6"].append(lineSplit[2])

	#print "IP_DICT: ", IP_DICT
	dnsLookupFile.close()


readDnsLookupFile()

print "4: ", IP_DICT["ipv4"]
print "6: ", IP_DICT["ipv6"]

cmdFile = open("commands.txt", "a")

for i in range( len(IP_DICT["ipv4"]) ):
	add = str(IP_DICT["ipv4"][i][:-1])
	cmd = "traceroute -4 -q 1 -n " + add + " > v4-" + str(i) + ".txt" + '\n'

	cmdFile.write(cmd)

for i in range( len(IP_DICT["ipv6"]) ):
	add = str(IP_DICT["ipv6"][i][:-1])
	cmd = "traceroute -6 -q 1 -n " + add + " > v6-" + str(i) + ".txt" + '\n'

	cmdFile.write(cmd)


cmdFile.close()
	

print "done"

