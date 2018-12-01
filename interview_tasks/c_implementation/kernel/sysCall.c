// First of all need to download kernel sources and add sys call (334	common	test_sys_call	sys_test)
// under arch/x86/entry/syscalls/syscall_64.tbl
// 
// Then add function to nest file:
SYSCALL_DEFINE1(test_sys_call, char *, msg)
{
	char buf[256];
	long copied = strncpy_from_user(buf, msg, sizeof(buf));
	if (copied < 0 || copied == sizeof(buf))
		return -EFAULT;
	printk(KERN_INFO "test_sys_call syscall called with \"%s\"\n", buf);
	return 0;
}
