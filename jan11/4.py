# the program runs synchronously, not parallely

import shlex, subprocess

i=0
while 1:
	command_line = raw_input()
	args = shlex.split(command_line)
	i = i+1
	print args
	print i
	p = subprocess.Popen(args)
	
